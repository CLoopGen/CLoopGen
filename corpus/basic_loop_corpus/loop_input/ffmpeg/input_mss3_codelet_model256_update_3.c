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

Model256 *m;
int i;
int sum;
unsigned int scale;
int send;
int sidx;

void init_vars() {
    m = (Model256*)calloc(1, sizeof(Model256));
    if (!m) exit(1);

    sum = 1 << 16;
    scale = 0x10000;
    send = 0;
    sidx = 0;

    for (int idx = 0; idx < 256; idx++) {
        m->weights[idx] = 1 + (idx & 31);
    }

    for (int idx = 0; idx < 68; idx++) {
        m->secondary[idx] = 0;
    }

    m->tot_weight = 0;
    m->sec_size = 68;
    m->upd_val = 0;
    m->max_upd_val = 100;
    m->till_rescale = 1000;
}