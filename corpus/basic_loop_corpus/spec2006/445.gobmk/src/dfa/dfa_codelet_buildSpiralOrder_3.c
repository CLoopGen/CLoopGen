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
    if (!mark[ii + delta]) {
        fifo[top] = ii + delta;
        mark[ii + delta] = 1;
        top++;
    }
}

}
