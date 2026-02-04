#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct endianess {
    uint32_t magic;
    int is_le;
};


extern  struct endianess table[];
extern uint32_t magic;
extern int le;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (access every second element, then handle remainder)
    int stride = 2;
    int found = 0;

    // First pass: strided access
    for (i = 0; i < 7 && !found; i += stride) {
        if (magic == table[i].magic) {
            le = table[i].is_le;
            found = 1;
        }
    }

    // Second pass: check skipped elements if not found in strided pass
    if (!found) {
        for (i = 1; i < 7; i += stride) {
            if (magic == table[i].magic) {
                le = table[i].is_le;
                break;
            }
        }
    }
}
