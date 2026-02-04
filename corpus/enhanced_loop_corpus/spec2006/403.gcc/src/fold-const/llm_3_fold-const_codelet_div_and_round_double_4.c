#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index mapping array (simulates irregular access)
    int index_map[5] = {4, 0, 3, 1, 2}; // Custom permutation of indices
    for (i = 0; i <= 4 - 1; i++) {
        int idx = index_map[i]; // Indirect access using lookup table
        work = (num[idx] * scale) + carry;
        num[idx] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry = ((unsigned long)(work) >> (8 * 8) / 2);
    }
}
