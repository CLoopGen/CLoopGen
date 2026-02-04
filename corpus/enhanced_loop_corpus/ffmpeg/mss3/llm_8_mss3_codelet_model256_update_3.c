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
extern int sum;
extern unsigned int scale;
extern int send;
extern int sidx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < 128; i += 2) {
        m->freqs[i] = sum * scale >> 16;
        m->freqs[i+1] = (sum + m->weights[i]) * scale >> 16;
        sum += m->weights[i] + m->weights[i+1];
        int send1 = m->freqs[i] >> 9;
        int send2 = m->freqs[i+1] >> 9;
        for (int j = sidx; j <= send1; j++)
            m->secondary[j] = i - 1;
        sidx = send1 + 1;
        for (int j = sidx; j <= send2; j++)
            m->secondary[j] = i;
        sidx = send2 + 1;
    }
}
