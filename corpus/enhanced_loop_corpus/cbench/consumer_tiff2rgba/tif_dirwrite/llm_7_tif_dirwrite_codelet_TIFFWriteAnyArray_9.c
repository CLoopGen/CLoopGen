#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 j;
    float temp1, temp2;
    for (j = 0; j < n - 1; j += 2) {
        temp1 = (float)v[j];
        temp2 = (float)v[j+1];
        bp[j] = temp1;
        bp[j+1] = temp2;
    }
    if (n > 0 && (n % 2) == 1) {
        bp[n-1] = (float)v[n-1];
    }
}
