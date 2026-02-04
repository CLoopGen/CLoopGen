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
    if (size > 0) {
        i = 0;
        for (; i < size; i++) {
            dc += left[i] + top[i];
        }
    }
}
