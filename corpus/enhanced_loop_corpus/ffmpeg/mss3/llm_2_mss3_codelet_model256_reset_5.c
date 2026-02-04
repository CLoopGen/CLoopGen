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
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i < 255; i += 2) {
        m->weights[i] = 1;
        if (i + 1 < 255) {
            m->weights[i + 1] = 1;
        }
    }
}
