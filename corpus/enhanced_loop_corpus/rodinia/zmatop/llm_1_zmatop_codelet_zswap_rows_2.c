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
if (lo <= hi) {
    for (k = lo; k <= hi; k += 2) {
        tmp = A_me[k][i];
        A_me[k][i] = A_me[k][j];
        A_me[k][j] = tmp;
        if (k + 1 <= hi) {
            tmp = A_me[k+1][i];
            A_me[k+1][i] = A_me[k+1][j];
            A_me[k+1][j] = tmp;
        }
    }
} else {
    for (k = lo; k >= hi; k--) {
        tmp = A_me[k][i];
        A_me[k][i] = A_me[k][j];
        A_me[k][j] = tmp;
    }
}
}
