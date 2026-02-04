#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
static uint32_t *codewords_data;
static int *quantlist_data;
static float *dimensions_data;
static float *pow2_data;
static float *num_data;

vorbis_enc_codebook *book;
float *num;
int i;
int entry;
float distance;

void init_vars() {
    // Set parameters to achieve ~0.01 seconds runtime
    // Empirically, with nentries ~ 65536 and ndimensions ~ 16, the loop takes ~0.01s
    book = (vorbis_enc_codebook*)calloc(1, sizeof(vorbis_enc_codebook));
    book->nentries = 65536;
    book->ndimensions = 16;
    
    // Allocate arrays
    lens_data = (uint8_t*)calloc(book->nentries, sizeof(uint8_t));
    codewords_data = (uint32_t*)calloc(book->nentries, sizeof(uint32_t));
    quantlist_data = (int*)calloc(book->nentries, sizeof(int));
    dimensions_data = (float*)calloc(book->nentries * book->ndimensions, sizeof(float));
    pow2_data = (float*)calloc(book->nentries, sizeof(float));
    num_data = (float*)calloc(book->ndimensions, sizeof(float));
    
    // Assign pointers
    book->lens = lens_data;
    book->codewords = codewords_data;
    book->quantlist = quantlist_data;
    book->dimensions = dimensions_data;
    book->pow2 = pow2_data;
    
    num = num_data;
    
    // Initialize data
    for (int idx = 0; idx < book->nentries; idx++) {
        lens_data[idx] = (idx % 7) ? 1 : 0; // Every 7th entry skipped
        pow2_data[idx] = (float)(rand()) / RAND_MAX * 10.0f;
        codewords_data[idx] = idx * 314159U;
        quantlist_data[idx] = idx * 751;
        
        float* vec = dimensions_data + idx * book->ndimensions;
        for (int j = 0; j < book->ndimensions; j++) {
            vec[j] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
        }
    }
    
    for (int j = 0; j < book->ndimensions; j++) {
        num_data[j] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
    }
    
    // Initialize loop variables
    i = 0;
    entry = 0;
    distance = 1e30f;
    
    // Set other book fields
    book->min = 0.0f;
    book->delta = 1.0f;
    book->seq_p = 0;
    book->lookup = 1;
}