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

void init_vars() {
    m = (Model256*)calloc(1, sizeof(Model256));
    if (!m) {
        exit(1);
    }

    for (int j = 0; j < 256; j++) {
        m->weights[j] = j * 3; 
    }

    m->tot_weight = 0;
    m->sec_size = 68;
    m->upd_val = 10;
    m->max_upd_val = 100;
    m->till_rescale = 5;

    for (int j = 0; j < 68; j++) {
        m->secondary[j] = j * 2;
    }

    i = 0;
}