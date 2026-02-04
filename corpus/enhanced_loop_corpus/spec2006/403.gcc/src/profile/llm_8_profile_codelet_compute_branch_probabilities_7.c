#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 40; i += 2) {
        hist_br_prob[i/2] = 0;
        hist_br_prob[i/2] += 1;
        hist_br_prob[i/2] -= 1;
    }
}
