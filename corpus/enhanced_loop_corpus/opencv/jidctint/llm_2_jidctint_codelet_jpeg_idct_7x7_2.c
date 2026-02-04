#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Array Index Rewriting
    // Instead of strided access (8 * i), we assume input data is pre-reorganized into separate arrays
    // for even and odd indices to enable sequential memory access, improving cache locality.
    
    JCOEFPTR even_inptr = inptr;           // Points to inptr[0], inptr[2], inptr[4], ...
    ISLOW_MULT_TYPE *even_quantptr = quantptr;
    int *wsptr_local = wsptr;

    for (ctr = 0; ctr < 7; ctr++) {
        tmp13 = (((ISLOW_MULT_TYPE)(even_inptr[0])) * (even_quantptr[0]));
        tmp13 = ((JLONG)((unsigned long)(tmp13) << 13));
        tmp13 += ((JLONG)1) << (13 - 1 - 1);

        z1 = (((ISLOW_MULT_TYPE)(even_inptr[1])) * (even_quantptr[1])); // inptr[2] -> [1] in even
        z2 = (((ISLOW_MULT_TYPE)(even_inptr[2])) * (even_quantptr[2])); // inptr[4]
        z3 = (((ISLOW_MULT_TYPE)(even_inptr[3])) * (even_quantptr[3])); // inptr[6]

        tmp10 = ((z2 - z3) * (((JLONG)((0.88174773399999995) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((JLONG)((0.31469212299999999) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = tmp10 + tmp12 + tmp13 - ((z2) * (((JLONG)((1.841218003) * (((JLONG)1) << 13) + 0.5))));

        tmp0 = z1 + z3;
        z2 -= tmp0;
        tmp0 = ((tmp0) * (((JLONG)((1.274162392) * (((JLONG)1) << 13) + 0.5)))) + tmp13;

        tmp10 += tmp0 - ((z3) * (((JLONG)((0.077722535999999995) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += tmp0 - ((z1) * (((JLONG)((2.4706022490000001) * (((JLONG)1) << 13) + 0.5))));
        tmp13 += ((z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));

        // Now process odd indices sequentially from a separate block
        JCOEFPTR odd_inptr = inptr + 1 + ctr * 8;           // Base offset for odd inputs: 1, 3, 5 per row
        ISLOW_MULT_TYPE *odd_quantptr = quantptr + 1 + ctr * 8;

        z1 = (((ISLOW_MULT_TYPE)(odd_inptr[0 * 8])) * (odd_quantptr[0 * 8])); // inptr[1]
        z2 = (((ISLOW_MULT_TYPE)(odd_inptr[2 * 8])) * (odd_quantptr[2 * 8])); // inptr[3]
        z3 = (((ISLOW_MULT_TYPE)(odd_inptr[4 * 8])) * (odd_quantptr[4 * 8])); // inptr[5]

        tmp1 = ((z1 + z2) * (((JLONG)((0.93541434700000003) * (((JLONG)1) << 13) + 0.5))));
        tmp2 = ((z1 - z2) * (((JLONG)((0.17026233900000001) * (((JLONG)1) << 13) + 0.5))));
        tmp0 = tmp1 - tmp2;
        tmp1 += tmp2;

        tmp2 = ((z2 + z3) * (-((JLONG)((1.3787562760000001) * (((JLONG)1) << 13) + 0.5))));
        tmp1 += tmp2;

        z2 = ((z1 + z3) * (((JLONG)((0.61360426800000001) * (((JLONG)1) << 13) + 0.5))));
        tmp0 += z2;
        tmp2 += z2 + ((z3) * (((JLONG)((1.870828693) * (((JLONG)1) << 13) + 0.5))));

        wsptr_local[0] = (int)((tmp10 + tmp0) >> (13 - 1));
        wsptr_local[6] = (int)((tmp10 - tmp0) >> (13 - 1));
        wsptr_local[1] = (int)((tmp11 + tmp1) >> (13 - 1));
        wsptr_local[5] = (int)((tmp11 - tmp1) >> (13 - 1));
        wsptr_local[2] = (int)((tmp12 + tmp2) >> (13 - 1));
        wsptr_local[4] = (int)((tmp12 - tmp2) >> (13 - 1));
        wsptr_local[3] = (int)((tmp13) >> (13 - 1));

        // Move pointers forward for next iteration
        even_inptr += 8;
        even_quantptr += 8;
        wsptr_local += 7;
    }
}
