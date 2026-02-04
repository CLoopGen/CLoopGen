#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int next[12];
extern  double one_bit;
extern int k;
extern double _usr_y1;
extern double y2;
extern double *xdbl;
extern double carry;
extern unsigned int ir;
extern unsigned int jr;

// Variable name mappings to avoid conflicts with system symbols
#define y1 _usr_y1



void loop(){
for (k = 0; ir > 0; ++k) {
    y1 = xdbl[jr] - xdbl[ir];
    y2 = y1 - carry;
    carry = (y2 < 0) ? one_bit : 0;
    y2 += (y2 < 0) ? 1 : 0;
    xdbl[ir] = y2;
    ir = next[ir];
    jr = next[jr];
}
}
