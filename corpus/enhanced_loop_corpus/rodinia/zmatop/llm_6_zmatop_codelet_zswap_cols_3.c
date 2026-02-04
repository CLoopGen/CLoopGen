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
    complex *A_i = A_me[i];
    complex *A_j = A_me[j];
    for (k = lo; k <= hi; k++) {
        tmp = A_i[k];
        A_i[k] = A_j[k];
        A_j[k] = tmp;
    }
}
