#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 8;
    for (i = 0; i < 8; i++) {
        reg_alloc_order[pos + i] = base + i;
    }
    pos += 8;
}
