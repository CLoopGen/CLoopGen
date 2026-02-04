#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index arrays
    // Simulate indirect addressing by precomputing indices in a stack-allocated array
    int i;
    int len = n / 2;
    char *indices_s[64];  // Assuming max size is manageable on stack; could be dynamic in practice
    char *indices_e[64];

    if (len > 64) len = 64;  // Bound check for static arrays

    // Precompute indirect pointers (could represent non-linear or reordered access)
    for (i = 0; i < len; i++) {
        indices_s[i] = s + i;
        indices_e[i] = e - i;
    }

    // Perform swap using the precomputed pointer array
    for (i = 0; i < len; i++) {
        tc = *(indices_s[i]);
        *(indices_s[i]) = *(indices_e[i]);
        *(indices_e[i]) = tc;
    }

    // Adjust side effects: simulate original loop's pointer movement and n change
    s += len;
    e -= len;
    n = 0;
}
