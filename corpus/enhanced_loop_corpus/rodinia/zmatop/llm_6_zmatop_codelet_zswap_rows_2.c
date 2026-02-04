#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern int i;
extern int j;
extern int lo;
extern int hi;
extern int k;
extern complex **A_me;
extern complex tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    complex *Ak_i;
    complex *Ak_j;
    for (k = lo; k <= hi; k++) {
        Ak_i = &A_me[k][i];
        Ak_j = &A_me[k][j];
        tmp = *Ak_i;
        *Ak_i = *Ak_j;
        *Ak_j = tmp;
    }
}
