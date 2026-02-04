#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Model {
    int weights[16];
    int freqs[16];
    int num_syms;
    int tot_weight;
    int upd_val;
    int max_upd_val;
    int till_rescale;
} Model;

extern Model *m;
extern int i;
extern int sum;
extern unsigned int scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < m->num_syms && sum < m->tot_weight; i++) {
        m->freqs[i] = (sum * scale + 0x8000) >> 16;
        sum += m->weights[i] + m->upd_val;
        for (j = 0; j < m->till_rescale; j++) {
            m->weights[i] += (m->weights[i] > m->max_upd_val) ? -1 : 1;
        }
    }
}
