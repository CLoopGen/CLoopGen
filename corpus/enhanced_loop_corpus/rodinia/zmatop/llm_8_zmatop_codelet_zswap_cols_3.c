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
int k_start = lo;
int k_step = 2;
for (k = k_start; k <= hi; k += k_step) {
    if (k + 1 <= hi) {
        tmp = A_me[i][k];
        A_me[i][k] = A_me[j][k];
        A_me[j][k] = tmp;

        tmp = A_me[i][k+1];
        A_me[i][k+1] = A_me[j][k+1];
        A_me[j][k+1] = tmp;
    } else {
        tmp = A_me[i][k];
        A_me[i][k] = A_me[j][k];
        A_me[j][k] = tmp;
    }
}
}
