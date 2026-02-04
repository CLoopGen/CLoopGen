#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 53; i++) {
        if (i == 25) {
            continue;
        }
        reg_allocno[i] = -1;
    }
}
