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
    complex temp_local;
    for (k = lo; k < hi; k += 2) {
        if (k + 1 <= hi) {
            temp_local = A_me[k][i];
            A_me[k][i] = A_me[k+1][i];
            A_me[k+1][i] = temp_local;

            temp_local = A_me[k][j];
            A_me[k][j] = A_me[k+1][j];
            A_me[k+1][j] = temp_local;
        } else {
            temp_local = A_me[k][i];
            A_me[k][i] = A_me[k][j];
            A_me[k][j] = temp_local;
        }
    }
    if ((hi - lo + 1) % 2 == 1 && lo <= hi) {
        k = hi;
        temp_local = A_me[k][i];
        A_me[k][i] = A_me[k][j];
        A_me[k][j] = temp_local;
    }
}
