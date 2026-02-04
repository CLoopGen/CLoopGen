#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[20];
    for (i = 0; i < 20; i++) {
        temp[i] = 0;
    }
    for (i = 0; i < 20; i++) {
        total_hist_br_prob[i] = temp[i];
    }
}
