#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *out;
uint8_t **in;
int len;
int channels;
int ch;
int out_bps;
int is;
int os;

void init_vars() {
    channels = 2;
    len = 1 << 20; // 1M samples per channel
    out_bps = len * sizeof(float);
    is = sizeof(double);
    os = sizeof(float);

    // Allocate output buffer
    out = aligned_alloc(32, channels * out_bps);
    
    // Allocate input array of pointers and channel buffers
    in = malloc(channels * sizeof(uint8_t*));
    
    for (int c = 0; c < channels; c++) {
        in[c] = aligned_alloc(32, len * sizeof(double));
        // Initialize with some data to avoid undefined behavior
        double *dptr = (double*)in[c];
        for (int i = 0; i < len; i++) {
            dptr[i] = (double)(i + c);
        }
    }
    
    // Initialize output to zero
    memset(out, 0, channels * out_bps);
}

// Explicitly define ch at file scope since it's used externally
int ch = 0;