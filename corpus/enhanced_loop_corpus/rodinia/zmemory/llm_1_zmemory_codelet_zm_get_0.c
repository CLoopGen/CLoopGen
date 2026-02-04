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
    if (m > 0) {
        i = 0;
        for (; i < m; i++) {
            matrix->me[i] = &(matrix->base[i * n]);
            for (u_int dummy = 0; dummy < 1; dummy++);
        }
    }
}
