#ifndef _VECTOR_H
#define _VECTOR_H
#define EPSILON 1e-6
#include <math.h>
typedef struct
{
    float x;
    float y;
    float z;
    int error; // 0 - no error; 1 - has error
} Vector;

// returns a vector with the values of x, y and z = 0; and error = 0
Vector VECTOR_create()
{
    Vector v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    v.error = 0;
    return v;
}

// modifies the vector with to the values of x, y and z = 0; and error = 0
void VECTOR_destroy(Vector *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
    v->error = 0;
}

// Function to set the values of x, y, z in v; and error = 0
void VECTOR_set(Vector *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->error = 0;
}

// Function that returns the x value in the vector
float VECTOR_getX(Vector v)
{
    return v.x;
}

// Function that returns the y value in the vector
float VECTOR_getY(Vector v)
{
    return v.y;
}

// Function that returns the z value in the vector
float VECTOR_getZ(Vector v)
{
    return v.z;
}

// Function that returns the magnitude of a vector v
float VECTOR_magnitude(Vector v)
{
    float x = VECTOR_getX(v);
    float y = VECTOR_getY(v);
    float z = VECTOR_getZ(v);
    float magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return magnitude;
}

// Function that returns dot product of two vectors
float VECTOR_dotProduct(Vector v1, Vector v2)
{
    Vector c;
    float dot_product = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    return dot_product;
}

// Function to calculate cross product of two vectors, result is stored in r
// if v1 and v2 are parallel set error of r to 1, otherwise set it to 0
// v1 and v2 are parallel if the dot product of the two vector is equal to the product of their magnitudes
void VECTOR_crossProduct(Vector *r, Vector v1, Vector v2)
{
    Vector cross_product;
    float dot_product = VECTOR_dotProduct(v1, v2);
    float magnitude1 = VECTOR_magnitude(v1);
    float magnitude2 = VECTOR_magnitude(v2);

    if (fabs(dot_product - (magnitude1 * magnitude2)) < EPSILON)
    {
        r->error = 1;
    }
    else
    {
        r->x = (v1.y * v2.z) - (v1.z * v2.y);
        r->y = (v1.z * v2.x) - (v1.x * v2.z);
        r->z = (v1.x * v2.y) - (v1.y * v2.x);
        r->error = 0;
    }
}

// Function to add two vectors, v1 and v2; result is stored in r ; and error = 0
void VECTOR_addition(Vector *r, Vector v1, Vector v2)
{
    r->x = v1.x + v2.x;
    r->y = v1.y + v2.y;
    r->z = v1.z + v2.z;
    r->error = 0;
}

// Function to subtract two vectors v1 - v2; result is stored in r; and error = 0
void VECTOR_substraction(Vector *r, Vector v1, Vector v2)
{
    r->x = v1.x - v2.x;
    r->y = v1.y - v2.y;
    r->z = v1.z - v2.z;
    r->error = 0;
}

// Function to divide a vector by a scalar value, updates the vector v
// if scalar is 0, set the error to 1 and do not perform the division
void VECTOR_scalarDivision(Vector *v, float scalar)
{
    if (scalar == 0)
    {
        v->error = 1;
    }
    else
    {
        v->x /= scalar;
        v->y /= scalar;
        v->z /= scalar;
        v->error = 0;
    }
}
#endif
