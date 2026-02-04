#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i <= (8 + 7); i++) {
        int squared_index = i * i; // Additional arithmetic operation
        int offset = squared_index % 53;
        if (regs_ever_live[offset]) {
            if ((offset + i) % 2 == 0) { // Extra computational check
                break;
            }
        }
    }
}
