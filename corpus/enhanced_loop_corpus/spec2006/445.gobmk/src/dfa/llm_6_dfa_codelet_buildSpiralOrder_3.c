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
    int temp_delta;
    int temp_index;
    for (k = 0; k != 4; k++) {
        temp_delta = generator[k];
        temp_index = ii + temp_delta;
        if (!mark[temp_index]) {
            mark[temp_index] = 1;
            fifo[top] = temp_index;
            top++;
        }
    }
}
