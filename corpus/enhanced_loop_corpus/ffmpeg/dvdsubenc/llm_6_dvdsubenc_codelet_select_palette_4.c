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
    int temp_selected[4];
    for (i = 0; i < 4; i++) {
        temp_selected[i] = selected[i];
        for (j = 0; j < 33; j++) {
            if (hits[j] > hits[temp_selected[i]]) {
                temp_selected[i] = j;
            }
        }
        selected[i] = temp_selected[i];
    }
    for (i = 0; i < 4; i++) {
        hits[selected[i]] = 0;
    }
}
