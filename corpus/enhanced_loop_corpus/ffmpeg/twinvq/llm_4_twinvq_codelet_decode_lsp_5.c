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

extern int lpc_hist_idx;
extern float *lsp;
extern float *hist;
extern  TwinVQModeTab *mtab;
extern int i;
extern  float *cb3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < mtab->n_lsp; i++) {
        float weight = cb3[lpc_hist_idx * mtab->n_lsp + i];
        float tmp2 = hist[i] * weight;
        hist[i] = lsp[i];
        if (weight < 0.5) {
            lsp[i] = lsp[i] + tmp2;
        } else {
            float tmp1 = 1.0f - weight;
            lsp[i] = lsp[i] * tmp1 + tmp2;
        }
    }
}
