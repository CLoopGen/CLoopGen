#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (; i < size; i += step) {
        if (!buf[i]) {
            break;
        }
        if (i + 1 < size && !buf[i + 1]) {
            i++;
            break;
        }
    }
}
