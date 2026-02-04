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
    double prev_y2 = 0;
    int prev_ir = ir;
    for (k = 0; ir > 0; ++k) {
        y1 = xdbl[jr] - xdbl[ir];
        y2 = y1 - carry;
        if (y2 < 0) {
            carry = one_bit;
            y2 += 1;
        } else {
            carry = 0;
        }
        if (prev_ir > 0) {
            xdbl[prev_ir] = prev_y2;
        }
        prev_y2 = y2;
        prev_ir = ir;
        ir = next[ir];
        jr = next[jr];
    }
    if (prev_ir > 0) {
        xdbl[prev_ir] = prev_y2;
    }
}
