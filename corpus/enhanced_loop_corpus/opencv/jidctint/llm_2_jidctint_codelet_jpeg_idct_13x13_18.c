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
extern JLONG tmp26;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 8; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Variant 1: Change memory access pattern to consecutive array indexing using local offsets
    // Instead of scaling index by 8 each time, pre-compute base pointers and use sequential access
    JCOEFPTR in_base = inptr;
    ISLOW_MULT_TYPE *quant_base = quantptr;
    int *ws_base = wsptr;

    z1 = (((ISLOW_MULT_TYPE)(in_base[0])) * (quant_base[0]));
    z1 = ((JLONG)((unsigned long)(z1) << (13)));
    z1 += ((JLONG)1) << (13 - 1 - 1);
    z2 = (((ISLOW_MULT_TYPE)(in_base[2])) * (quant_base[2]));
    z3 = (((ISLOW_MULT_TYPE)(in_base[4])) * (quant_base[4]));
    z4 = (((ISLOW_MULT_TYPE)(in_base[6])) * (quant_base[6]));
    tmp10 = z3 + z4;
    tmp11 = z3 - z4;
    tmp12 = ((tmp10) * (((JLONG)((1.155388986) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.096834933999999998) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp20 = ((z2) * (((JLONG)((1.373119086) * (((JLONG)1) << 13) + 0.5)))) + tmp12 + tmp13;
    tmp22 = ((z2) * (((JLONG)((0.50148704099999997) * (((JLONG)1) << 13) + 0.5)))) - tmp12 + tmp13;
    tmp12 = ((tmp10) * (((JLONG)((0.31645013100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.48691473899999999) * (((JLONG)1) << 13) + 0.5)))) + z1;
    tmp21 = ((z2) * (((JLONG)((1.0585540520000001) * (((JLONG)1) << 13) + 0.5)))) - tmp12 + tmp13;
    tmp25 = ((z2) * (-((JLONG)((1.25222392) * (((JLONG)1) << 13) + 0.5)))) + tmp12 + tmp13;
    tmp12 = ((tmp10) * (((JLONG)((0.435816023) * (((JLONG)1) << 13) + 0.5))));
    tmp13 = ((tmp11) * (((JLONG)((0.93730306399999996) * (((JLONG)1) << 13) + 0.5)))) - z1;
    tmp23 = ((z2) * (-((JLONG)((0.17046460799999999) * (((JLONG)1) << 13) + 0.5)))) - tmp12 - tmp13;
    tmp24 = ((z2) * (-((JLONG)((0.80336486900000004) * (((JLONG)1) << 13) + 0.5)))) + tmp12 - tmp13;
    tmp26 = ((tmp11 - z2) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5)))) + z1;
    z1 = (((ISLOW_MULT_TYPE)(in_base[1])) * (quant_base[1]));
    z2 = (((ISLOW_MULT_TYPE)(in_base[3])) * (quant_base[3]));
    z3 = (((ISLOW_MULT_TYPE)(in_base[5])) * (quant_base[5]));
    z4 = (((ISLOW_MULT_TYPE)(in_base[7])) * (quant_base[7]));
    tmp11 = ((z1 + z2) * (((JLONG)((1.3223126510000001) * (((JLONG)1) << 13) + 0.5))));
    tmp12 = ((z1 + z3) * (((JLONG)((1.1638749450000001) * (((JLONG)1) << 13) + 0.5))));
    tmp15 = z1 + z4;
    tmp13 = ((tmp15) * (((JLONG)((0.93779705700000004) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((2.0200822999999999) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z2 + z3) * (-((JLONG)((0.33844345799999997) * (((JLONG)1) << 13) + 0.5))));
    tmp11 += tmp14 + ((z2) * (((JLONG)((0.83722356399999998) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp14 - ((z3) * (((JLONG)((1.5721160270000001) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z2 + z4) * (-((JLONG)((1.1638749450000001) * (((JLONG)1) << 13) + 0.5))));
    tmp11 += tmp14;
    tmp13 += tmp14 + ((z4) * (((JLONG)((2.205608352) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = ((z3 + z4) * (-((JLONG)((0.65721781300000004) * (((JLONG)1) << 13) + 0.5))));
    tmp12 += tmp14;
    tmp13 += tmp14;
    tmp15 = ((tmp15) * (((JLONG)((0.33844345799999997) * (((JLONG)1) << 13) + 0.5))));
    tmp14 = tmp15 + ((z1) * (((JLONG)((0.31877435500000001) * (((JLONG)1) << 13) + 0.5)))) - ((z2) * (((JLONG)((0.466105296) * (((JLONG)1) << 13) + 0.5))));
    z1 = ((z3 - z2) * (((JLONG)((0.93779705700000004) * (((JLONG)1) << 13) + 0.5))));
    tmp14 += z1;
    tmp15 += z1 + ((z3) * (((JLONG)((0.38451559499999999) * (((JLONG)1) << 13) + 0.5)))) - ((z4) * (((JLONG)((1.7423458110000001) * (((JLONG)1) << 13) + 0.5))));
    
    // Write outputs with direct offset arithmetic but now using base pointer for clarity
    ws_base[0] = (int)((tmp20 + tmp10) >> (13 - 1));
    ws_base[12*8] = (int)((tmp20 - tmp10) >> (13 - 1));
    ws_base[1*8] = (int)((tmp21 + tmp11) >> (13 - 1));
    ws_base[11*8] = (int)((tmp21 - tmp11) >> (13 - 1));
    ws_base[2*8] = (int)((tmp22 + tmp12) >> (13 - 1));
    ws_base[10*8] = (int)((tmp22 - tmp12) >> (13 - 1));
    ws_base[3*8] = (int)((tmp23 + tmp13) >> (13 - 1));
    ws_base[9*8] = (int)((tmp23 - tmp13) >> (13 - 1));
    ws_base[4*8] = (int)((tmp24 + tmp14) >> (13 - 1));
    ws_base[8*8] = (int)((tmp24 - tmp14) >> (13 - 1));
    ws_base[5*8] = (int)((tmp25 + tmp15) >> (13 - 1));
    ws_base[7*8] = (int)((tmp25 - tmp15) >> (13 - 1));
    ws_base[6*8] = (int)((tmp26) >> (13 - 1));
}
}
