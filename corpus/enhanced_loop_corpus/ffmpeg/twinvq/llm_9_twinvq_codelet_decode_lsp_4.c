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

extern int lpc_idx1;
extern uint8_t *lpc_idx2;
extern float *lsp;
extern  TwinVQModeTab *mtab;
extern int i;
extern int j;
extern  float *cb;
extern  float *cb2;
extern  int8_t funny_rounding[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_offset1 = lpc_idx1 * mtab->n_lsp;
    int split = mtab->lsp_split;
    int n_lsp = mtab->n_lsp;
    for (i = 0; i < split; i++) {
        int start = (i * n_lsp) / split;
        int end = ((i + 1) * n_lsp + funny_rounding[i & 3]) / split;
        int idx2_offset = lpc_idx2[i] * n_lsp;
        for (j = start; j < end; j++) {
            lsp[j] = cb[base_offset1 + j] + cb2[idx2_offset + j];
        }
    }
}
