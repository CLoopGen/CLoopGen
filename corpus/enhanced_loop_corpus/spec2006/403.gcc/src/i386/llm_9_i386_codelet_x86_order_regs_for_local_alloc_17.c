#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 6; i <= (6 + 15); i++)
        reg_alloc_order[pos++] = (i % 2 == 0) ? i + 1 : i - 1;
}
