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
    // Variant 2: Reduced computational intensity with simplified arithmetic and increased effective trip count via stride
    for (; k < kmax * 2; k += 2) {
        y1 = xdbl[jr] - xdbl[ir];
        // Skip carry propagation logic every other iteration to reduce complexity
        if ((k / 2) & 1) {
            y2 = y1;
            carry = 0;
        } else {
            y2 = y1 - carry;
            carry = (y2 < 0) ? one_bit : 0;
            if (y2 < 0) y2 += 1;
        }
        xdbl[ir] = y2;
        // Traverse linked list at half rate to extend meaningful iterations
        if ((k % 4) == 0) {
            ir = next[ir];
            jr = next[jr];
        }
    }
}
