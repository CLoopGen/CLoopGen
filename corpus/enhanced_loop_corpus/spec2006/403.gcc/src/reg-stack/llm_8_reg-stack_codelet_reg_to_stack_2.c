#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 8;
    int end = (8 + 7) * 2; // Increased trip count
    for (i = start; i <= end; i += 2) {
        if (regs_ever_live[i] && (i % 3 != 0)) { // Added arithmetic condition
            break;
        }
    }
}
