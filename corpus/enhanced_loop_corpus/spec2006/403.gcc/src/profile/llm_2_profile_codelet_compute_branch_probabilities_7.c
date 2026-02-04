#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 20; i += 2) {
        hist_br_prob[i] = 0;
        if (i + 1 < 20) {
            hist_br_prob[i + 1] = 0;
        }
    }
}
