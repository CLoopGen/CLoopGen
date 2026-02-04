#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access using pointer arithmetic for better spatial locality
    // Traverse the array B consecutively assuming row-major layout and ldb >= n2
    double *b_ptr = B;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            *b_ptr++ *= alpha;
        }
        b_ptr += (ldb - n2); // Skip any padding at the end of each row
    }
}
