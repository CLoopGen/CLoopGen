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

static uint16_t static_bark_tab_data_0[10] = {0};
static uint16_t static_bark_tab_data_1[10] = {0};
static uint16_t static_bark_tab_data_2[10] = {0};

static int16_t static_bark_cb_data_0[8] = {0};
static int16_t static_bark_cb_data_1[8] = {0};
static int16_t static_bark_cb_data_2[8] = {0};

static int16_t static_cb0_data_0[4] = {0};
static int16_t static_cb0_data_1[4] = {0};
static int16_t static_cb0_data_2[4] = {0};

static int16_t static_cb1_data_0[4] = {0};
static int16_t static_cb1_data_1[4] = {0};
static int16_t static_cb1_data_2[4] = {0};

static float static_lspcodebook_data[16] = {0.0f};

static int16_t static_ppc_shape_cb_data[32] = {0};

static struct TwinVQFrameMode static_fmode_data[3] = {
    {
        .sub = 2,
        .bark_tab = static_bark_tab_data_0,
        .bark_env_size = 5,
        .bark_cb = static_bark_cb_data_0,
        .bark_n_coef = 3,
        .bark_n_bit = 7,
        .cb0 = static_cb0_data_0,
        .cb1 = static_cb1_data_0,
        .cb_len_read = 1
    },
    {
        .sub = 3,
        .bark_tab = static_bark_tab_data_1,
        .bark_env_size = 6,
        .bark_cb = static_bark_cb_data_1,
        .bark_n_coef = 4,
        .bark_n_bit = 8,
        .cb0 = static_cb0_data_1,
        .cb1 = static_cb1_data_1,
        .cb_len_read = 2
    },
    {
        .sub = 4,
        .bark_tab = static_bark_tab_data_2,
        .bark_env_size = 7,
        .bark_cb = static_bark_cb_data_2,
        .bark_n_coef = 5,
        .bark_n_bit = 9,
        .cb0 = static_cb0_data_2,
        .cb1 = static_cb1_data_2,
        .cb_len_read = 3
    }
};

static TwinVQModeTab internal_mtab = {
    .fmode = {
        {
            .sub = 2,
            .bark_tab = static_bark_tab_data_0,
            .bark_env_size = 5,
            .bark_cb = static_bark_cb_data_0,
            .bark_n_coef = 3,
            .bark_n_bit = 7,
            .cb0 = static_cb0_data_0,
            .cb1 = static_cb1_data_0,
            .cb_len_read = 1
        },
        {
            .sub = 3,
            .bark_tab = static_bark_tab_data_1,
            .bark_env_size = 6,
            .bark_cb = static_bark_cb_data_1,
            .bark_n_coef = 4,
            .bark_n_bit = 8,
            .cb0 = static_cb0_data_1,
            .cb1 = static_cb1_data_1,
            .cb_len_read = 2
        },
        {
            .sub = 4,
            .bark_tab = static_bark_tab_data_2,
            .bark_env_size = 7,
            .bark_cb = static_bark_cb_data_2,
            .bark_n_coef = 5,
            .bark_n_bit = 9,
            .cb0 = static_cb0_data_2,
            .cb1 = static_cb1_data_2,
            .cb_len_read = 3
        }
    },
    .size = 1024,
    .n_lsp = 10,
    .lspcodebook = static_lspcodebook_data,
    .lsp_bit0 = 5,
    .lsp_bit1 = 6,
    .lsp_bit2 = 7,
    .lsp_split = 3,
    .ppc_shape_cb = static_ppc_shape_cb_data,
    .ppc_period_bit = 4,
    .ppc_shape_bit = 5,
    .ppc_shape_len = 8,
    .pgain_bit = 3,
    .peak_per2wid = 200
};

TwinVQModeTab *mtab = &internal_mtab;
int n_ch = 2;
int lsp_bits_per_block = 12;
int bsize_no_main_cb[3] = {0};
int bse_bits[3] = {10, 15, 20};
int i = 0;

void init_vars() {
    for (int j = 0; j < 3; j++) {
        bse_bits[j] = 10 + j * 5;
    }
    n_ch = 2;
    lsp_bits_per_block = 12;
    i = 0;
}