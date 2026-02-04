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
    int i1;
    for (i1 = 0; i1 < size; i1++) {
        int d = pix1[i1] - pix2[i1];
        ssd += d * d;
    }
}
