#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified arithmetic but added inner logic dependency
    int base = 20 + 1 + 7 + 1;
    for (i = base; i <= base + 3; i++) {
        int temp = i & 1 ? i + 1 : i * 2;
        reg_alloc_order[pos++] = temp + 5;
    }
}
