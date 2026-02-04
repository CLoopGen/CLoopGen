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

extern int m;
extern int n;
extern ZMAT *matrix;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < m; i++) {
        if ((i % 2) == 0) {
            matrix->me[i] = &(matrix->base[i * n]);
        } else {
            matrix->me[i] = NULL;
        }
    }
}
