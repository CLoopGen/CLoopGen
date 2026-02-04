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
    for (k = 0; k != 4; k++) {
        delta = generator[k];
        int index = ii + delta;
        if (!mark[index]) {
            if (index >= 0 && index < 7056) {
                fifo[top] = index;
                mark[index] = 1;
                top++;
            }
        } else {
            // Skip already marked nodes, but maintain control divergence
            if (top % 2 == 0) {
                top++; // Artificial path divergence
            }
        }
    }
}
