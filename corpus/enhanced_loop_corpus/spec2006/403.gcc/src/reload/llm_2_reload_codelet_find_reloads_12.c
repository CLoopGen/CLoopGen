#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matched[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (int stride = 0; stride < noperands; stride += 2) {
        goal_alternative_matched[stride] = -1;
        if (stride + 1 < noperands) {
            goal_alternative_matched[stride + 1] = -1;
        }
    }
}
