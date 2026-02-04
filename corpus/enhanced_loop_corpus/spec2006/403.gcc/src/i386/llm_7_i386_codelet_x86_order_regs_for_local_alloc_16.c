#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 8; i <= (8 + 7); i++) {
        temp = i;
        reg_alloc_order[pos] = temp;
        pos = pos + 1;
    }
}
