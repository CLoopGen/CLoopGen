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
    uint64_t temp_ssd = ssd;
    for (i = 0; i < size; i += 2) {
        int d1 = (i + 0 < size) ? (pix1[i] - pix2[i]) : 0;
        int d2 = (i + 1 < size) ? (pix1[i+1] - pix2[i+1]) : 0;
        temp_ssd += d1 * d1;
        temp_ssd += d2 * d2;
    }
    ssd = temp_ssd;
}
