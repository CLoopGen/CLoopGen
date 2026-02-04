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
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 2: Strided and indirect memory access using index remapping table
const int index_map[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reorder access: even indices first, then odd
for (ctr = 0; ctr < 6; ctr++, inptr++, quantptr++, wsptr += 12) {
    JCOEFPTR base_in = inptr;
    ISLOW_MULT_TYPE *base_quant = quantptr;

    // Indirect and strided access through mapping
    z3 = (((ISLOW_MULT_TYPE)(base_in[index_map[0] * 8])) * (base_quant[index_map[0] * 8]));
    z3 <<= 13;
    z3 += ((INT32)1) << (13 - 2 - 1);
    z4 = (((ISLOW_MULT_TYPE)(base_in[index_map[2] * 8])) * (base_quant[index_map[2] * 8]));
    z4 = ((z4) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    tmp10 = z3 + z4;
    tmp11 = z3 - z4;

    z1 = (((ISLOW_MULT_TYPE)(base_in[index_map[1] * 8])) * (base_quant[index_map[1] * 8]));
    z4 = ((z1) * (((INT32)((1.3660254039999999) * (((INT32)1) << 13) + 0.5))));
    z1 <<= 13;

    z2 = (((ISLOW_MULT_TYPE)(base_in[index_map[3] * 8])) * (base_quant[index_map[3] * 8]));
    z2 <<= 13;

    tmp12 = z1 - z2;
    tmp21 = z3 + tmp12;
    tmp24 = z3 - tmp12;
    tmp12 = z4 + z2;
    tmp20 = tmp10 + tmp12;
    tmp25 = tmp10 - tmp12;
    tmp12 = z4 - z1 - z2;
    tmp22 = tmp11 + tmp12;
    tmp23 = tmp11 - tmp12;

    z1 = (((ISLOW_MULT_TYPE)(base_in[index_map[4] * 8])) * (base_quant[index_map[4] * 8]));
    z2 = (((ISLOW_MULT_TYPE)(base_in[index_map[5] * 8])) * (base_quant[index_map[5] * 8]));
    z3 = (((ISLOW_MULT_TYPE)(base_in[index_map[6] * 8])) * (base_quant[index_map[6] * 8]));
    z4 = (((ISLOW_MULT_TYPE)(base_in[index_map[7] * 8])) * (base_quant[index_map[7] * 8]));

    tmp11 = ((z2) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
    tmp14 = ((z2) * (-((INT32)4433)));

    tmp10 = z1 + z3;
    tmp15 = ((tmp10 + z4) * (((INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5))));
    tmp12 = tmp15 + ((tmp10) * (((INT32)((0.26105238400000003) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp12 + tmp11 + ((z1) * (((INT32)((0.28014371599999999) * (((INT32)1) << 13) + 0.5))));

    tmp13 = ((z3 + z4) * (-((INT32)((1.04551058) * (((INT32)1) << 13) + 0.5))));
    tmp12 += tmp13 + tmp14 - ((z3) * (((INT32)((1.478575242) * (((INT32)1) << 13) + 0.5))));
    tmp13 += tmp15 - tmp11 + ((z4) * (((INT32)((1.5867066809999999) * (((INT32)1) << 13) + 0.5))));
    tmp15 += tmp14 - ((z1) * (((INT32)((0.67632675799999997) * (((INT32)1) << 13) + 0.5)))) - ((z4) * (((INT32)((1.982889723) * (((INT32)1) << 13) + 0.5))));

    z1 -= z4;
    z2 -= z3;
    z3 = ((z1 + z2) * (((INT32)4433)));
    tmp11 = z3 + ((z1) * (((INT32)6270)));
    tmp14 = z3 - ((z2) * (((INT32)15137)));

    // Write results with non-unit stride in output
    wsptr[0]  = (int)((tmp20 + tmp10) >> (13 - 2));
    wsptr[11] = (int)((tmp20 - tmp10) >> (13 - 2));
    wsptr[1]  = (int)((tmp21 + tmp11) >> (13 - 2));
    wsptr[10] = (int)((tmp21 - tmp11) >> (13 - 2));
    wsptr[2]  = (int)((tmp22 + tmp12) >> (13 - 2));
    wsptr[9]  = (int)((tmp22 - tmp12) >> (13 - 2));
    wsptr[3]  = (int)((tmp23 + tmp13) >> (13 - 2));
    wsptr[8]  = (int)((tmp23 - tmp13) >> (13 - 2));
    wsptr[4]  = (int)((tmp24 + tmp14) >> (13 - 2));
    wsptr[7]  = (int)((tmp24 - tmp14) >> (13 - 2));
    wsptr[5]  = (int)((tmp25 + tmp15) >> (13 - 2));
    wsptr[6]  = (int)((tmp25 - tmp15) >> (13 - 2));
}
}
