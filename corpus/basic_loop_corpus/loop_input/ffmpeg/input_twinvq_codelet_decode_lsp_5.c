#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

struct TwinVQFrameMode {
    uint8_t sub;
    const uint16_t *bark_tab;
    uint8_t bark_env_size;
    const int16_t *bark_cb;
    uint8_t bark_n_coef;
    uint8_t bark_n_bit;
    const int16_t *cb0;
    const int16_t *cb1;
    uint8_t cb_len_read;
};

typedef struct TwinVQModeTab {
    struct TwinVQFrameMode fmode[3];
    uint16_t size;
    uint8_t n_lsp;
    const float *lspcodebook;
    uint8_t lsp_bit0;
    uint8_t lsp_bit1;
    uint8_t lsp_bit2;
    uint8_t lsp_split;
    const int16_t *ppc_shape_cb;
    uint8_t ppc_period_bit;
    uint8_t ppc_shape_bit;
    uint8_t ppc_shape_len;
    uint8_t pgain_bit;
    uint16_t peak_per2wid;
} TwinVQModeTab;

static uint16_t static_bark_tab_data[] = { 0, 1, 2, 3, 4 };
static int16_t static_bark_cb_data[] = { -100, -50, 0, 50, 100 };
static int16_t static_cb0_data[] = { 1, 2, 3 };
static int16_t static_cb1_data[] = { 4, 5, 6 };
static int16_t static_ppc_shape_cb_data[] = { 10, 20, 30, 40, 50 };

static float static_lspcodebook_data[] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f };

const uint16_t *bark_tab_ptr = static_bark_tab_data;
const int16_t *bark_cb_ptr = static_bark_cb_data;
const int16_t *cb0_ptr = static_cb0_data;
const int16_t *cb1_ptr = static_cb1_data;
const int16_t *ppc_shape_cb_ptr = static_ppc_shape_cb_data;
const float *lspcodebook_ptr = static_lspcodebook_data;

TwinVQModeTab *mtab;
float *lsp;
float *hist;
float *cb3;
int lpc_hist_idx;
int i;

#define DATA_SIZE_MB 64
#define N_LSP (DATA_SIZE_MB * (1 << 16) / sizeof(float) / 3)
#define LPC_HIST_IDX_MAX 3

void init_vars() {
    mtab = (TwinVQModeTab*)calloc(1, sizeof(TwinVQModeTab));
    if (!mtab) exit(1);

    mtab->fmode[0].bark_tab = bark_tab_ptr;
    mtab->fmode[0].bark_cb = bark_cb_ptr;
    mtab->fmode[0].cb0 = cb0_ptr;
    mtab->fmode[0].cb1 = cb1_ptr;

    mtab->lspcodebook = lspcodebook_ptr;
    mtab->ppc_shape_cb = ppc_shape_cb_ptr;

    mtab->n_lsp = N_LSP > 0 ? N_LSP : 1;
    mtab->size = 1024;
    mtab->lsp_bit0 = 4;
    mtab->lsp_bit1 = 5;
    mtab->lsp_bit2 = 6;
    mtab->lsp_split = 2;
    mtab->ppc_period_bit = 3;
    mtab->ppc_shape_bit = 4;
    mtab->ppc_shape_len = 5;
    mtab->pgain_bit = 7;
    mtab->peak_per2wid = 200;

    lsp = (float*)calloc(mtab->n_lsp, sizeof(float));
    hist = (float*)calloc(mtab->n_lsp, sizeof(float));
    cb3 = (float*)calloc(LPC_HIST_IDX_MAX * mtab->n_lsp, sizeof(float));

    if (!lsp || !hist || !cb3) exit(1);

    for (int idx = 0; idx < mtab->n_lsp; idx++) {
        lsp[idx] = 1.0f + idx * 0.01f;
        hist[idx] = 0.5f + idx * 0.005f;
    }

    for (int j = 0; j < LPC_HIST_IDX_MAX; j++) {
        for (int idx = 0; idx < mtab->n_lsp; idx++) {
            cb3[j * mtab->n_lsp + idx] = 0.2f + (j * mtab->n_lsp + idx) * 0.001f;
        }
    }

    lpc_hist_idx = rand() % LPC_HIST_IDX_MAX;
}