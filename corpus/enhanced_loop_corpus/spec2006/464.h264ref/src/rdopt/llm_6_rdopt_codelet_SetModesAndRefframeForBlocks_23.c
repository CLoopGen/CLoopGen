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

extern int i;
extern Macroblock *currMB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by reordering writes and adding a dependency on previous iteration
    int temp_b8mode[4] = {0};
    int temp_b8pdir[4] = {-1, -1, -1, -1};
    for (i = 0; i < 4; i++) {
        // Create WAW hazard: current write depends on prior iteration's result
        if (i > 0) {
            temp_b8mode[i] = temp_b8mode[i-1] + 1;  // artificial dependence
        } else {
            temp_b8mode[i] = 0;
        }
        temp_b8pdir[i] = -1;
    }
    // Write back to currMB without loop-carried dependence in store order
    for (i = 0; i < 4; i++) {
        currMB->b8mode[i] = temp_b8mode[i];
        currMB->b8pdir[i] = temp_b8pdir[i];
    }
}
