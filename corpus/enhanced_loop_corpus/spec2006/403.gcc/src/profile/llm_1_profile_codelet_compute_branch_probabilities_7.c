#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer;
    for (outer = 0; outer < 10; outer++) {
        for (i = 0; i < 2; i++) {
            hist_br_prob[outer * 2 + i] = 0;
        }
    }
}
