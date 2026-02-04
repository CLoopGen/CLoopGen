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



void loop(){
    int j;
    m->tot_weight = 0;
    for (i = 0; i < 128; i++) {
        for (j = 0; j < 2; j++) {
            int idx = (i << 1) | j;
            m->weights[idx] = (m->weights[idx] + 2) >> 1;
            m->tot_weight += m->weights[idx];
        }
    }
}
