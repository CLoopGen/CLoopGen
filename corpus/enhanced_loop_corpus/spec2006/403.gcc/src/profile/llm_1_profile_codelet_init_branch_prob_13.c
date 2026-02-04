#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        total_hist_br_prob[i * 4 + 0] = 0;
        total_hist_br_prob[i * 4 + 1] = 0;
        total_hist_br_prob[i * 4 + 2] = 0;
        total_hist_br_prob[i * 4 + 3] = 0;
    }
}
