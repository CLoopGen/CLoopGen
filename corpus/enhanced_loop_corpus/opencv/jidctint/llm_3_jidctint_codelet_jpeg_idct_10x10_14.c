#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with indirect memory access using index arrays to simulate non-regular or runtime-determined access patterns
// This models scenarios like sparse transforms or permuted coefficient processing

// Predefined index map — could be dynamic in real use cases
static const int read_idx[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reordering: even indices first, then odd
static const int write_idx[10] = {0, 8, 1, 9, 2, 7, 3, 6, 4, 5}; // Custom output permutation

for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[0]])) * (quantptr[8 * read_idx[0]]));
    z3 <<= 13;
    z3 += ((INT32)1) << (13 - 2 - 1);
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[4]])) * (quantptr[8 * read_idx[4]]));
    z1 = ((z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
    z2 = ((z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));
    tmp10 = z3 + z1;
    tmp11 = z3 - z2;
    tmp22 = ((z3 - ((z1 - z2) << 1)) >> (13 - 2));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[2]])) * (quantptr[8 * read_idx[2]]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[6]])) * (quantptr[8 * read_idx[6]]));
    z1 = ((z2 + z3) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    tmp12 = z1 + ((z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    tmp13 = z1 - ((z3) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));
    tmp20 = tmp10 + tmp12;
    tmp24 = tmp10 - tmp12;
    tmp21 = tmp11 + tmp13;
    tmp23 = tmp11 - tmp13;
    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[1]])) * (quantptr[8 * read_idx[1]]));
    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[3]])) * (quantptr[8 * read_idx[3]]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[5]])) * (quantptr[8 * read_idx[5]]));
    z4 = (((ISLOW_MULT_TYPE)(inptr[8 * read_idx[7]])) * (quantptr[8 * read_idx[7]]));
    tmp11 = z2 + z4;
    tmp13 = z2 - z4;
    tmp12 = ((tmp13) * (((INT32)((0.30901699399999999) * (((INT32)1) << 13) + 0.5))));
    z5 = z3 << 13;
    z2 = ((tmp11) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5))));
    z4 = z5 + tmp12;
    tmp10 = ((z1) * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) + z2 + z4;
    tmp14 = ((z1) * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5)))) - z2 + z4;
    z2 = ((tmp11) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5))));
    z4 = z5 - tmp12 - (tmp13 << (13 - 1));
    tmp12 = (z1 - tmp13 - z3) << 2;
    tmp11 = ((z1) * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) - z2 - z4;
    tmp13 = ((z1) * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) - z2 + z4;

    // Indirect writes using permuted index table
    wsptr[8 * write_idx[0]] = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[8 * write_idx[1]] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[8 * write_idx[2]] = (int)((tmp21 + tmp11) >> (13 - 2));
    wsptr[8 * write_idx[3]] = (int)((tmp21 - tmp11) >> (13 - 2));
    wsptr[8 * write_idx[4]] = (int)(tmp22 + tmp12);
    wsptr[8 * write_idx[5]] = (int)(tmp22 - tmp12);
    wsptr[8 * write_idx[6]] = (int)((tmp23 + tmp13) >> (13 - 2));
    wsptr[8 * write_idx[7]] = (int)((tmp23 - tmp13) >> (13 - 2));
    wsptr[8 * write_idx[8]] = (int)((tmp24 + tmp14) >> (13 - 2));
    wsptr[8 * write_idx[9]] = (int)((tmp24 - tmp14) >> (13 - 2));
}
}
