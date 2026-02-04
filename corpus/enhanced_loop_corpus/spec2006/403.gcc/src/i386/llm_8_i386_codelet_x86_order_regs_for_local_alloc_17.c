#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i <= (8 + 7); i += 2)
        reg_alloc_order[pos++] = i * i + 3;
}
