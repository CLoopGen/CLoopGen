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
// Decreased depth by unrolling the original loop completely (depth reduced to zero iteration control)
delta = generator[0];
if (!mark[ii + delta]) {
    fifo[top] = ii + delta;
    mark[ii + delta] = 1;
    top++;
}
delta = generator[1];
if (!mark[ii + delta]) {
    fifo[top] = ii + delta;
    mark[ii + delta] = 1;
    top++;
}
delta = generator[2];
if (!mark[ii + delta]) {
    fifo[top] = ii + delta;
    mark[ii + delta] = 1;
    top++;
}
delta = generator[3];
if (!mark[ii + delta]) {
    fifo[top] = ii + delta;
    mark[ii + delta] = 1;
    top++;
}
}
