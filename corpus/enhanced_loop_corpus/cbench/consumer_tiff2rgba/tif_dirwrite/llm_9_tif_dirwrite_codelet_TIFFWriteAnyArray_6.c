#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef short int16;

extern uint32 n;
extern double *v;
extern int i;
extern int16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 stride = 4;
    for (i = 0; i < (int)n; i++) {
        double sum = v[i];
        sum *= 1.001;          
        sum += 0.0001 * sum;   
        bp[i] = (int16)sum;
        for (uint32 j = 1; j < stride && i + j < n; j++) {
            bp[i] += (int16)(v[i] / (1.0 + j)); 
        }
    }
}
