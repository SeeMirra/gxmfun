#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <math.h>

#define DEG_TO_RAD(x) ((x) * M_PI / 180.0)
#define RAD_TO_RAD(x) ((x) * 180.0 / M_PI)

typedef struct {
	float x, y;
} vector2f;

typedef struct {
	union { float x; float r; };
	union { float y; float g; };
	union { float z; float b; };
} vector3f;

typedef struct {
	union { float x; float r; };
	union { float y; float g; };
	union { float z; float b; };
	union { float w; float a; };
} vector4f;

typedef float matrix3x3[3][3];
typedef float matrix4x4[4][4];

void vector3f_init(vector3f *v, float x, float y, float z);
void vector3f_copy(vector3f *dst, const vector3f *src);
void vector3f_add(vector3f *v1, const vector3f *v2);
void vector3f_scalar_mult(vector3f *v, float a);
void vector3f_add_mult(vector3f *v, const vector3f *u, float a);
void vector3f_opposite(vector3f *v1, const vector3f *v0);
float vector3f_dot_product(const vector3f *v1, const vector3f *v2);
void vector3f_cross_product(vector3f *w, const vector3f *u, const vector3f *v);
void vector3f_matrix4x4_mult(vector3f *u, const matrix4x4 m, const vector3f *v, float w);

void matrix3x3_identity(matrix3x3 m);
void matrix3x3_from_matrix4x4(matrix3x3 dst, const matrix4x4 src);

void matrix4x4_identity(matrix4x4 m);
void matrix4x4_copy(matrix4x4 dst, const matrix4x4 src);

void matrix4x4_multiply(matrix4x4 dst, const matrix4x4 src1, const matrix4x4 src2);

void matrix4x4_init_rotation_x(matrix4x4 m, float rad);
void matrix4x4_init_rotation_y(matrix4x4 m, float rad);
void matrix4x4_init_rotation_z(matrix4x4 m, float rad);

void matrix4x4_rotate_x(matrix4x4 m, float rad);
void matrix4x4_rotate_y(matrix4x4 m, float rad);
void matrix4x4_rotate_z(matrix4x4 m, float rad);

void matrix4x4_init_translation(matrix4x4 m, float x, float y, float z);
void matrix4x4_init_translation_vector3f(matrix4x4 m, const vector3f *v);
void matrix4x4_translate(matrix4x4 m, float x, float y, float z);

void matrix4x4_init_scaling(matrix4x4 m, float scale_x, float scale_y, float scale_z);
void matrix4x4_scale(matrix4x4 m, float scale_x, float scale_y, float scale_z);
void matrix4x4_reflect_origin(matrix4x4 m);

void matrix4x4_transpose(matrix4x4 out, const matrix4x4 m);
int matrix4x4_invert(matrix4x4 out, const matrix4x4 m);

void matrix4x4_init_orthographic(matrix4x4 m, float left, float right, float bottom, float top, float near, float far);
void matrix4x4_init_frustum(matrix4x4 m, float left, float right, float bottom, float top, float near, float far);
void matrix4x4_init_perspective(matrix4x4 m, float fov, float aspect, float near, float far);

/* Graphics related */

void matrix3x3_normal_matrix(matrix3x3 out, const matrix4x4 m);

#endif
