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
    u_int i_val;
    for (i_val = 1; i_val < QR->m; i_val++) {
        complex *row_base = Rout->me[i_val];
        for (u_int j_val = 0; j_val < QR->n && j_val < i_val; j_val++) {
            row_base[j_val].re = 0.;
            row_base[j_val].im = 0.;
            // Introduce artificial WAW dependency by writing twice (semantically same but creates write-after-write)
            row_base[j_val].re = row_base[j_val].re; // Redundant assignment: WAW on .re
        }
    }
}
