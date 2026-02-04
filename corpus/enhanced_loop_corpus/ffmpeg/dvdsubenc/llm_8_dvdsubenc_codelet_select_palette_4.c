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
        int max_val = hits[0];
        selected[i] = 0;
        for (j = 1; j < 33; j++) {
            if (hits[j] > max_val) {
                max_val = hits[j];
                selected[i] = j;
            }
        }
        hits[selected[i]] = 0;
    }
}
