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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    for (; k < kmax - 1; k += 2) {
        double y1_a = xdbl[jr] - xdbl[ir];
        double y2_a = y1_a - carry;
        if (y2_a < 0) {
            carry = one_bit;
            y2_a += 1;
        } else {
            carry = 0;
        }
        xdbl[ir] = y2_a;
        unsigned int ir_next = next[ir];
        unsigned int jr_next = next[jr];

        double y1_b = xdbl[jr_next] - xdbl[ir_next];
        double y2_b = y1_b - carry;
        if (y2_b < 0) {
            carry = one_bit;
            y2_b += 1;
        } else {
            carry = 0;
        }
        xdbl[ir_next] = y2_b;

        ir = next[ir_next];
        jr = next[jr_next];
    }
    // Handle leftover iteration if kmax is odd
    if (k < kmax) {
        y1 = xdbl[jr] - xdbl[ir];
        y2 = y1 - carry;
        if (y2 < 0) {
            carry = one_bit;
            y2 += 1;
        } else {
            carry = 0;
        }
        xdbl[ir] = y2;
        ir = next[ir];
        jr = next[jr];
        ++k;
    }
}
