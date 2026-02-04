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
    int step = 2; // Strided access with step size 2
    int ir_stride = ir * step;
    int jr_stride = jr * step;
    y1 = xdbl[jr_stride] - xdbl[ir_stride];
    y2 = y1 - carry;
    if (y2 < 0) {
        carry = one_bit;
        y2 += 1;
    } else {
        carry = 0;
    }
    xdbl[ir_stride] = y2;
    ydbl[ir_stride] = y2 + shift;
    ir = next[ir];
    jr = next[jr];
}
}
