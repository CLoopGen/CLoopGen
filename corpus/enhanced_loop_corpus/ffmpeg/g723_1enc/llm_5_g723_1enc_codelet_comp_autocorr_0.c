#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t hamming_window[180];
extern int i;
extern int16_t vector[180];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (((60 << 2) / 2) + 60); i++) {
        int16_t temp = vector[i];
        if (temp > 0 || hamming_window[i] > 0) {
            temp = (temp * hamming_window[i] + (1 << 14)) >> 15;
        }
        vector[i] = temp;
    }
}
