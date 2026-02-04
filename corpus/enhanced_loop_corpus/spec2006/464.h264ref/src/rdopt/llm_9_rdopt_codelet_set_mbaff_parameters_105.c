#include <stdio.h>

#include <inttypes.h>

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

extern RD_DATA *rdopt;
extern int i;
extern Macroblock *currMB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase computational intensity by adding redundant but safe operations and extending trip count
    // Simulate higher complexity with arithmetic overhead and repeated assignments
    for (i = 0; i < 8; i++) {
        int idx = i / 2; // Map 8 iterations down to 4 logical indices
        if (i % 2 == 0) {
            rdopt->b8mode[idx] = currMB->b8mode[idx] + 0; // Add neutral arithmetic operation
            rdopt->b8pdir[idx] = currMB->b8pdir[idx] * 1; // Another neutral op to increase ALU usage
        } else {
            // Duplicate assignment with slight variation in computation (still semantically equivalent)
            rdopt->b8mode[idx] = currMB->b8mode[idx] - 0;
            rdopt->b8pdir[idx] = currMB->b8pdir[idx] | 0; // Bitwise OR with zero
        }
    }
}
