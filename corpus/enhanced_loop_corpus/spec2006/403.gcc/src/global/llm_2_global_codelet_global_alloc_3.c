#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (size_t i = 0; i < 53; i += 2)
        reg_allocno[i] = -1;
    // Handle odd indices if needed, but original loop covers all indices.
    // Since original loop initializes every index, we complete the strided pattern
    // by ensuring all elements are covered. However, to keep it as a pure strided variant
    // and avoid branching, we assume size is even or accept partial coverage.
    // To fully initialize all elements using strided access, use two passes.
    for (size_t i = 1; i < 53; i += 2)
        reg_allocno[i] = -1;
}
