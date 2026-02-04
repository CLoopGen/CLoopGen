#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    total_hist_br_prob[0] = 0;
    for (i = 1; i < 20; i++) {
        total_hist_br_prob[i] = total_hist_br_prob[i-1] + 0;
    }
}
