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
    for (k = lo; k <= hi; k += 2) {
        if (k + 1 <= hi) {
            tmp = A_me[i][k];
            A_me[i][k] = A_me[j][k];
            A_me[j][k] = tmp;

            tmp = A_me[i][k + 1];
            A_me[i][k + 1] = A_me[j][k + 1];
            A_me[j][k + 1] = tmp;
        } else {
            tmp = A_me[i][k];
            A_me[i][k] = A_me[j][k];
            A_me[j][k] = tmp;
        }
    }
}
