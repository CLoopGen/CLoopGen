#include <stdio.h>

#include <inttypes.h>

typedef uint64_t u64;

typedef u64 smallfelem[4];

extern  u64 idx;
extern unsigned int size;
extern  smallfelem pre_comp[16][3];
extern unsigned int i;
extern unsigned int j;
extern u64 *outlimbs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        u64 base_index = i * 12; // Assuming flattened access: each pre_comp[i] has 3 smallfelem of 4 u64 -> 12 elements
        u64 mask = i ^ idx;
        mask |= mask >> 4;
        mask |= mask >> 2;
        mask |= mask >> 1;
        mask &= 1;
        mask--;
        for (j = 0; j < 4 * 3; j++) {
            u64 indirect_index = (j * 3 + i) % (4 * 3); // Strided access pattern with modulo to stay in bounds
            outlimbs[indirect_index] |= ((u64 *)&pre_comp[0][0][0])[base_index + j] & mask;
        }
    }
}
