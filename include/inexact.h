#pragma once

// default inexact types
typedef double inexact;

typedef struct float2_t {
	union {
		inexact x;
		inexact r;
		inexact s;
	};
	union {
		inexact y;
		inexact g;
		inexact t;
	};
} float2_t;

typedef struct float3_t {
	union {
		inexact x;
		inexact r;
		inexact s;
	};
	union {
		inexact y;
		inexact g;
		inexact t;
	};
	union {
		inexact z;
		inexact b;
		inexact p;
	};
} float3_t;

typedef struct float4_t {
	union {
		inexact x;
		inexact r;
		inexact s;
	};
	union {
		inexact y;
		inexact g;
		inexact t;
	};
	union {
		inexact z;
		inexact b;
		inexact p;
	};
	union {
		inexact w;
		inexact a;
		inexact q;
	};
} float4_t;

typedef inexact matrix_t[16];
