#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 20; i++) {
    if (i % 2 == 0) {
        hist_br_prob[i] = 0;
    } else {
        continue;
    }
}
}
