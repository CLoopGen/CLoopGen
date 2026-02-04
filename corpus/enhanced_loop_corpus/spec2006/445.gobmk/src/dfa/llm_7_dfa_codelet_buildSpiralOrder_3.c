#include <stdio.h>

#include <inttypes.h>

extern  int generator[4];
extern int mark[7056];
extern int fifo[14112];
extern int top;
extern int k;
extern int ii;
extern int delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_top = top;
    for (k = 0; k != 4; k++) {
        delta = generator[k];
        int addr = ii + delta;
        if (!mark[addr]) {
            fifo[local_top] = addr;
            mark[addr] = 1;
            local_top++;
        }
    }
    top = local_top;
}
