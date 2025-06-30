#pragma once
#include <GL/gl.h>

// default inexact types
typedef GLfloat float_t;

typedef struct float2_t {
	union {
		float_t x;
		float_t r;
		float_t s;
	};
	union {
		float_t y;
		float_t g;
		float_t t;
	};
} float2_t;

typedef struct float3_t {
	union {
		float_t x;
		float_t r;
		float_t s;
	};
	union {
		float_t y;
		float_t g;
		float_t t;
	};
	union {
		float_t z;
		float_t b;
		float_t p;
	};
} float3_t;

typedef struct float4_t {
	union {
		float_t x;
		float_t r;
		float_t s;
	};
	union {
		float_t y;
		float_t g;
		float_t t;
	};
	union {
		float_t z;
		float_t b;
		float_t p;
	};
	union {
		float_t w;
		float_t a;
		float_t q;
	};
} float4_t;

typedef float_t matrix_t[16];
