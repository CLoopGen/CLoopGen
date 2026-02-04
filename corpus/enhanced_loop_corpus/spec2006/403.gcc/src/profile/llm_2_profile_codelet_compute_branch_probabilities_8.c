#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 20; i += 2) {
        total_hist_br_prob[i] += hist_br_prob[i];
        if (i + 1 < 20) {
            total_hist_br_prob[i + 1] += hist_br_prob[i + 1];
        }
    }
}
