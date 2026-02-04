#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i <= (4 + 15); i += 2)
        reg_alloc_order[pos++] = i;
}
