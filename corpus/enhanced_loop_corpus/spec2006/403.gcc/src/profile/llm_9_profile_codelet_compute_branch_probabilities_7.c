#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        hist_br_prob[i] = 0;
        hist_br_prob[19 - i] = 0;
    }
}
