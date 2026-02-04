#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct vorbis_codebook {
    uint8_t dimensions;
    uint8_t lookup_type;
    uint8_t maxdepth;
    VLC vlc;
    float *codevectors;
    unsigned int nb_bits;
} vorbis_codebook;

float *lsp;
float last;
unsigned int idx;
unsigned int lsp_len;
vorbis_codebook codebook;
int vec_off;

void init_vars() {
    // Allocate lsp array with ~128MB to ensure loop runtime around 0.01s
    const size_t total_lsp_size = 32 * 1024 * 1024; // ~128 MB (32M floats)
    lsp = (float *)calloc(total_lsp_size, sizeof(float));
    if (!lsp) exit(1);

    // Set reasonable values for dimensions and offsets
    codebook.dimensions = 16;
    codebook.lookup_type = 0;
    codebook.maxdepth = 5;
    codebook.nb_bits = 10;

    // Allocate codevectors with sufficient size
    const size_t codevector_size = 64;
    codebook.codevectors = (float *)calloc(codevector_size, sizeof(float));
    if (!codebook.codevectors) exit(1);

    // Initialize codevectors with non-zero values
    for (size_t i = 0; i < codevector_size; ++i) {
        codebook.codevectors[i] = (float)(i * 0.5f);
    }

    // Set vec_off within valid range
    vec_off = 0;

    // Set lsp_len to a value ensuring we don't overflow lsp
    lsp_len = total_lsp_size - codebook.dimensions;

    // Initialize last
    last = 1.0f;

    // Initialize VLC table (not used in loop but part of struct)
    codebook.vlc.bits = 8;
    codebook.vlc.table_size = 0;
    codebook.vlc.table_allocated = 0;
    codebook.vlc.table = NULL;
}