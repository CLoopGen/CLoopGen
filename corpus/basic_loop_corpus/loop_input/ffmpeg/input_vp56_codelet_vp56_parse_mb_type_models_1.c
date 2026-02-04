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

VP56Model *model;
int ctx;
int type;

void init_vars() {
    model = (VP56Model*)calloc(1, sizeof(VP56Model));
    if (!model) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int ctx_idx = 0; ctx_idx < 3; ctx_idx++) {
        for (int type_idx = 0; type_idx < 10; type_idx++) {
            model->mb_types_stats[ctx_idx][type_idx][0] = (uint8_t)((ctx_idx * 10 + type_idx + 1) % 97);
            model->mb_types_stats[ctx_idx][type_idx][1] = (uint8_t)((ctx_idx * 10 + type_idx + 31) % 89);
            for (int i = 0; i < 10; i++) {
                model->mb_type[ctx_idx][type_idx][i] = 0;
            }
        }
    }
}