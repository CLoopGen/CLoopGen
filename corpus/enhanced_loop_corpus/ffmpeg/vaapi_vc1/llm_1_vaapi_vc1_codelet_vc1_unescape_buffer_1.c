#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    int total = size;
    int block = 1;
    for (i = 0; i < total; i += block) {
        for (j = i; j < i + block && j < total; j++) {
            dsize = j;
            *dst++ = *src++;
        }
    }
}
