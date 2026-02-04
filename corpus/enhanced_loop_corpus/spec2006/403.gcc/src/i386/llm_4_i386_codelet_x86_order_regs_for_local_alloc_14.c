#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (((((((20 + 1) + 7) + 1) + 7) + 1) + 7) + 1); i <= ((((((((20 + 1) + 7) + 1) + 7) + 1) + 7) + 1) + 7); i++) {
        if (i % 2 == 0) {
            reg_alloc_order[pos++] = i;
        }
    }
}
