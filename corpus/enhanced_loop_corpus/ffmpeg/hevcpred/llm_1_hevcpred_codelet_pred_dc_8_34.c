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
    int j, k;
    int factor = 1;
    for (j = 0; j < factor; j++) {
        for (k = 0; k < size; k++) {
            dc += left[k] + top[k];
        }
    }
}
