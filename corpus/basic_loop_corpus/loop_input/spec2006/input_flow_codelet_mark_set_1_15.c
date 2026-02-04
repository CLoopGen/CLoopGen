#include <stdio.h>
#include <inttypes.h>

int regno_first = 0;
int regno_last = 1048575; // 1MB of data: 1048576 bytes
int i;
char regs_ever_live[1048576]; // 1MB array

void init_vars() {
    regno_first = 0;
    regno_last = 1048575;
    for (i = 0; i < 1048576; ++i) {
        regs_ever_live[i] = 0;
    }
}