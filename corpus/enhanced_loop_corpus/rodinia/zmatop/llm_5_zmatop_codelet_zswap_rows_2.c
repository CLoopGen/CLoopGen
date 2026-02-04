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
if (lo <= hi && i >= 0 && j >= 0) {
    for (k = lo; k <= hi; k++) {
        if (A_me[k] != NULL) {
            tmp = A_me[k][i];
            A_me[k][i] = A_me[k][j];
            A_me[k][j] = tmp;
        }
    }
} else {
    k = lo - 1;
}
}
