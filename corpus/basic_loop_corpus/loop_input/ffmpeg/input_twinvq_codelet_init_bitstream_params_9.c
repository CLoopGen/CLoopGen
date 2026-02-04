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

static uint16_t g_bark_tab_data[3] = {100, 200, 300};
static int16_t g_bark_cb_data[3] = {1000, 2000, 3000};
static int16_t g_cb0_data[3] = {500, 1500, 2500};
static int16_t g_cb1_data[3] = {750, 1750, 2750};
static float g_lspcodebook_data[3] = {0.1f, 0.2f, 0.3f};
static int16_t g_ppc_shape_cb_data[3] = {100, 200, 300};

static TwinVQModeTab g_mtab_instance = {
    .fmode = {
        {
            .sub = 1,
            .bark_tab = &g_bark_tab_data[0],
            .bark_env_size = 10,
            .bark_cb = &g_bark_cb_data[0],
            .bark_n_coef = 4,
            .bark_n_bit = 5,
            .cb0 = &g_cb0_data[0],
            .cb1 = &g_cb1_data[0],
            .cb_len_read = 8
        },
        {
            .sub = 2,
            .bark_tab = &g_bark_tab_data[1],
            .bark_env_size = 20,
            .bark_cb = &g_bark_cb_data[1],
            .bark_n_coef = 6,
            .bark_n_bit = 7,
            .cb0 = &g_cb0_data[1],
            .cb1 = &g_cb1_data[1],
            .cb_len_read = 9
        },
        {
            .sub = 3,
            .bark_tab = &g_bark_tab_data[2],
            .bark_env_size = 30,
            .bark_cb = &g_bark_cb_data[2],
            .bark_n_coef = 8,
            .bark_n_bit = 9,
            .cb0 = &g_cb0_data[2],
            .cb1 = &g_cb1_data[2],
            .cb_len_read = 10
        }
    },
    .size = 1024,
    .n_lsp = 5,
    .lspcodebook = &g_lspcodebook_data[0],
    .lsp_bit0 = 3,
    .lsp_bit1 = 4,
    .lsp_bit2 = 5,
    .lsp_split = 2,
    .ppc_shape_cb = &g_ppc_shape_cb_data[0],
    .ppc_period_bit = 6,
    .ppc_shape_bit = 7,
    .ppc_shape_len = 8,
    .pgain_bit = 9,
    .peak_per2wid = 512
};

TwinVQModeTab *mtab = &g_mtab_instance;
int n_ch = 2;
int bse_bits[3];
int i;

void init_vars() {
    n_ch = 2;
    for (int j = 0; j < 3; j++) {
        bse_bits[j] = 0;
    }
    mtab = &g_mtab_instance;
}