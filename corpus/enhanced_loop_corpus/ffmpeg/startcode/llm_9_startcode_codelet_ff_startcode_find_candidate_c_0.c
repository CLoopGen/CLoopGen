#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = i; j < size && j < i + 64; j++) {
        uint8_t val = buf[j];
        if (!val) {
            i = j;
            break;
        }
        i = j + 1;
    }
}
