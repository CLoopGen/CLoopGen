#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int only_this_block;
int i;
int j;
int bs_x;
int bs_y;
int ii;
int jj;
int block8x8;
int ipred_array[16];
int cont_array[16];
int ipred_number;
Macroblock *currMB;

void init_vars() {
    // Allocate and initialize currMB
    currMB = (Macroblock*)calloc(1, sizeof(Macroblock));
    if (!currMB) exit(1);

    // Initialize b8mode: set values to 11 or 13 so that condition triggers
    currMB->b8mode[0] = 11;
    currMB->b8mode[1] = 13;
    currMB->b8mode[2] = 11;
    currMB->b8mode[3] = 13;

    // Initialize intra_pred_modes safely within bounds [0,15]
    for (int idx = 0; idx < 16; ++idx) {
        currMB->intra_pred_modes[idx] = idx % 7; // valid mode values
    }

    // Set only_this_block to -1 to ensure all blocks are processed
    only_this_block = -1;

    // Initialize other scalar variables used in arithmetic
    i = 0;
    j = 0;
    bs_x = 0;
    bs_y = 0;
    ii = 0;
    jj = 0;
    block8x8 = 0;
    ipred_number = 0;

    // Initialize arrays to zero
    memset(ipred_array, 0, sizeof(ipred_array));
    memset(cont_array, 0, sizeof(cont_array));

    // Initialize neighbor pointers to NULL (not needed for this loop)
    currMB->mb_available_up = NULL;
    currMB->mb_available_left = NULL;
}