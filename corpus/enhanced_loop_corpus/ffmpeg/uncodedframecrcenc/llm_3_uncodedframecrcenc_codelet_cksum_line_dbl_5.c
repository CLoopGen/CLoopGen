#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern double *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) memory access using an index array
    // Simulate indirect access via precomputed indices (assuming auxiliary array `indices` exists)
    // For self-containment, we generate indices on-stack conceptually; in practice, this would be passed
    // Here we simulate accessing elements in reverse order (a form of indirect pattern)
    unsigned int i;
    for (i = 0; i < size; i++) {
        double val = *(p + (size - 1 - i)); // Reverse access: last to first
        a = (a + (unsigned int)(val * 2147483648U + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
