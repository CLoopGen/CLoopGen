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
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index map to simulate non-sequential, indirect access pattern
    // This models scenarios with gather/scatter patterns or permuted data layouts

    static const int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reordering for indirect access
    static const int out_map[11] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80}; // Stride 8 simulation via lookup

    JCOEFPTR base_in = inptr;
    ISLOW_MULT_TYPE *base_quant = quantptr;
    int *base_wsp = wsptr;

    for (ctr = 0; ctr < 8; ctr++, base_in++, base_quant++, base_wsp++) {
        int idx0 = indices[0], idx2 = indices[1], idx4 = indices[2], idx6 = indices[3];
        int idx1 = indices[4], idx3 = indices[5], idx5 = indices[6], idx7 = indices[7];

        tmp10 = (((ISLOW_MULT_TYPE)(base_in[idx0])) * (base_quant[idx0]));
        tmp10 = ((JLONG)((unsigned long)(tmp10) << (13)));
        tmp10 += ((JLONG)1) << (13 - 1 - 1);
        z1 = (((ISLOW_MULT_TYPE)(base_in[idx2])) * (base_quant[idx2]));
        z2 = (((ISLOW_MULT_TYPE)(base_in[idx4])) * (base_quant[idx4]));
        z3 = (((ISLOW_MULT_TYPE)(base_in[idx6])) * (base_quant[idx6]));
        tmp20 = ((z2 - z3) * (((JLONG)((2.5466401319999998) * (((JLONG)1) << 13) + 0.5))));
        tmp23 = ((z2 - z1) * (((JLONG)((0.43081504500000001) * (((JLONG)1) << 13) + 0.5))));
        z4 = z1 + z3;
        tmp24 = ((z4) * (-((JLONG)((1.155664402) * (((JLONG)1) << 13) + 0.5))));
        z4 -= z2;
        tmp25 = tmp10 + ((z4) * (((JLONG)((1.3569279759999999) * (((JLONG)1) << 13) + 0.5))));
        tmp21 = tmp20 + tmp23 + tmp25 - ((z2) * (((JLONG)((1.821790775) * (((JLONG)1) << 13) + 0.5))));
        tmp20 += tmp25 + ((z3) * (((JLONG)((2.1158250870000002) * (((JLONG)1) << 13) + 0.5))));
        tmp23 += tmp25 - ((z1) * (((JLONG)((1.5135984769999999) * (((JLONG)1) << 13) + 0.5))));
        tmp24 += tmp25;
        tmp22 = tmp24 - ((z3) * (((JLONG)((0.78874911999999997) * (((JLONG)1) << 13) + 0.5))));
        tmp24 += ((z2) * (((JLONG)((1.9444135220000001) * (((JLONG)1) << 13) + 0.5)))) - ((z1) * (((JLONG)((1.3909757300000001) * (((JLONG)1) << 13) + 0.5))));
        tmp25 = tmp10 - ((z4) * (((JLONG)((1.414213562) * (((JLONG)1) << 13) + 0.5))));

        z1 = (((ISLOW_MULT_TYPE)(base_in[idx1])) * (base_quant[idx1]));
        z2 = (((ISLOW_MULT_TYPE)(base_in[idx3])) * (base_quant[idx3]));
        z3 = (((ISLOW_MULT_TYPE)(base_in[idx5])) * (base_quant[idx5]));
        z4 = (((ISLOW_MULT_TYPE)(base_in[idx7])) * (base_quant[idx7]));

        tmp11 = z1 + z2;
        tmp14 = ((tmp11 + z3 + z4) * (((JLONG)((0.39843000299999998) * (((JLONG)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((JLONG)((0.88798390199999999) * (((JLONG)1) << 13) + 0.5))));
        tmp12 = ((z1 + z3) * (((JLONG)((0.67036129499999997) * (((JLONG)1) << 13) + 0.5))));
        tmp13 = tmp14 + ((z1 + z4) * (((JLONG)((0.36615157399999998) * (((JLONG)1) << 13) + 0.5))));
        tmp10 = tmp11 + tmp12 + tmp13 - ((z1) * (((JLONG)((0.92310786600000005) * (((JLONG)1) << 13) + 0.5))));
        z1 = tmp14 - ((z2 + z3) * (((JLONG)((1.163011579) * (((JLONG)1) << 13) + 0.5))));
        tmp11 += z1 + ((z2) * (((JLONG)((2.0732765880000001) * (((JLONG)1) << 13) + 0.5))));
        tmp12 += z1 - ((z3) * (((JLONG)((1.1921936230000001) * (((JLONG)1) << 13) + 0.5))));
        z1 = ((z2 + z4) * (-((JLONG)((1.7982489100000001) * (((JLONG)1) << 13) + 0.5))));
        tmp11 += z1;
        tmp13 += z1 + ((z4) * (((JLONG)((2.1024586319999998) * (((JLONG)1) << 13) + 0.5))));
        tmp14 += ((z2) * (-((JLONG)((1.4672213009999999) * (((JLONG)1) << 13) + 0.5)))) + 
                 ((z3) * (((JLONG)((1.001388905) * (((JLONG)1) << 13) + 0.5)))) - 
                 ((z4) * (((JLONG)((1.6848439070000001) * (((JLONG)1) << 13) + 0.5))));

        base_wsp[out_map[0] / 8]  = (int)((tmp20 + tmp10) >> (13 - 1));
        base_wsp[out_map[10] / 8] = (int)((tmp20 - tmp10) >> (13 - 1));
        base_wsp[out_map[1] / 8]  = (int)((tmp21 + tmp11) >> (13 - 1));
        base_wsp[out_map[9] / 8]  = (int)((tmp21 - tmp11) >> (13 - 1));
        base_wsp[out_map[2] / 8]  = (int)((tmp22 + tmp12) >> (13 - 1));
        base_wsp[out_map[8] / 8]  = (int)((tmp22 - tmp12) >> (13 - 1));
        base_wsp[out_map[3] / 8]  = (int)((tmp23 + tmp13) >> (13 - 1));
        base_wsp[out_map[7] / 8]  = (int)((tmp23 - tmp13) >> (13 - 1));
        base_wsp[out_map[4] / 8]  = (int)((tmp24 + tmp14) >> (13 - 1));
        base_wsp[out_map[6] / 8]  = (int)((tmp24 - tmp14) >> (13 - 1));
        base_wsp[out_map[5] / 8]  = (int)((tmp25) >> (13 - 1));
    }
}
