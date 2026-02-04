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
    double temp_y1 = xdbl[jr] - xdbl[ir];
    double temp_y2 = temp_y1 - carry;
    if (temp_y2 < 0) {
        carry = one_bit;
        temp_y2 += 1;
    } else {
        carry = 0;
    }
    y1 = temp_y1;
    xdbl[ir] = temp_y2;
    ir = next[ir];
    jr = next[jr];
}
}
