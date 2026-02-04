#include <stdio.h>

#include <inttypes.h>

extern int64_t cond[5];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (reverse order access)
    unsigned int indices[5] = {4, 3, 2, 1, 0}; // Reverse access pattern
    unsigned int i;
    for (i = 0; i < 5; i++)
        cond[indices[i]] = ((cond[indices[i]] & 72057594037927935L) - 1) >> 63;
}
