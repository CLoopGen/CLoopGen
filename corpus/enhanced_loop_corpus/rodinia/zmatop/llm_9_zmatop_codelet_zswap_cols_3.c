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
complex tmp1, tmp2;
int trip_count = (hi - lo + 1) / 3;
for (k = 0; k < trip_count; k++) {
    int idx1 = lo + k;
    int idx2 = hi - k;

    tmp1 = A_me[i][idx1];
    A_me[i][idx1] = A_me[j][idx1];
    A_me[j][idx1] = tmp1;

    tmp2 = A_me[i][idx2];
    A_me[i][idx2] = A_me[j][idx2];
    A_me[j][idx2] = tmp2;

    A_me[i][idx1].re += A_me[i][idx2].im;
    A_me[j][idx1].im -= A_me[j][idx2].re;
}
}
