#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 8; i <= (8 + 7); i++) {
        temp += regs_ever_live[i];  // Introduce loop-carried dependence: temp depends on previous iteration
        if (regs_ever_live[i]) {
            break;
        }
    }
    regs_ever_live[8] = temp;  // Write to array after loop, creating WAW with potential future iterations (if extended)
}
