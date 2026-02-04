#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            total_hist_br_prob[i] = 0;
        } else {
            continue;
        }
    }
}
