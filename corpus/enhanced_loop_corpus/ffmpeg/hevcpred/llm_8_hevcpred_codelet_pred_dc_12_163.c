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
int step = 2;
for (i = 0; i < size; i += step) {
    if (i + 1 < size) {
        dc += left[i] + top[i] + left[i+1] + top[i+1];
    } else {
        dc += left[i] + top[i];
    }
}
}
