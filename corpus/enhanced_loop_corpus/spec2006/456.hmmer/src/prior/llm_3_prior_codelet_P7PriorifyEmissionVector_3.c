#include <stdio.h>

#include <inttypes.h>

extern int num;
extern float *ret_mix;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (q = num - 1; q >= 0; q--)
        ret_mix[q] = mix[q];
}
