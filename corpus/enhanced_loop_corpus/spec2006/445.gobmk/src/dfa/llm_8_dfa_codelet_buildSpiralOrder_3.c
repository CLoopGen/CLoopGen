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
    for (k = 0; k < 4; k += 2) {
        delta = generator[k];
        int index1 = ii + delta;
        if (!mark[index1]) {
            fifo[top] = index1;
            mark[index1] = 1;
            top++;
        }
        if (k + 1 < 4) {
            delta = generator[k + 1];
            int index2 = ii + delta;
            if (!mark[index2]) {
                fifo[top] = index2;
                mark[index2] = 1;
                top++;
            }
        }
    }
}
