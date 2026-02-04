#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct GetBitContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    int index;
    int size_in_bits;
    int size_in_bits_plus8;
} GetBitContext;

typedef struct PutBitContext {
    uint32_t bit_buf;
    int bit_left;
    uint8_t *buf;
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    int size_in_bits;
} PutBitContext;

typedef struct CABACContext {
    int low;
    int range;
    int outstanding_count;
    const uint8_t *bytestream_start;
    const uint8_t *bytestream;
    const uint8_t *bytestream_end;
    PutBitContext pb;
} CABACContext;

typedef struct TransformUnit {
    int cu_qp_delta;
    int res_scale_val;
    int intra_pred_mode;
    int intra_pred_mode_c;
    int chroma_mode_c;
    uint8_t is_cu_qp_delta_coded;
    uint8_t is_cu_chroma_qp_offset_coded;
    int8_t cu_qp_offset_cb;
    int8_t cu_qp_offset_cr;
    uint8_t cross_pf;
} TransformUnit;

enum PredMode {
    MODE_INTER = 0,
    MODE_INTRA,
    MODE_SKIP
};


enum PartMode {
    PART_2Nx2N = 0,
    PART_2NxN = 1,
    PART_Nx2N = 2,
    PART_NxN = 3,
    PART_2NxnU = 4,
    PART_2NxnD = 5,
    PART_nLx2N = 6,
    PART_nRx2N = 7
};


typedef struct CodingUnit {
    int x;
    int y;
    enum PredMode pred_mode;
    enum PartMode part_mode;
    uint8_t intra_split_flag;
    uint8_t max_trafo_depth;
    uint8_t cu_transquant_bypass_flag;
} CodingUnit;

typedef struct Mv {
    int16_t x;
    int16_t y;
} Mv;

typedef struct PredictionUnit {
    int mpm_idx;
    int rem_intra_luma_pred_mode;
    uint8_t intra_pred_mode[4];
    Mv mvd;
    uint8_t merge_flag;
    uint8_t intra_pred_mode_c[4];
    uint8_t chroma_mode_c[4];
} PredictionUnit;

typedef struct NeighbourAvailable {
    int cand_bottom_left;
    int cand_left;
    int cand_up;
    int cand_up_left;
    int cand_up_right;
    int cand_up_right_sap;
} NeighbourAvailable;

typedef struct HEVCLocalContext {
    uint8_t cabac_state[199];
    uint8_t stat_coeff[4];
    uint8_t first_qp_group;
    GetBitContext gb;
    CABACContext cc;
    int8_t qp_y;
    int8_t curr_qp_y;
    int qPy_pred;
    TransformUnit tu;
    uint8_t ctb_left_flag;
    uint8_t ctb_up_flag;
    uint8_t ctb_up_right_flag;
    uint8_t ctb_up_left_flag;
    int end_of_tiles_x;
    int end_of_tiles_y;
    uint8_t edge_emu_buffer[11360] __attribute__((aligned(32)));
    uint8_t edge_emu_buffer2[11360] __attribute__((aligned(32)));
    int16_t tmp[4096] __attribute__((aligned(32)));
    int ct_depth;
    CodingUnit cu;
    PredictionUnit pu;
    NeighbourAvailable na;
    int boundary_flags;
} HEVCLocalContext;

extern HEVCLocalContext *lc;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            lc->pu.intra_pred_mode[i * 2 + j] = 1;
}
