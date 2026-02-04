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
extern JLONG tmp15;
extern JLONG tmp20;
extern JLONG tmp21;
extern JLONG tmp22;
extern JLONG tmp23;
extern JLONG tmp24;
extern JLONG tmp25;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (8 * i), reorganize data to be accessed consecutively
    // Assume input data has been pre-reorganized into arrays with consecutive layout
    // This variant assumes inptr, quantptr are now accessed as linear arrays

    JCOEFPTR in_base = inptr - 8 * ctr;        // Base pointer to start of block
    ISLOW_MULT_TYPE *quant_base = quantptr - 8 * ctr;
    int *ws_base = wsptr - 8 * ctr;

    for (ctr = 0; ctr < 8; ctr++) {
        z3 = (((ISLOW_MULT_TYPE)(in_base[0])) * (quant_base[0]));
        z3 = ((JLONG)((unsigned long)(z3) << 13));
        z3 += ((JLONG)1) << (13 - 1 - 1);
        z4 = (((ISLOW_MULT_TYPE)(in_base[4])) * (quant_base[4]));
        z4 = ((z4) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = z3 + z4;
        tmp11 = z3 - z4;
        z1 = (((ISLOW_MULT_TYPE)(in_base[2])) * (quant_base[2]));
        z4 = ((z1) * (((JLONG)((1.3660254039999999) * (((JLONG)1) << 13) + 0.5))));
        z1 = ((JLONG)((unsigned long)(z1) << 13));
        z2 = (((ISLOW_MULT_TYPE)(in_base[6])) * (quant_base[6]));
        z2 = ((JLONG)((unsigned long)(z2) << 13));
        tmp12 = z1 - z2;
        tmp21 = z3 + tmp12;
        tmp24 = z3 - tmp12;
        tmp12 = z4 + z2;
        tmp20 = tmp10 + tmp12;
        tmp25 = tmp10 - tmp12;
        tmp12 = z4 - z1 - z2;
        tmp22 = tmp11 + tmp12;
        tmp23 = tmp11 - tmp12;
        z1 = (((ISLOW_MULT_TYPE)(in_base[1])) * (quant_base[1]));
        z2 = (((ISLOW_MULT_TYPE)(in_base[3])) * (quant_base[3]));
        z3 = (((ISLOW_MULT_TYPE)(in_base[5])) * (quant_base[5]));
        z4 = (((ISLOW_MULT_TYPE)(in_base[7])) * (quant_base[7]));
        tmp11 = ((z2) * (((JLONG)((1.3065629649999999) * (((JLONG)1) << 13) + 0.5))));
        tmp14 = ((z2) * (-((JLONG)4433)));
        tmp10 = z1 + z3;
        tmp15 = ((tmp10 + z4) * (((JLONG)((0.86091866900000003) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = tmp15 + ((tmp10) * (((JLONG)((0.26105238400000003) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = tmp12 + tmp11 + ((z1) * (((JLONG)((0.28014371599999999) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = ((z3 + z4) * (-((JLONG)((1.04551058) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += tmp13 + tmp14 - ((z3) * (((JLONG)((1.478575242) * (((JLONG)1) << 13) + 0.5))));
        tmp13 += tmp15 - tmp11 + ((z4) * (((JLONG)((1.5867066809999999) * (((JLONG)1) << 13) + 0.5))));
        tmp15 += tmp14 - ((z1) * (((JLONG)((0.67632675799999997) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.982889723) * (((JLONG)1) << 13) + 0.5))));
        z1 -= z4;
        z2 -= z3;
        z3 = ((z1 + z2) * (((JLONG)4433)));
        tmp11 = z3 + ((z1) * (((JLONG)6270)));
        tmp14 = z3 - ((z2) * (((JLONG)15137)));
        ws_base[0]      = (int)((tmp20 + tmp10) >> (13 - 1));
        ws_base[11]     = (int)((tmp20 - tmp10) >> (13 - 1));
        ws_base[1]      = (int)((tmp21 + tmp11) >> (13 - 1));
        ws_base[10]     = (int)((tmp21 - tmp11) >> (13 - 1));
        ws_base[2]      = (int)((tmp22 + tmp12) >> (13 - 1));
        ws_base[9]      = (int)((tmp22 - tmp12) >> (13 - 1));
        ws_base[3]      = (int)((tmp23 + tmp13) >> (13 - 1));
        ws_base[8]      = (int)((tmp23 - tmp13) >> (13 - 1));
        ws_base[4]      = (int)((tmp24 + tmp14) >> (13 - 1));
        ws_base[7]      = (int)((tmp24 - tmp14) >> (13 - 1));
        ws_base[5]      = (int)((tmp25 + tmp15) >> (13 - 1));
        ws_base[6]      = (int)((tmp25 - tmp15) >> (13 - 1));

        in_base += 8;
        quant_base += 8;
        ws_base += 8;
    }
}
