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
extern Macroblock *currMB;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic to improve spatial locality
    int *b8mode_dst = currMB->b8mode;
    int *b8mode_src = rdopt->b8mode;
    int *b8pdir_dst = currMB->b8pdir;
    int *b8pdir_src = rdopt->b8pdir;

    for (int i = 0; i < 4; i++) {
        *(b8mode_dst + i) = *(b8mode_src + i);
        *(b8pdir_dst + i) = *(b8pdir_src + i);
    }
}
