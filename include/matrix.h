#include <gl2es.h>

// vectors
void normalize(float_t v[3]);
void cross(float_t v1[3], float_t v2[3], float_t result[3]);


// matrices
void matrix_mul_matrix(float_t *a, float_t *b, float_t *c);
void matrix_mul_vector(float_t *a, float_t *b, float_t *c);
void matrix_inverse3_transpose(float_t *m, float_t *r);