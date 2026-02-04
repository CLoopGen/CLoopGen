#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 20;
    int offset = 1;
    int step = 8;
    int limit = base + 4 * step;
    for (i = base + offset; i <= limit; i += step) {
        reg_alloc_order[pos] = i;
        pos = pos + 1;
    }
}
