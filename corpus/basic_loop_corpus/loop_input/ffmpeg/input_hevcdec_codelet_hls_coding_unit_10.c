#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

static uint8_t global_buffer[2048] __attribute__((aligned(32)));
static uint8_t bytestream_buffer[2048] __attribute__((aligned(32)));
static uint8_t putbit_buffer[2048] __attribute__((aligned(32)));

HEVCLocalContext *lc;
int x;

void init_vars() {
    lc = (HEVCLocalContext*)aligned_alloc(32, sizeof(HEVCLocalContext));
    if (!lc) exit(1);

    memset(lc, 0, sizeof(HEVCLocalContext));

    lc->gb.buffer = global_buffer;
    lc->gb.buffer_end = global_buffer + sizeof(global_buffer);
    lc->gb.index = 0;
    lc->gb.size_in_bits = 8 * sizeof(global_buffer);
    lc->gb.size_in_bits_plus8 = lc->gb.size_in_bits + 8;

    lc->cc.low = 0;
    lc->cc.range = 512;
    lc->cc.outstanding_count = 0;
    lc->cc.bytestream_start = bytestream_buffer;
    lc->cc.bytestream = bytestream_buffer;
    lc->cc.bytestream_end = bytestream_buffer + sizeof(bytestream_buffer);

    lc->cc.pb.bit_buf = 0;
    lc->cc.pb.bit_left = 32;
    lc->cc.pb.buf = putbit_buffer;
    lc->cc.pb.buf_ptr = putbit_buffer;
    lc->cc.pb.buf_end = putbit_buffer + sizeof(putbit_buffer);
    lc->cc.pb.size_in_bits = 8 * sizeof(putbit_buffer);

    lc->qp_y = 26;
    lc->curr_qp_y = 26;
    lc->qPy_pred = 26;

    lc->tu.cu_qp_delta = 0;
    lc->tu.res_scale_val = 1;
    lc->tu.intra_pred_mode = 0;
    lc->tu.intra_pred_mode_c = 0;
    lc->tu.chroma_mode_c = 0;
    lc->tu.is_cu_qp_delta_coded = 0;
    lc->tu.is_cu_chroma_qp_offset_coded = 0;
    lc->tu.cu_qp_offset_cb = 0;
    lc->tu.cu_qp_offset_cr = 0;
    lc->tu.cross_pf = 0;

    lc->ctb_left_flag = 1;
    lc->ctb_up_flag = 1;
    lc->ctb_up_right_flag = 1;
    lc->ctb_up_left_flag = 1;
    lc->end_of_tiles_x = 0;
    lc->end_of_tiles_y = 0;

    memset(lc->edge_emu_buffer, 0, sizeof(lc->edge_emu_buffer));
    memset(lc->edge_emu_buffer2, 0, sizeof(lc->edge_emu_buffer2));
    memset(lc->tmp, 0, sizeof(lc->tmp));

    lc->ct_depth = 0;

    lc->cu.x = 0;
    lc->cu.y = 0;
    lc->cu.pred_mode = MODE_INTRA;
    lc->cu.part_mode = PART_2Nx2N;
    lc->cu.intra_split_flag = 0;
    lc->cu.max_trafo_depth = 0;
    lc->cu.cu_transquant_bypass_flag = 0;

    lc->pu.mpm_idx = 0;
    lc->pu.rem_intra_luma_pred_mode = 0;
    memset(lc->pu.intra_pred_mode, 0, sizeof(lc->pu.intra_pred_mode));
    lc->pu.mvd.x = 0;
    lc->pu.mvd.y = 0;
    lc->pu.merge_flag = 0;
    memset(lc->pu.intra_pred_mode_c, 0, sizeof(lc->pu.intra_pred_mode_c));
    memset(lc->pu.chroma_mode_c, 0, sizeof(lc->pu.chroma_mode_c));

    lc->na.cand_bottom_left = 1;
    lc->na.cand_left = 1;
    lc->na.cand_up = 1;
    lc->na.cand_up_left = 1;
    lc->na.cand_up_right = 1;
    lc->na.cand_up_right_sap = 1;

    lc->boundary_flags = 0;

    for (int i = 0; i < 199; i++)
        lc->cabac_state[i] = 128;
    for (int i = 0; i < 4; i++)
        lc->stat_coeff[i] = 1;
    lc->first_qp_group = 1;

    x = 0;
}