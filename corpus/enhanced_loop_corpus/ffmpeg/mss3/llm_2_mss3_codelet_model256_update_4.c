#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Model256 {
    int weights[256];
    int freqs[256];
    int tot_weight;
    int secondary[68];
    int sec_size;
    int upd_val;
    int max_upd_val;
    int till_rescale;
} Model256;

extern Model256 *m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    int i;
    m->tot_weight = 0;
    for (i = 0; i < 256; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;

        m->weights[idx1] = (m->weights[idx1] + 1) >> 1;
        m->tot_weight += m->weights[idx1];

        if (idx2 < 256) {
            m->weights[idx2] = (m->weights[idx2] + 1) >> 1;
            m->tot_weight += m->weights[idx2];
        }
    }
}
