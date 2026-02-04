#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *pix1;
extern  uint8_t *pix2;
extern int size;
extern uint64_t ssd;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, k;
    int chunk = 4;
    int rounded_size = (size / chunk) * chunk;
    for (j = 0; j < rounded_size; j += chunk) {
        for (k = 0; k < chunk; k++) {
            int idx = j + k;
            int d = pix1[idx] - pix2[idx];
            ssd += d * d;
        }
    }
    for (i = rounded_size; i < size; i++) {
        int d = pix1[i] - pix2[i];
        ssd += d * d;
    }
}
