#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *map;
extern  unsigned char *source;
extern unsigned char *target;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using pointer arithmetic
    // Eliminate index-based array access and use pointers for consecutive access
    unsigned char *t = target;
    ssize_t idx;

    for (i = 0; i < 16; i++) {
        idx = map[i];
        if (idx == -1) {
            *t = 3;
        } else {
            *t = source[idx];
        }
        t++; // Consecutive write to target
    }
}
