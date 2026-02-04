#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[256];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

extern PixelModel3 n;
extern int c;
extern int e;
extern int f;
extern int g;
extern int k;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = (n.size > 128) ? 128 : n.size;
for (c = 0; c < limit; c += 2) {
    for (g = c + 1; g < limit; g++) {
        int idx_c = 2 * c, idx_g = 2 * g;
        int freq_c = n.freqs[idx_c], freq_g = n.freqs[idx_g];
        if (freq_g > freq_c) {
            n.freqs[idx_c] = freq_g;
            n.freqs[idx_c + 1] = n.freqs[idx_g + 1];
            n.freqs[idx_g] = freq_c;
            n.freqs[idx_g + 1] = n.freqs[idx_c + 1] - (freq_g - freq_c);
            uint16_t tmp_cnt = n.cnts[g];
            n.cnts[g] = n.cnts[c];
            n.cnts[c] = tmp_cnt;
            uint8_t tmp_sym = n.symbols[g];
            n.symbols[g] = n.symbols[c];
            n.symbols[c] = tmp_sym;
        }
    }
}
}
