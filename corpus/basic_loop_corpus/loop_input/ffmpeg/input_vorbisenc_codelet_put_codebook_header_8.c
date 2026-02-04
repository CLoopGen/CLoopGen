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
static int *quantlist_data;
static uint32_t *codewords_data;
static float *dimensions_data;
static float *pow2_data;

vorbis_enc_codebook *cb;
int i;
int len;
int j;

void init_vars() {
    // Allocate data arrays with ~64MB of input to target ~0.01s runtime
    const size_t total_size = 16777216; // 16M elements (adjustable for timing)

    lens_data = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    codewords_data = (uint32_t*)calloc(total_size, sizeof(uint32_t));
    quantlist_data = (int*)calloc(total_size, sizeof(int));
    dimensions_data = (float*)calloc(total_size, sizeof(float));
    pow2_data = (float*)calloc(total_size, sizeof(float));

    // Initialize with plausible values
    for (size_t idx = 0; idx < total_size; idx++) {
        lens_data[idx] = (uint8_t)(idx % 32);
        codewords_data[idx] = (uint32_t)(idx * 314159);
        quantlist_data[idx] = (int)(idx % 1000);
        dimensions_data[idx] = (float)(idx * 0.5);
        pow2_data[idx] = (float)(1 << (idx % 16));
    }

    cb = (vorbis_enc_codebook*)malloc(sizeof(vorbis_enc_codebook));
    cb->nentries = (int)total_size - 1000000; // Ensure j+i doesn't exceed bounds
    cb->lens = lens_data;
    cb->codewords = codewords_data;
    cb->ndimensions = 100;
    cb->min = 0.0f;
    cb->delta = 1.0f;
    cb->seq_p = 1;
    cb->lookup = 1;
    cb->quantlist = quantlist_data;
    cb->dimensions = dimensions_data;
    cb->pow2 = pow2_data;

    i = 1000000; // Start offset to allow j+i within bounds
    len = 5;     // Value unlikely to match early lens entries
    j = 0;       // Initialized in loop
}