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
for (ctx = 0; ctx < 2; ctx++) {
    int p[6]; // Reduced array size
    for (type = 0; type < 6; type++) {
        p[type] = 50 * model->mb_types_stats[ctx][type][1];
    }
    for (type = 0; type < 6; type++) {
        int p02 = p[0] + p[2];
        int p13 = p[1] + p[3];
        int p45 = p[4] + p[5];
        int p0245 = p02 + p45;
        int p_total = p0245 + p13;
        model->mb_type[ctx][type][0] = 128 - (128 * model->mb_types_stats[ctx][type][0]) / (1 + p_total);
        model->mb_type[ctx][type][1] = 1 + 127 * p0245 / (1 + p_total);
        model->mb_type[ctx][type][2] = 1 + 127 * p02 / (1 + p0245);
        model->mb_type[ctx][type][3] = 1 + 127 * p[0] / (1 + p02);
        model->mb_type[ctx][type][4] = 1 + 127 * p[4] / (1 + p45);
        model->mb_type[ctx][type][5] = 1 + 127 * p13 / (1 + p_total);
        p[type] = 50 * model->mb_types_stats[ctx][type][1];
    }
}
}
