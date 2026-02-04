#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse order (consecutive backward access)
    for (i = 19; i >= 0; i--) {
        hist_br_prob[i] = 0;
    }
}
