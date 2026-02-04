#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **out;
uint8_t *in;
int len;
int channels;
int ch;
int in_bps;
int is;
int os;

void init_vars() {
    channels = 2;
    len = 1048576; // 1M samples per channel to target ~0.01 sec runtime
    in_bps = sizeof(double) * len; // pitch between channel data in input
    is = sizeof(double); // input stride
    os = sizeof(double); // output stride

    // Allocate input buffer
    in = aligned_alloc(64, channels * in_bps);
    
    // Allocate output pointer array
    out = malloc(channels * sizeof(uint8_t*));
    
    // Allocate each output channel buffer and assign
    for (int c = 0; c < channels; c++) {
        out[c] = aligned_alloc(64, os * len);
    }

    // Initialize input data with some pattern to allow inspection
    double *din = (double*)in;
    for (int i = 0; i < channels * len; i++) {
        din[i] = (double)(i & 0xFF) * 0.125;
    }
}

// Explicit instantiation of extern variables
uint8_t **out = NULL;
uint8_t *in = NULL;
int len = 0;
int channels = 0;
int ch = 0;
int in_bps = 0;
int is = 0;
int os = 0;