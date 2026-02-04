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

extern ZMAT *QR;
extern ZMAT *Rout;
extern u_int i;
extern u_int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int temp_i, temp_j;
    for (temp_i = 1; temp_i < QR->m; temp_i++) {
        for (temp_j = 0; temp_j < QR->n && temp_j < temp_i; temp_j++) {
            double zero_val = 0.0;
            Rout->me[temp_i][temp_j].re = zero_val;
            Rout->me[temp_i][temp_j].im = zero_val;
        }
    }
}
