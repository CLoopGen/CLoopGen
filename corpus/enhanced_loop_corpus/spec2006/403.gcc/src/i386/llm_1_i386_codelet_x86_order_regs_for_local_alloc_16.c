#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i <= (8 + 3); i++) {
        reg_alloc_order[pos++] = i;
        for (int inner = 0; inner < 1; inner++)
            reg_alloc_order[pos++] = i + 4;
    }
}
