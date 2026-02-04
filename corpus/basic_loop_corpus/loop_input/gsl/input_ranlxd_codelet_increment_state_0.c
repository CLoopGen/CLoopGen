#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (1 << 20)

int next[12];
double one_bit;
int k;
double _usr_y1;
double y2;
double *xdbl;
double carry;
unsigned int ir;
unsigned int jr;

void init_vars() {
    // Allocate xdbl array with DATA_SIZE elements
    xdbl = (double*)aligned_alloc(sizeof(double), DATA_SIZE * sizeof(double));
    
    // Initialize xdbl with non-zero values to avoid division by zero or other issues
    for (int i = 0; i < DATA_SIZE; ++i) {
        xdbl[i] = (double)(i % 1000) / 100.0;
    }

    // Initialize one_bit to a small value, e.g., 2^-53 for double precision epsilon
    one_bit = 1.1102230246251565e-16;

    // Set up next pointers as a linked list within bounds [0, 11]
    for (int i = 0; i < 11; ++i) {
        next[i] = i + 1;
    }
    next[11] = 0; // Circular to prevent going out of bounds indefinitely

    // Initialize ir and jr to valid indices in the next array and xdbl
    ir = 0;
    jr = 5;

    // Initialize carry and y1, y2
    carry = 0.0;
    _usr_y1 = 0.0;
    y2 = 0.0;
    k = 0;
}