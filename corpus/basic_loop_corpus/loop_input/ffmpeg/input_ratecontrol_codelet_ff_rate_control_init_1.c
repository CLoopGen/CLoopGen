#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct RateControlEntry {
    int pict_type;
    float qscale;
    int mv_bits;
    int i_tex_bits;
    int p_tex_bits;
    int misc_bits;
    int header_bits;
    uint64_t expected_bits;
    int new_pict_type;
    float new_qscale;
    int64_t mc_mb_var_sum;
    int64_t mb_var_sum;
    int i_count;
    int skip_count;
    int f_code;
    int b_code;
} RateControlEntry;

typedef struct Predictor {
    double coeff;
    double count;
    double decay;
} Predictor;

typedef struct AVExpr AVExpr;

typedef struct RateControlContext {
    int num_entries;
    RateControlEntry *entry;
    double buffer_index;
    Predictor pred[5];
    double short_term_qsum;
    double short_term_qcount;
    double pass1_rc_eq_output_sum;
    double pass1_wanted_bits;
    double last_qscale;
    double last_qscale_for[5];
    int64_t last_mc_mb_var_sum;
    int64_t last_mb_var_sum;
    uint64_t i_cplx_sum[5];
    uint64_t p_cplx_sum[5];
    uint64_t mv_bits_sum[5];
    uint64_t qscale_sum[5];
    int frame_count[5];
    int last_non_b_pict_type;
    void *non_lavc_opaque;
    float dry_run_qscale;
    int last_picture_number;
    AVExpr *rc_eq_eval;
} RateControlContext;

RateControlEntry *g_entry_array = NULL;
RateControlContext *rcc = NULL;
int i = 0;

void init_vars() {
    g_entry_array = (RateControlEntry*)calloc(1, sizeof(RateControlEntry));
    rcc = (RateControlContext*)calloc(1, sizeof(RateControlContext));
    if (!g_entry_array || !rcc) exit(1);

    rcc->num_entries = 5;
    rcc->entry = g_entry_array;
    rcc->buffer_index = 0.0;
    rcc->short_term_qsum = 0.0;
    rcc->short_term_qcount = 0.0;
    rcc->pass1_rc_eq_output_sum = 0.0;
    rcc->pass1_wanted_bits = 0.0;
    rcc->last_qscale = 0.0;
    rcc->last_mc_mb_var_sum = 0;
    rcc->last_mb_var_sum = 0;
    rcc->last_non_b_pict_type = 0;
    rcc->non_lavc_opaque = NULL;
    rcc->dry_run_qscale = 1.0f;
    rcc->last_picture_number = 0;
    rcc->rc_eq_eval = NULL;

    for (int j = 0; j < 5; j++) {
        rcc->pred[j].coeff = 0.0;
        rcc->pred[j].count = 0.0;
        rcc->pred[j].decay = 0.0;
        rcc->i_cplx_sum[j] = 0;
        rcc->p_cplx_sum[j] = 0;
        rcc->mv_bits_sum[j] = 0;
        rcc->qscale_sum[j] = 0;
        rcc->frame_count[j] = 0;
        rcc->last_qscale_for[j] = 0.0;
    }
}