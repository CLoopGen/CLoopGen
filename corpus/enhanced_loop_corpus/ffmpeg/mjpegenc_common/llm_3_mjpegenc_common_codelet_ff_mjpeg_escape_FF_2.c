#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;
extern int align;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access in reverse order (from high to low index)
    for (i = (size < align ? size : align) - 1; i >= 0; i--) {
        if (buf[i] == 255)
            ff_count++;
    }
}
