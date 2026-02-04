#include <stdio.h>

#include <inttypes.h>

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

extern int only_this_block;
extern int i;
extern int j;
extern int bs_x;
extern int bs_y;
extern int ii;
extern int jj;
extern int block8x8;
extern int ipred_array[16];
extern int cont_array[16];
extern int ipred_number;
extern Macroblock *currMB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (block8x8 = 0; block8x8 < 4; block8x8++) {
        if (((currMB->b8mode[block8x8] == 11 && (only_this_block < 0 || only_this_block == block8x8)) || 
             ((currMB->b8mode[block8x8] == 13) && (only_this_block < 0 || only_this_block == block8x8)))) {
            bs_x = bs_y = (currMB->b8mode[block8x8] == 13) ? 8 : 4;
            ii = (bs_x >> 2);
            jj = (bs_y >> 2);
            for (j = 0; j < 2; j++) {
                for (i = 0; i < 2; i++) {
                    if (j % jj == 0 && i % ii == 0) {
                        ipred_array[ipred_number] = currMB->intra_pred_modes[(block8x8 << 2) | (j << 1) | i];
                        cont_array[ipred_number] = (block8x8 << 2) + (j << 1) + i;
                        ipred_number++;
                    }
                }
            }
        }
    }
}
