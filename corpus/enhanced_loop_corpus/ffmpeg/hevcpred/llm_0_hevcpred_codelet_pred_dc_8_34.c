#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern  uint8_t *top;
extern  uint8_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < size; j++) {
        dc += left[j] + top[j];
    }
}
