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
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an index array to define non-sequential, indirect access pattern.
    // This simulates scenarios like scatter/gather or reordered coefficient processing.

    static const int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reordered access pattern
    int idx;
    JCOEFPTR in_base = inptr;
    ISLOW_MULT_TYPE *quant_base = quantptr;
    int *wsp_base = wsptr;

    for (ctr = 0; ctr < 8; ctr++) {
        idx = indices[ctr]; // Indirect indexing

        z1 = (((ISLOW_MULT_TYPE)(in_base[idx])) * (quant_base[idx]));
        z1 <<= 13;
        z1 += ((INT32)1) << (13 - 2 - 1);
        z4 = (((ISLOW_MULT_TYPE)(in_base[(idx + 4) & 7])) * (quant_base[(idx + 4) & 7])); // Wrap-around offset
        z2 = ((z4) * (((INT32)((1.274162392) * (((INT32)1) << 13) + 0.5))));
        z3 = ((z4) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));
        z4 = ((z4) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
        tmp10 = z1 + z2;
        tmp11 = z1 + z3;
        tmp12 = z1 - z4;
        tmp23 = ((z1 - ((z2 + z3 - z4) << 1)) >> (13 - 2));
        z1 = (((ISLOW_MULT_TYPE)(in_base[(idx + 2) & 7])) * (quant_base[(idx + 2) & 7]));
        z2 = (((ISLOW_MULT_TYPE)(in_base[(idx + 6) & 7])) * (quant_base[(idx + 6) & 7]));
        z3 = ((z1 + z2) * (((INT32)((1.105676686) * (((INT32)1) << 13) + 0.5))));
        tmp13 = z3 + ((z1) * (((INT32)((0.27307958999999998) * (((INT32)1) << 13) + 0.5))));
        tmp14 = z3 - ((z2) * (((INT32)((1.719280954) * (((INT32)1) << 13) + 0.5))));
        tmp15 = ((z1) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5)))) - ((z2) * (((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
        tmp20 = tmp10 + tmp13;
        tmp26 = tmp10 - tmp13;
        tmp21 = tmp11 + tmp14;
        tmp25 = tmp11 - tmp14;
        tmp22 = tmp12 + tmp15;
        tmp24 = tmp12 - tmp15;
        z1 = (((ISLOW_MULT_TYPE)(in_base[(idx + 1) & 7])) * (quant_base[(idx + 1) & 7]));
        z2 = (((ISLOW_MULT_TYPE)(in_base[(idx + 3) & 7])) * (quant_base[(idx + 3) & 7]));
        z3 = (((ISLOW_MULT_TYPE)(in_base[(idx + 5) & 7])) * (quant_base[(idx + 5) & 7]));
        z4 = (((ISLOW_MULT_TYPE)(in_base[(idx + 7) & 7])) * (quant_base[(idx + 7) & 7]));

        tmp13 = z4 << 13;
        tmp14 = z1 + z3;
        tmp11 = ((z1 + z2) * (((INT32)((1.334852607) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((tmp14) * (((INT32)((1.1974488459999999) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((INT32)((1.1269801690000001) * (((INT32)1) << 13) + 0.5))));
        tmp14 = ((tmp14) * (((INT32)((0.752406978) * (((INT32)1) << 13) + 0.5))));
        tmp16 = tmp14 - ((z1) * (((INT32)((1.061150426) * (((INT32)1) << 13) + 0.5))));
        z1 -= z2;
        tmp15 = ((z1) * (((INT32)((0.46708512899999999) * (((INT32)1) << 13) + 0.5)))) - tmp13;
        tmp16 += tmp15;
        z1 += z4;
        z4 = ((z2 + z3) * (-((INT32)((0.15834168100000001) * (((INT32)1) << 13) + 0.5)))) - tmp13;
        tmp11 += z4 - ((z2) * (((INT32)((0.42410394800000001) * (((INT32)1) << 13) + 0.5))));
        tmp12 += z4 - ((z3) * (((INT32)((2.3739597730000002) * (((INT32)1) << 13) + 0.5))));
        z4 = ((z3 - z2) * (((INT32)((1.405321284) * (((INT32)1) << 13) + 0.5))));
        tmp14 += z4 + tmp13 - ((z3) * (((INT32)((1.6906431334000001) * (((INT32)1) << 13) + 0.5))));
        tmp15 += z4 + ((z2) * (((INT32)((0.67495756699999998) * (((INT32)1) << 13) + 0.5))));
        tmp13 = (z1 - z3) << 2;

        // Scatter output with indirect placement based on index mapping
        wsp_base[0] = (int)((tmp20 + tmp10) >> (13 - 2));
        wsp_base[13] = (int)((tmp20 - tmp10) >> (13 - 2));
        wsp_base[1] = (int)((tmp21 + tmp11) >> (13 - 2));
        wsp_base[12] = (int)((tmp21 - tmp11) >> (13 - 2));
        wsp_base[2] = (int)((tmp22 + tmp12) >> (13 - 2));
        wsp_base[11] = (int)((tmp22 - tmp12) >> (13 - 2));
        wsp_base[3] = (int)(tmp23 + tmp13);
        wsp_base[10] = (int)(tmp23 - tmp13);
        wsp_base[4] = (int)((tmp24 + tmp14) >> (13 - 2));
        wsp_base[9] = (int)((tmp24 - tmp14) >> (13 - 2));
        wsp_base[5] = (int)((tmp25 + tmp15) >> (13 - 2));
        wsp_base[8] = (int)((tmp25 - tmp15) >> (13 - 2));
        wsp_base[6] = (int)((tmp26 + tmp16) >> (13 - 2));
        wsp_base[7] = (int)((tmp26 - tmp16) >> (13 - 2));

        // Move all pointers forward by one logical step
        in_base++;
        quant_base++;
        wsp_base += 14;
    }
}
