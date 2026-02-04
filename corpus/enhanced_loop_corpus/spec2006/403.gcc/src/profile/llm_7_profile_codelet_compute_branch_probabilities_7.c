#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    hist_br_prob[0] = 0;
    for (i = 1; i < 20; i++) {
        hist_br_prob[i] = hist_br_prob[i-1] + 0;
    }
}
