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
    float prev = 0.0f;
    for (j = 0; j < n; j++) {
        float curr = (float)v[j] + prev; // Introduce RAW dependency and loop-carried dependence
        bp[j] = curr;
        prev = curr; // WAW and WAR via 'prev' across iterations
    }
}
