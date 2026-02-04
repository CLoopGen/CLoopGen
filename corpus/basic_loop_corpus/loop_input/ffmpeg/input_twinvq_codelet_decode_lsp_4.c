#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

static uint16_t static_bark_tab_data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static int16_t static_bark_cb_data[16] = {0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8};
static int16_t static_cb0_data[8] = {0, 1, 2, 3, 4, 5, 6, 7};
static int16_t static_cb1_data[8] = {-1, -2, -3, -4, -5, -6, -7, -8};
static float static_lspcodebook_data[128] = {0};
static int16_t static_ppc_shape_cb_data[32] = {0};
static uint8_t static_lpc_idx2_data[4] = {0, 1, 2, 3};
static float static_cb_data[256 * 16] = {0};
static float static_cb2_data[256 * 16] = {0};
static float static_lsp_data[256 * 16] = {0};

static struct TwinVQFrameMode static_fmode_data[3] = {
    {
        .sub = 1,
        .bark_tab = static_bark_tab_data,
        .bark_env_size = 5,
        .bark_cb = static_bark_cb_data,
        .bark_n_coef = 4,
        .bark_n_bit = 3,
        .cb0 = static_cb0_data,
        .cb1 = static_cb1_data,
        .cb_len_read = 8
    },
    {
        .sub = 2,
        .bark_tab = static_bark_tab_data + 1,
        .bark_env_size = 6,
        .bark_cb = static_bark_cb_data + 2,
        .bark_n_coef = 5,
        .bark_n_bit = 4,
        .cb0 = static_cb0_data + 1,
        .cb1 = static_cb1_data + 1,
        .cb_len_read = 7
    },
    {
        .sub = 3,
        .bark_tab = static_bark_tab_data + 2,
        .bark_env_size = 7,
        .bark_cb = static_bark_cb_data + 4,
        .bark_n_coef = 6,
        .bark_n_bit = 5,
        .cb0 = static_cb0_data + 2,
        .cb1 = static_cb1_data + 2,
        .cb_len_read = 6
    }
};

static TwinVQModeTab static_mtab_data = {
    .fmode = {
        { .sub = 1, .bark_tab = static_bark_tab_data, .bark_env_size = 5, .bark_cb = static_bark_cb_data, .bark_n_coef = 4, .bark_n_bit = 3, .cb0 = static_cb0_data, .cb1 = static_cb1_data, .cb_len_read = 8 },
        { .sub = 2, .bark_tab = static_bark_tab_data + 1, .bark_env_size = 6, .bark_cb = static_bark_cb_data + 2, .bark_n_coef = 5, .bark_n_bit = 4, .cb0 = static_cb0_data + 1, .cb1 = static_cb1_data + 1, .cb_len_read = 7 },
        { .sub = 3, .bark_tab = static_bark_tab_data + 2, .bark_env_size = 7, .bark_cb = static_bark_cb_data + 4, .bark_n_coef = 6, .bark_n_bit = 5, .cb0 = static_cb0_data + 2, .cb1 = static_cb1_data + 2, .cb_len_read = 6 }
    },
    .size = 256,
    .n_lsp = 16,
    .lspcodebook = static_lspcodebook_data,
    .lsp_bit0 = 4,
    .lsp_bit1 = 5,
    .lsp_bit2 = 6,
    .lsp_split = 4,
    .ppc_shape_cb = static_ppc_shape_cb_data,
    .ppc_period_bit = 3,
    .ppc_shape_bit = 4,
    .ppc_shape_len = 8,
    .pgain_bit = 2,
    .peak_per2wid = 100
};

int lpc_idx1;
uint8_t *lpc_idx2;
float *lsp;
TwinVQModeTab *mtab;
int i;
int j;
float *cb;
float *cb2;
int8_t funny_rounding[4] = {0, 1, 0, 1};

void init_vars() {
    mtab = &static_mtab_data;
    lpc_idx1 = 5;
    lpc_idx2 = static_lpc_idx2_data;
    lsp = static_lsp_data;
    cb = static_cb_data;
    cb2 = static_cb2_data;

    for (int idx = 0; idx < 256 * 16; idx++) {
        static_cb_data[idx] = (float)(idx % 100);
        static_cb2_data[idx] = (float)(idx % 80);
    }
    j = 0;
}