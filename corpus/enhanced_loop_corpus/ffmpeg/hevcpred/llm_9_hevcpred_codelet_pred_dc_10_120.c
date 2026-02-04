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
    dc += (left[i % size] + top[i % size]) * (i % 3 + 1);
}
}
