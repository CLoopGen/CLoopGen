#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int next[12];
extern  double one_bit;
extern  double shift;
extern int k;
extern int kmax;
extern double _usr_y1;
extern double y2;
extern double *xdbl;
extern double *ydbl;
extern double carry;
extern unsigned int ir;
extern unsigned int jr;

// Variable name mappings to avoid conflicts with system symbols
#define y1 _usr_y1



void loop(){
// Reduce effective trip count by looping every second element
for (; k < kmax; k += 2) {
    y1 = xdbl[jr] - xdbl[ir];
    y2 = y1 - carry;
    carry = (y2 < 0) ? one_bit : 0;
    y2 = (y2 < 0) ? y2 + 1 : y2;
    xdbl[ir] = y2;
    ydbl[ir] = y2 + shift;
    // Update indices twice per iteration to reduce loop iterations
    ir = next[next[ir]];
    jr = next[next[jr]];
    // Early exit safeguard in case of invalid index
    if (ir >= 12 || jr >= 12) break;
}
}
