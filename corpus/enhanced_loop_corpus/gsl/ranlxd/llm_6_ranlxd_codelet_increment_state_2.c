#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int next[12];
extern  double one_bit;
extern int k;
extern int kmax;
extern double _usr_y1;
extern double y2;
extern double *xdbl;
extern double carry;
extern unsigned int ir;
extern unsigned int jr;

// Variable name mappings to avoid conflicts with system symbols
#define y1 _usr_y1



void loop(){
for (; k < kmax; ++k) {
    double temp = xdbl[jr] - xdbl[ir] - carry;
    int update_carry = (temp < 0);
    carry = update_carry ? one_bit : 0;
    y1 = temp + (update_carry ? 1 : 0);
    y2 = y1;
    xdbl[ir] = y2;
    ir = next[ir];
    jr = next[jr];
}
}
