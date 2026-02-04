#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i <= (8 + 7); i++) {
        if (!regs_ever_live[i]) {
            continue;
        }
        break;
    }
}
