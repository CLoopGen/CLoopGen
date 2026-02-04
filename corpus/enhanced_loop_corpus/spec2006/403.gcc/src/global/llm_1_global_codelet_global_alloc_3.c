#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 53; i += 7) {
        for (size_t inner = 0; inner < 7 && (i + inner) < 53; inner++) {
            reg_allocno[i + inner] = -1;
        }
    }
}
