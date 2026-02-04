#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int hits[33];
extern int i;
extern int j;
extern int selected[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        int max_val = hits[selected[i]];
        int max_idx = selected[i];
        for (j = 0; j < 33; j++) {
            if (hits[j] > max_val) {
                max_val = hits[j];
                max_idx = j;
            }
        }
        selected[i] = max_idx;
        hits[max_idx] = 0;
    }
}
