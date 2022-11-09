#include <matrix.h>

#include <math.h>

void normalize(float_t v[3])
{
    float_t r;

    r = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    if (r == 0.0) return;

    v[0] /= r;
    v[1] /= r;
    v[2] /= r;
}

// result = v1 cross v2
void cross(float_t v1[3], float_t v2[3], float_t result[3])
{
    result[0] = v1[1]*v2[2] - v1[2]*v2[1];
    result[1] = v1[2]*v2[0] - v1[0]*v2[2];
    result[2] = v1[0]*v2[1] - v1[1]*v2[0];
}


// a*b -> c
void matrix_mul_matrix(float_t *a, float_t *b, float_t *c)
{
#if defined(__ARM_NEON__) && !defined(__APPLE__)
    float_t* a1 = a+8;
    float_t* b1 = b+8;
    float_t* c1 = c+8;
    asm volatile (
    "vld1.32  {d16-d19}, [%2]       \n"
    "vld1.32  {d20-d23}, [%3]       \n"
    "vld1.32  {d0-d3}, [%4]         \n"
    "vld1.32  {d4-d7}, [%5]         \n"
    "vmul.f32 q12, q8, d0[0]        \n"
    "vmul.f32 q13, q8, d2[0]        \n"
    "vmul.f32 q14, q8, d4[0]        \n"
    "vmul.f32 q15, q8, d6[0]        \n"
    "vmla.f32 q12, q9, d0[1]        \n"
    "vmla.f32 q13, q9, d2[1]        \n"
    "vmla.f32 q14, q9, d4[1]        \n"
    "vmla.f32 q15, q9, d6[1]        \n"
    "vmla.f32 q12, q10, d1[0]       \n"
    "vmla.f32 q13, q10, d3[0]       \n"
    "vmla.f32 q14, q10, d5[0]       \n"
    "vmla.f32 q15, q10, d7[0]       \n"
    "vmla.f32 q12, q11, d1[1]       \n"
    "vmla.f32 q13, q11, d3[1]       \n"
    "vmla.f32 q14, q11, d5[1]       \n"
    "vmla.f32 q15, q11, d7[1]       \n"
    "vst1.32  {d24-d27}, [%0]       \n"
    "vst1.32  {d28-d31}, [%1]       \n"

    ::"r"(c), "r"(c1), "r"(a), "r"(a1), "r"(b), "r"(b1)
    : "q0", "q1", "q2", "q3", 
      "q8", "q9", "q10", "q11", "q12", "q13", "q14", "q15", "memory");
#else
	float_t a00 = a[ 0], a01 = a[ 1], a02 = a[ 2], a03 = a[ 3],
            a10 = a[ 4], a11 = a[ 5], a12 = a[ 6], a13 = a[ 7],
            a20 = a[ 8], a21 = a[ 9], a22 = a[10], a23 = a[11],
            a30 = a[12], a31 = a[13], a32 = a[14], a33 = a[15];

    float_t
	b0 = b[ 0], b1 = b[ 1], b2 = b[ 2], b3 = b[ 3];
    c[ 0] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    c[ 1] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    c[ 2] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    c[ 3] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

    b0 = b[ 4]; b1 = b[ 5]; b2 = b[ 6]; b3 = b[ 7];
    c[ 4] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    c[ 5] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    c[ 6] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    c[ 7] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

    b0 = b[ 8]; b1 = b[ 9]; b2 = b[10]; b3 = b[11];
    c[ 8] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    c[ 9] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    c[10] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    c[11] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

    b0 = b[12]; b1 = b[13]; b2 = b[14]; b3 = b[15];
    c[12] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
    c[13] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
    c[14] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
    c[15] = b0*a03 + b1*a13 + b2*a23 + b3*a33;
#endif
}

void matrix_mul_vector(float_t *a, float_t *b, float_t *c) {
#if defined(__ARM_NEON__) && !defined(__APPLE__)
    const float* a1 = a+8;
    asm volatile (
    "vld4.f32 {d0,d2,d4,d6}, [%1] \n" 
    "vld4.f32 {d1,d3,d5,d7}, [%2] \n" // q0-q3 = a(0,4,8,12/1,5,9,13/2,6,10,14/3,7,11,15)
    "vld1.f32 {q4}, [%3]       \n" // q4 = b
    "vmul.f32 q0, q0, d8[0]    \n" // q0 = a(0,4,8,12)*b[0]
    "vmla.f32 q0, q1, d8[1]    \n" // q0 = q0 + a(1,5,9,13)*b[1]
    "vmla.f32 q0, q2, d9[0]    \n" // q0 = q0 + a(2,6,10,14)*b[2]
    "vmla.f32 q0, q3, d9[1]    \n" // q0 = q0 + a(3,7,11,15)*b[3]
    "vst1.f32 {q0}, [%0]       \n"
    ::"r"(c), "r"(a), "r"(a1), "r"(b)
    : "q0", "q1", "q2", "q3", "q4", "memory");
#else
    c[0] = a[ 0] * b[0] + a[ 1] * b[1] + a[ 2] * b[2] + a[ 3] * b[3];
    c[1] = a[ 4] * b[0] + a[ 5] * b[1] + a[ 6] * b[2] + a[ 7] * b[3];
    c[2] = a[ 8] * b[0] + a[ 9] * b[1] + a[10] * b[2] + a[11] * b[3];
    c[3] = a[12] * b[0] + a[13] * b[1] + a[14] * b[2] + a[15] * b[3];
#endif
}

// upper3x3 of matrix4 -> inverse -> transposed mat3
void matrix_inverse3_transpose(float_t *m, float_t *r)
{
    r[0] = m[4+1]*m[8+2] - m[4+2]*m[8+1];
    r[1] = m[4+2]*m[8+0] - m[4+0]*m[8+2];
    r[2] = m[4+0]*m[8+1] - m[4+1]*m[8+0];

    r[3] = m[0+2]*m[8+1] - m[0+1]*m[8+2];
    r[4] = m[0+0]*m[8+2] - m[0+2]*m[8+0];
    r[5] = m[0+1]*m[8+0] - m[0+0]*m[8+1];

    r[6] = m[0+1]*m[4+2] - m[0+2]*m[4+1];
    r[7] = m[0+2]*m[4+0] - m[0+0]*m[4+2];
    r[8] = m[0+0]*m[4+1] - m[0+1]*m[4+0];

    float_t det = 1.0f/(m[0]*r[0] + m[4+0]*r[3] + m[8+0]*r[6]);
    for (int i = 0; i < 9; i++) r[i] *= det;
}
