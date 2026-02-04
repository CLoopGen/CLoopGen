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

static vorbis_enc_codebook cb_instance;
static uint8_t *lens_data;
static uint32_t *codewords_data;
static int *quantlist_data;
static float *dimensions_data;
static float *pow2_data;

vorbis_enc_codebook *cb = &cb_instance;
int i;

void init_vars() {
    // Allocate approximately 64MB of data to target ~0.01s runtime
    // We focus on lens array since it's the one being accessed in the loop
    size_t total_size_bytes = 64 * 1024 * 1024;
    size_t element_size = sizeof(uint8_t);
    int n = total_size_bytes / element_size;
    
    // Ensure we have reasonable minimum size
    if (n < 1000000) n = 1000000; // At least 1M entries
    
    lens_data = (uint8_t*)calloc(n, sizeof(uint8_t));
    codewords_data = (uint32_t*)malloc(n * sizeof(uint32_t));
    quantlist_data = (int*)malloc(n * sizeof(int));
    dimensions_data = (float*)malloc(n * sizeof(float));
    pow2_data = (float*)malloc(n * sizeof(float));
    
    // Initialize most entries to non-zero, but set a zero near the end to ensure loop terminates
    for (int j = 0; j < n - 1; j++) {
        lens_data[j] = 1;
    }
    lens_data[n - 1] = 0; // This will cause the loop to break at the last element
    
    // Initialize other arrays with plausible values
    for (int j = 0; j < n; j++) {
        codewords_data[j] = j * 314159;
        quantlist_data[j] = j % 1000;
        dimensions_data[j] = 1.0f + j * 0.01f;
        pow2_data[j] = 1.0f + j * 0.001f;
    }
    
    // Initialize codebook structure
    cb_instance.nentries = n;
    cb_instance.lens = lens_data;
    cb_instance.codewords = codewords_data;
    cb_instance.ndimensions = 32;
    cb_instance.min = 0.0f;
    cb_instance.delta = 1.0f;
    cb_instance.seq_p = 1;
    cb_instance.lookup = 1;
    cb_instance.quantlist = quantlist_data;
    cb_instance.dimensions = dimensions_data;
    cb_instance.pow2 = pow2_data;
}