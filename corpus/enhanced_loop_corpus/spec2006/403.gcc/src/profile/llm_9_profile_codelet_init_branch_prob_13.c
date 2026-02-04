#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; i++) {
        if (i < 20) total_hist_br_prob[i] = 0;
        else total_hist_br_prob[39 - i] = 0;
    }
}
