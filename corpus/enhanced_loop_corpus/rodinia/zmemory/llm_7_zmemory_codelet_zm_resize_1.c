#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

extern ZMAT *A;
extern int new_m;
extern int new_n;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    complex **me_ptr = A->me;
    complex *base_ptr = A->base;
    u_int n = new_n;
    for (i = 0; i < new_m; i++) {
        me_ptr[i] = &base_ptr[i * n];
    }
}
