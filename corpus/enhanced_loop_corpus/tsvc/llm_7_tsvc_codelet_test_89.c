#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *A;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    s += A[0];
    s += A[1];
    s += A[2];
    s += A[3];
}
