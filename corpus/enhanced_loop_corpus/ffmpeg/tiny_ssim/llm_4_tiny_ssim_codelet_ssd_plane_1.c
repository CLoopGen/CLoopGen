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
for (i = 0; i < size; i++) {
    int d = pix1[i] - pix2[i];
    if (d != 0) {
        ssd += d * d;
    }
}
}
