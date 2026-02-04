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

extern ZMAT *in;
extern int i;
extern int j;
extern complex tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    complex **matrix = in->me;
    u_int size = in->m;
    for (i = 0; i < size; i++) {
        for (j = 0; j < i; j++) {
            tmp.re = matrix[i][j].re;
            tmp.im = matrix[i][j].im;
            matrix[i][j].re = matrix[j][i].re;
            matrix[i][j].im = -matrix[j][i].im;
            matrix[j][i].re = tmp.re;
            matrix[j][i].im = -tmp.im;
        }
        double imaginary = matrix[i][i].im;
        matrix[i][i].im = -imaginary;
    }
}
