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



void loop() {
    // Variant 2: Indirect access using an index remapping table (simulating non-sequential pattern)
    int order[256];
    for (i = 0; i < 256; i++) {
        order[i] = (137 * i + 199) % 256; // Simple linear congruential shuffle
    }

    sum = 0;
    sidx = 0;

    for (i = 0; i < 256; i++) {
        int idx = order[i]; // Indirect access via shuffled index
        m->freqs[idx] = sum * scale >> 16;
        sum += m->weights[idx];
        send = m->freqs[idx] >> 9;

        // Replace while with bounded for to fill secondary array up to send
        for (; sidx <= send && sidx < 68; sidx++) {
            m->secondary[sidx] = idx - 1;
        }
    }
}
