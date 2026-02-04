#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i <= (8 + 7); i++) {
        if (regs_ever_live[i]) {
            if (i % 2 == 0) {
                // Introduce additional control path without altering logic
            } else {
                goto exit_loop;
            }
        }
    }
    exit_loop: ;
}
