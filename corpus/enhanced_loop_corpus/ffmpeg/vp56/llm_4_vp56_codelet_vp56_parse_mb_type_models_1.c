#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VP56Model {
    uint8_t coeff_reorder[64];
    uint8_t coeff_index_to_pos[64];
    uint8_t coeff_index_to_idct_selector[64];
    uint8_t vector_sig[2];
    uint8_t vector_dct[2];
    uint8_t vector_pdi[2][2];
    uint8_t vector_pdv[2][7];
    uint8_t vector_fdv[2][8];
    uint8_t coeff_dccv[2][11];
    uint8_t coeff_ract[2][3][6][11];
    uint8_t coeff_acct[2][3][3][6][5];
    uint8_t coeff_dcct[2][36][5];
    uint8_t coeff_runv[2][14];
    uint8_t mb_type[3][10][10];
    uint8_t mb_types_stats[3][10][2];
} VP56Model;

extern VP56Model *model;
extern int ctx;
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctx = 0; ctx < 3; ctx++) {
    int p[10];
    for (type = 0; type < 10; type++) {
        p[type] = 100 * model->mb_types_stats[ctx][type][1];
    }
    for (type = 0; type < 10; type++) {
        int p02, p34, p0234, p17, p56, p89, p5689, p156789;
        model->mb_type[ctx][type][0] = 255 - (255 * model->mb_types_stats[ctx][type][0]) / (1 + model->mb_types_stats[ctx][type][0] + model->mb_types_stats[ctx][type][1]);
        
        if (model->mb_type[ctx][type][0] > 128) {
            p[type] = 0;
        } else {
            p[type] = 50 * model->mb_types_stats[ctx][type][1];
        }

        p02 = p[0] + p[2];
        p34 = p[3] + p[4];
        p0234 = p02 + p34;
        p17 = p[1] + p[7];
        p56 = p[5] + p[6];
        p89 = p[8] + p[9];
        p5689 = p56 + p89;
        p156789 = p17 + p5689;

        model->mb_type[ctx][type][1] = 1 + 255 * p0234 / (1 + p0234 + p156789);
        model->mb_type[ctx][type][2] = 1 + 255 * p02 / (1 + p0234);

        if (p156789 > 0) {
            model->mb_type[ctx][type][3] = 1 + 255 * p17 / (1 + p156789);
        } else {
            model->mb_type[ctx][type][3] = 1;
        }

        model->mb_type[ctx][type][4] = 1 + 255 * p[0] / (1 + (p[0] + p[2]));
        model->mb_type[ctx][type][5] = 1 + 255 * p[3] / (1 + p34);
        model->mb_type[ctx][type][6] = 1 + 255 * p[1] / (1 + p17);
        model->mb_type[ctx][type][7] = 1 + 255 * p56 / (1 + p5689);

        if (p56 > 0) {
            model->mb_type[ctx][type][8] = 1 + 255 * p[5] / (1 + p56);
        } else {
            model->mb_type[ctx][type][8] = 1;
        }

        model->mb_type[ctx][type][9] = 1 + 255 * p[8] / (1 + p89);
        p[type] = 100 * model->mb_types_stats[ctx][type][1];
    }
}
}
