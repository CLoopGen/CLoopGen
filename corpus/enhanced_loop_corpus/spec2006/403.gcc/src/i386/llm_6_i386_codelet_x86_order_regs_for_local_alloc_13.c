#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 20 + 1;
    int limit = base + 7;
    for (i = base; i <= limit; i++) {
        reg_alloc_order[pos] = i;
        pos += 1;
    }
}
