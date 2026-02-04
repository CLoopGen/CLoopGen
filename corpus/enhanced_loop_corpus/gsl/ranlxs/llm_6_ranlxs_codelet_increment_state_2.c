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
    double temp_x_ir = xdbl[ir];
    y1 = xdbl[jr] - temp_x_ir;
    y2 = y1 - carry;
    carry = (y2 < 0) ? one_bit : 0;
    y2 += (y2 < 0) ? 1 : 0;
    xdbl[ir] = y2;
    ydbl[ir] = y2 + shift;
    ir = next[ir];
    jr = next[jr];
}
}
