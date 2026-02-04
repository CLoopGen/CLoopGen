#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        total_hist_br_prob[i] += hist_br_prob[i];
        total_hist_br_prob[i+5] += hist_br_prob[i+5];
        total_hist_br_prob[i+10] += hist_br_prob[i+10];
        total_hist_br_prob[i+15] += hist_br_prob[i+15];
    }
}
