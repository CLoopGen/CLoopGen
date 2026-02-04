#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element access with bounds check
    for (; i + 1 < size; i++)
        if (!buf[i] || !buf[i + 1])
            break;
}
