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
    for (k = 0; k != 8; k++) {
        delta = generator[k % 4] + (k / 4) * 32;
        int offset = ii + delta;
        if (offset < 7056 && !mark[offset]) {
            fifo[top] = offset;
            mark[offset] = 1;
            top++;
        }
    }
}
