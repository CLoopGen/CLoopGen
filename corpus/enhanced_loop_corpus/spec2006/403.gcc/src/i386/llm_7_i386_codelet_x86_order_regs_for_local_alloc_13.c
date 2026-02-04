#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    int offset = 20 + 1;
    for (i = 0; i < 8; i++) {
        temp[i] = offset + i;
    }
    for (i = 0; i < 8; i++) {
        reg_alloc_order[pos + i] = temp[i];
    }
    pos += 8;
}
