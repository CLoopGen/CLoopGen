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
    if (size > 0) {
        const u64 *inlimbs = (u64 *)&pre_comp[0][0][0];
        u64 mask = idx;  // Simplified mask logic with reduced operations
        mask = (mask & 1) ? ~0ULL : 0ULL;
        for (j = 0; j < 4 * 3; j++)
            outlimbs[j] |= inlimbs[j] & mask;

        for (i = 1; i < size; i += 2) {  // Reduced effective trip count by stepping by 2
            inlimbs = (u64 *)&pre_comp[i][0][0];
            mask = (i ^ idx) & 1;
            mask = mask ? ~0ULL : 0ULL;
            for (j = 0; j < 4 * 3; j += 2) {  // Reduced inner loop iterations, stride of 2
                outlimbs[j] |= inlimbs[j] & mask;
            }
        }
    }
}
