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
    int prev = 0;
    int temp;
    for (i = 0; i < size; i++) {
        temp = left[i] + top[i] + prev;
        prev = temp;
    }
    dc += prev;
}
