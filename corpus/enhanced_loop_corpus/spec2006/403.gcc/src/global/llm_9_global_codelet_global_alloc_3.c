#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective work with stride-based iteration and simplified assignment
    for (i = 0; i < 53; i += 3) {
        reg_allocno[i] = -1;
        if (i + 1 < 53) reg_allocno[i + 1] = -1;
    }
}
