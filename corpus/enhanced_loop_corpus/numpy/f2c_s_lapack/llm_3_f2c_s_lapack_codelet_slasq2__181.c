#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real e;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with indirect indexing via pointer arithmetic
    real *p = z__ + *n + 1;  // Point one past the last element
    for (k = *n; k >= 1; --k) {
        e += *(--p);  // Decrement pointer and access
    }
}
