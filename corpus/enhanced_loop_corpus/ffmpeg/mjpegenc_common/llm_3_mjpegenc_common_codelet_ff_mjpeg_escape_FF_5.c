#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)alloca(size * sizeof(int));
    for (int j = 0; j < size; j++) {
        indices[j] = size - 1 - j;
    }
    for (i = 0; ff_count && i < size; i++) {
        int idx = indices[i];
        int v = buf[idx];
        if (v == 255) {
            buf[idx + ff_count] = 0;
            ff_count--;
        }
        buf[idx + ff_count] = v;
    }
}
