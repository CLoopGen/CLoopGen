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
    for (k = lo; k <= hi; k++) {
        if (k % 2 == 0) {
            tmp = A_me[i][k];
            A_me[i][k] = A_me[j][k];
            A_me[j][k] = tmp;
        } else {
            A_me[i][k] = (complex){ .re = 0.0, .im = 0.0 };
            A_me[j][k] = (complex){ .re = 0.0, .im = 0.0 };
        }
    }
} else {
    k = lo;
}
}
