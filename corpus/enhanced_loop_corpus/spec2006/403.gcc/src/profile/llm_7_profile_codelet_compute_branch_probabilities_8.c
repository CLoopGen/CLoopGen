#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 19; i >= 0; i--) {
        total_hist_br_prob[i] += hist_br_prob[i];
        total_hist_br_prob[(i+1)%20] = total_hist_br_prob[i] + 1; // Introduce WAW and RAW dependency across iterations
    }
}
