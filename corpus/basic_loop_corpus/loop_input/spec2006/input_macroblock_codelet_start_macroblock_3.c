#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int64_t int64;

typedef struct macroblock {
    int currSEnr;
    int slice_nr;
    int delta_qp;
    int qp;
    int qpsp;
    int bitcounter[8];
    struct macroblock *mb_available_up;
    struct macroblock *mb_available_left;
    int mb_type;
    int mvd[2][4][4][2];
    int intra_pred_modes[16];
    int intra_pred_modes8x8[16];
    int cbp;
    int64 cbp_blk;
    int b8mode[4];
    int b8pdir[4];
    unsigned long cbp_bits;
    int lf_disable;
    int lf_alpha_c0_offset;
    int lf_beta_offset;
    int c_ipred_mode;
    int IntraChromaPredModeFlag;
    int mb_field;
    int mbAddrA;
    int mbAddrB;
    int mbAddrC;
    int mbAddrD;
    int mbAvailA;
    int mbAvailB;
    int mbAvailC;
    int mbAvailD;
    int all_blk_8x8;
    int luma_transform_size_8x8_flag;
    int NoMbPartLessThan8x8Flag;
    int bi_pred_me;
    double actj;
    int prev_qp;
    int prev_delta_qp;
    int prev_cbp;
    int predict_qp;
    int predict_error;
    int LFDisableIdc;
    int LFAlphaC0Offset;
    int LFBetaOffset;
    int skip_flag;
} Macroblock;

int i;
int j;
int k;
int l;
Macroblock *currMB;

void init_vars() {
    currMB = (Macroblock*)calloc(1, sizeof(Macroblock));
    if (!currMB) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    currMB->mb_available_up = NULL;
    currMB->mb_available_left = NULL;

    for (int idx = 0; idx < 8; ++idx) {
        currMB->bitcounter[idx] = 0;
    }

    for (int a = 0; a < 2; ++a)
        for (int b = 0; b < 4; ++b)
            for (int c = 0; c < 4; ++c)
                for (int d = 0; d < 2; ++d)
                    currMB->mvd[a][b][c][d] = 0;

    for (int idx = 0; idx < 16; ++idx) {
        currMB->intra_pred_modes[idx] = 0;
        currMB->intra_pred_modes8x8[idx] = 0;
    }

    for (int idx = 0; idx < 4; ++idx) {
        currMB->b8mode[idx] = 0;
        currMB->b8pdir[idx] = 0;
    }

    currMB->currSEnr = 0;
    currMB->slice_nr = 0;
    currMB->delta_qp = 0;
    currMB->qp = 0;
    currMB->qpsp = 0;
    currMB->mb_type = 0;
    currMB->cbp = 0;
    currMB->cbp_blk = 0;
    currMB->cbp_bits = 0;
    currMB->lf_disable = 0;
    currMB->lf_alpha_c0_offset = 0;
    currMB->lf_beta_offset = 0;
    currMB->c_ipred_mode = 0;
    currMB->IntraChromaPredModeFlag = 0;
    currMB->mb_field = 0;
    currMB->mbAddrA = 0;
    currMB->mbAddrB = 0;
    currMB->mbAddrC = 0;
    currMB->mbAddrD = 0;
    currMB->mbAvailA = 0;
    currMB->mbAvailB = 0;
    currMB->mbAvailC = 0;
    currMB->mbAvailD = 0;
    currMB->all_blk_8x8 = 0;
    currMB->luma_transform_size_8x8_flag = 0;
    currMB->NoMbPartLessThan8x8Flag = 0;
    currMB->bi_pred_me = 0;
    currMB->actj = 0.0;
    currMB->prev_qp = 0;
    currMB->prev_delta_qp = 0;
    currMB->prev_cbp = 0;
    currMB->predict_qp = 0;
    currMB->predict_error = 0;
    currMB->LFDisableIdc = 0;
    currMB->LFAlphaC0Offset = 0;
    currMB->LFBetaOffset = 0;
    currMB->skip_flag = 0;
}