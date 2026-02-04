#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate indirect access by reversing the effective write order (i.e., access table16[65535-i])
    for (i = 0; i <= 65535; i++) {
        int idx = 65535 - i; // Indirect index
        table16[idx] = (J16SAMPLE)i;
    }
}
