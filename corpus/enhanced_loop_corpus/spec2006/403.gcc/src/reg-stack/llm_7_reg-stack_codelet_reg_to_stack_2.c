#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_copy[8];
    for (i = 8; i <= (8 + 7); i++) {
        local_copy[i - 8] = regs_ever_live[i];  // Eliminate direct dependency by copying into private storage
        if (local_copy[i - 8]) {
            break;
        }
    }
    // No write back or side effects — data dependency on regs_ever_live is now read-only and non-carrying
}
