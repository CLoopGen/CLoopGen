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

typedef struct HuffReader {
    VLC vlc;
    int simple;
    int nb_symbols;
    uint16_t simple_symbols[2];
} HuffReader;

// Define all extern variables
HuffReader *r;
int *code_lengths;
int alphabet_size = 32768;
int len;
int sym;
int code;
int max_code_length = 15;
uint16_t *codes;

static int internal_code_lengths[32768];
static uint16_t internal_codes[32768];

void init_vars() {
    // Allocate and initialize r
    r = (HuffReader*)calloc(1, sizeof(HuffReader));
    
    // Initialize code_lengths to point to internal array
    code_lengths = internal_code_lengths;
    
    // Initialize codes to point to internal array
    codes = internal_codes;
    
    // Set reasonable alphabet size within bounds
    alphabet_size = 32768;
    
    // Max code length for Huffman coding typically up to 15
    max_code_length = 15;
    
    // Initialize code_lengths with valid values between 1 and max_code_length
    for (int i = 0; i < alphabet_size; i++) {
        code_lengths[i] = (i % max_code_length) + 1;
    }
    
    // Initialize code and nb_symbols
    code = 0;
    if (r) {
        r->nb_symbols = 0;
    }
}