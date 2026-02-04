#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i <= (8 + 7); i++)
        for (int depth2 = 0; depth2 < 1; depth2++)
            if (regs_ever_live[i]) {
                goto exit_loop;
            }
exit_loop:;
}
