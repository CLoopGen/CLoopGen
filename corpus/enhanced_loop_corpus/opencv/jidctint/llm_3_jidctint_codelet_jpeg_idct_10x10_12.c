#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG tmp14;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index lookup table to access array elements indirectly.
    // This simulates scenarios with non-regular or data-dependent access patterns.
    // The indices represent the same logical offsets but accessed through indirection.

    static const int idx[] = {0,1,2,3,4,5,6,7}; // Logical indices (could be randomized or reordered in real use)
    JCOEFPTR inptr_base = inptr;
    ISLOW_MULT_TYPE *quantptr_base = quantptr;
    int *wsptr_base = wsptr;

    for (ctr = 0; ctr < 8; ctr++) {
        int i0 = idx[0], i1 = idx[1], i2 = idx[2], i3 = idx[3];
        int i4 = idx[4], i5 = idx[5], i6 = idx[6], i7 = idx[7];

        z3 = (((ISLOW_MULT_TYPE)(inptr_base[i0 * 8])) * (quantptr_base[i0 * 8]));
        z3 = ((JLONG)((unsigned long)(z3) << (13)));
        z3 += ((JLONG)1) << (13 - 1 - 1);
        z4 = (((ISLOW_MULT_TYPE)(inptr_base[i4 * 8])) * (quantptr_base[i4 * 8]));
        z1 = ((z4) * (((JLONG)((1.1441228059999999) * (((JLONG)1) << 13) + 0.5))));
        z2 = ((z4) * (((JLONG)((0.437016024) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = z3 + z1;
        tmp11 = z3 - z2;
        tmp22 = ((z3 - ((JLONG)((unsigned long)(z1 - z2) << (1)))) >> (13 - 1));
        z2 = (((ISLOW_MULT_TYPE)(inptr_base[i2 * 8])) * (quantptr_base[i2 * 8]));
        z3 = (((ISLOW_MULT_TYPE)(inptr_base[i6 * 8])) * (quantptr_base[i6 * 8]));
        z1 = ((z2 + z3) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = z1 + ((z2) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = z1 - ((z3) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));
        tmp20 = tmp10 + tmp12;
        tmp24 = tmp10 - tmp12;
        tmp21 = tmp11 + tmp13;
        tmp23 = tmp11 - tmp13;
        z1 = (((ISLOW_MULT_TYPE)(inptr_base[i1 * 8])) * (quantptr_base[i1 * 8]));
        z2 = (((ISLOW_MULT_TYPE)(inptr_base[i3 * 8])) * (quantptr_base[i3 * 8]));
        z3 = (((ISLOW_MULT_TYPE)(inptr_base[i5 * 8])) * (quantptr_base[i5 * 8]));
        z4 = (((ISLOW_MULT_TYPE)(inptr_base[i7 * 8])) * (quantptr_base[i7 * 8]));
        tmp11 = z2 + z4;
        tmp13 = z2 - z4;
        tmp12 = ((tmp13) * (((JLONG)((0.30901699399999999) * (((JLONG)1) << 13) + 0.5))));
        z5 = ((JLONG)((unsigned long)(z3) << (13)));
        z2 = ((tmp11) * (((JLONG)((0.95105651599999996) * (((JLONG)1) << 13) + 0.5))));
        z4 = z5 + tmp12;
        tmp10 = ((z1) * (((JLONG)((1.3968022470000001) * (((JLONG)1) << 13) + 0.5)))) + z2 + z4;
        tmp14 = ((z1) * (((JLONG)((0.22123174200000001) * (((JLONG)1) << 13) + 0.5)))) - z2 + z4;
        z2 = ((tmp11) * (((JLONG)((0.58778525199999998) * (((JLONG)1) << 13) + 0.5))));
        z4 = z5 - tmp12 - ((JLONG)((unsigned long)(tmp13) << (13 - 1)));
        tmp12 = ((JLONG)((unsigned long)(z1 - tmp13 - z3) << (1)));
        tmp11 = ((z1) * (((JLONG)((1.2600735110000001) * (((JLONG)1) << 13) + 0.5)))) - z2 - z4;
        tmp13 = ((z1) * (((JLONG)((0.64203952200000003) * (((JLONG)1) << 13) + 0.5)))) - z2 + z4;

        wsptr_base[i0 * 8 + 0] = (int)((tmp20 + tmp10) >> (13 - 1));
        wsptr_base[i0 * 8 + 9] = (int)((tmp20 - tmp10) >> (13 - 1));
        wsptr_base[i1 * 8 + 1] = (int)((tmp21 + tmp11) >> (13 - 1));
        wsptr_base[i1 * 8 + 8] = (int)((tmp21 - tmp11) >> (13 - 1));
        wsptr_base[i2 * 8 + 2] = (int)(tmp22 + tmp12);
        wsptr_base[i2 * 8 + 7] = (int)(tmp22 - tmp12);
        wsptr_base[i3 * 8 + 3] = (int)((tmp23 + tmp13) >> (13 - 1));
        wsptr_base[i3 * 8 + 6] = (int)((tmp23 - tmp13) >> (13 - 1));
        wsptr_base[i4 * 8 + 4] = (int)((tmp24 + tmp14) >> (13 - 1));
        wsptr_base[i4 * 8 + 5] = (int)((tmp24 - tmp14) >> (13 - 1));

        inptr_base++;
        quantptr_base++;
        wsptr_base++;
    }
}
