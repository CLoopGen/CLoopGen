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
    int temp_max = hits[selected[i]];
    for (j = 1; j < 33; j++) {
        if (hits[j] > temp_max) {
            selected[i] = j;
            temp_max = hits[j];
        }
    }
    hits[selected[i]] = 0;
}
}
