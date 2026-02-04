#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[20];
    for (i = 0; i < 20; i++) {
        temp[i] = 0;
    }
    for (i = 0; i < 20; i++) {
        hist_br_prob[i] = temp[i];
    }
}
