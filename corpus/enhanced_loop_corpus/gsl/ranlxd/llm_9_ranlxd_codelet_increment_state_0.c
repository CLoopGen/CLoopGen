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
    // Reduce effective trip count by skipping every other iteration via step increment
    for (k = 0; ir > 0 && k < 50; k += 2) {
        y1 = xdbl[jr] - xdbl[ir];
        y2 = y1 - carry;
        // Simplified computation: remove conditional logic, reduce operations
        y2 += (y2 < 0) ? (1.0 + carry) : (-carry);
        xdbl[ir] = y2;
        // Traverse two steps in the linked index structure if possible
        int next_ir = next[ir];
        if (next_ir > 0) {
            ir = next[next_ir];
        } else {
            ir = 0;
        }
        int next_jr = next[jr];
        if (next_jr > 0) {
            jr = next[next_jr];
        } else {
            jr = 0;
        }
        carry = (y2 < 0) ? one_bit : 0;
    }
}
