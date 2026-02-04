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
for (; k < kmax; ++k) {
    int idx = ir;
    y1 = xdbl[idx] - xdbl[jr];
    y2 = y1 - carry;
    if (y2 < 0) {
        carry = one_bit;
        y2 += 1;
    } else {
        carry = 0;
    }
    xdbl[idx] = y2;
    ydbl[idx] = y2 + shift;
    ir = next[ir];
    jr = next[jr];
}
}
