#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int64_t int64;

typedef struct {
    double min_rdcost;
    int rec_mbY[16][16];
    int rec_mbU[16][16];
    int rec_mbV[16][16];
    int ****cofAC;
    int ***cofDC;
    int mb_type;
    int bi_pred_me;
    int b8mode[4];
    int b8pdir[4];
    int **ipredmode;
    int intra_pred_modes[16];
    int cbp;
    int64 cbp_blk;
    int mode;
    short ******pred_mv;
    short ******all_mv;
    short ******bipred_mv1;
    short ******bipred_mv2;
    short refar[2][4][4];
    int i16offset;
    int c_ipred_mode;
    int luma_transform_size_8x8_flag;
    int NoMbPartLessThan8x8Flag;
    int qp;
    int prev_qp;
    int prev_delta_qp;
} RD_DATA;

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

RD_DATA *rdopt;
int i;
Macroblock *currMB;

void init_vars() {
    rdopt = (RD_DATA*)calloc(1, sizeof(RD_DATA));
    currMB = (Macroblock*)calloc(1, sizeof(Macroblock));

    for (int idx = 0; idx < 4; idx++) {
        currMB->b8mode[idx] = idx % 2;
        currMB->b8pdir[idx] = idx % 3;
    }

    rdopt->min_rdcost = 0.0;
    rdopt->mb_type = 0;
    rdopt->bi_pred_me = 0;
    rdopt->cbp = 0;
    rdopt->cbp_blk = 0;
    rdopt->mode = 0;
    rdopt->i16offset = 0;
    rdopt->c_ipred_mode = 0;
    rdopt->luma_transform_size_8x8_flag = 0;
    rdopt->NoMbPartLessThan8x8Flag = 1;
    rdopt->qp = 26;
    rdopt->prev_qp = 26;
    rdopt->prev_delta_qp = 0;

    currMB->currSEnr = 0;
    currMB->slice_nr = 0;
    currMB->delta_qp = 0;
    currMB->qp = 26;
    currMB->qpsp = 0;
    for (int j = 0; j < 8; j++) {
        currMB->bitcounter[j] = 0;
    }
    currMB->mb_available_up = NULL;
    currMB->mb_available_left = NULL;
    currMB->mb_type = 0;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 4; b++)
            for (int c = 0; c < 4; c++)
                for (int d = 0; d < 2; d++)
                    currMB->mvd[a][b][c][d] = 0;
    for (int k = 0; k < 16; k++) {
        currMB->intra_pred_modes[k] = 0;
        currMB->intra_pred_modes8x8[k] = 0;
    }
    currMB->cbp = 0;
    currMB->cbp_blk = 0;
    currMB->cbp_bits = 0;
    currMB->lf_disable = 0;
    currMB->lf_alpha_c0_offset = 0;
    currMB->lf_beta_offset = 0;
    currMB->c_ipred_mode = 0;
    currMB->IntraChromaPredModeFlag = 0;
    currMB->mb_field = 0;
    currMB->mbAddrA = -1;
    currMB->mbAddrB = -1;
    currMB->mbAddrC = -1;
    currMB->mbAddrD = -1;
    currMB->mbAvailA = 0;
    currMB->mbAvailB = 0;
    currMB->mbAvailC = 0;
    currMB->mbAvailD = 0;
    currMB->all_blk_8x8 = 1;
    currMB->luma_transform_size_8x8_flag = 0;
    currMB->NoMbPartLessThan8x8Flag = 1;
    currMB->bi_pred_me = 0;
    currMB->actj = 1.0;
    currMB->prev_qp = 26;
    currMB->prev_delta_qp = 0;
    currMB->prev_cbp = 0;
    currMB->predict_qp = 26;
    currMB->predict_error = 0;
    currMB->LFDisableIdc = 0;
    currMB->LFAlphaC0Offset = 0;
    currMB->LFBetaOffset = 0;
    currMB->skip_flag = 0;
}