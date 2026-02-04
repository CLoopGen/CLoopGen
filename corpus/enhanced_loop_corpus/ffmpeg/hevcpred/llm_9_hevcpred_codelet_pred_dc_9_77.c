#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern  uint16_t *top;
extern  uint16_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size * 2; i++) {
        dc += (i % 2 == 0) ? left[i/2] : top[i/2];
    }
}
