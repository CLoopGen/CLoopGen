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
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            dc += left[i];
        } else {
            dc += top[i];
        }
    }
}
