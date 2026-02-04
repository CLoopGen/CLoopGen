#include <stdio.h>

#include <inttypes.h>

extern int numlines_s[63];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int indices[63];
    for (int j = 0; j < 63; j++) indices[j] = j;
    for (i = 0; indices[i] < 63 && numlines_s[indices[i]] >= 0; i++)
        ;
}
