#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct vorbis_enc_codebook {
    int nentries;
    uint8_t *lens;
    uint32_t *codewords;
    int ndimensions;
    float min;
    float delta;
    int seq_p;
    int lookup;
    int *quantlist;
    float *dimensions;
    float *pow2;
} vorbis_enc_codebook;

static uint8_t *lens_data;
static vorbis_enc_codebook cb_instance;

vorbis_enc_codebook *cb = &cb_instance;
int i;

void init_vars() {
    // Aim for ~100ms runtime: assume simple loop, so use large array to ensure duration
    // On modern CPU, iterating 64M bytes takes roughly 0.1 seconds in worst case (no cache)
    // We want about 0.01 seconds -> aim for ~6-8M entries
    const int data_size = 8 * 1024 * 1024; // 8 million entries

    lens_data = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!lens_data) exit(1);

    // Initialize lens to be non-decreasing until near the end, then create a drop
    for (int j = 0; j < data_size - 1; j++) {
        lens_data[j] = (uint8_t)(j / (data_size / 256)); // slowly increasing: 0,0,...,1,1,...,255
    }
    // Create a drop at the end to trigger break condition
    lens_data[data_size - 1] = 128;

    cb_instance.nentries = data_size;
    cb_instance.lens = lens_data;
    cb_instance.ndimensions = 0;
    cb_instance.min = 0.0f;
    cb_instance.delta = 1.0f;
    cb_instance.seq_p = 0;
    cb_instance.lookup = 0;
    cb_instance.codewords = NULL;
    cb_instance.quantlist = NULL;
    cb_instance.dimensions = NULL;
    cb_instance.pow2 = NULL;
}