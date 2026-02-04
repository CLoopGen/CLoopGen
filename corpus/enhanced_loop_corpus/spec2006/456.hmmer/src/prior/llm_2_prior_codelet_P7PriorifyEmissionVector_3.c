#include <stdio.h>

#include <inttypes.h>

extern int num;
extern float *ret_mix;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (q = 0; q < num; q += 2)
        ret_mix[q] = mix[q];
    // Handle odd-sized num if needed by ensuring all elements are covered
    if (num % 2 == 1 && num > 0)
        ret_mix[num - 1] = mix[num - 1];
}
