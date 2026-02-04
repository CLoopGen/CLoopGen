#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *out;
uint8_t **in;
int len;
int channels;
int ch;
int out_bps;
int is;
int os;

static uint8_t *out_buffer;
static uint8_t **in_buffers;
static int16_t *raw_input_data;

void init_vars() {
    channels = 2;
    len = 4000000;
    out_bps = len * sizeof(float);
    is = sizeof(int16_t);
    os = sizeof(float);

    size_t total_out_size = channels * out_bps;
    out_buffer = aligned_alloc(32, total_out_size);
    out = out_buffer;

    in_buffers = aligned_alloc(32, channels * sizeof(uint8_t*));
    raw_input_data = aligned_alloc(32, channels * len * sizeof(int16_t));

    in = in_buffers;

    for (int c = 0; c < channels; c++) {
        in[c] = (uint8_t*)&raw_input_data[c * len];
        for (int i = 0; i < len; i++) {
            ((int16_t*)in[c])[i] = rand() % 65536 - 32768;
        }
    }

    for (int c = 0; c < channels; c++) {
        uint8_t *po = out + c * out_bps;
        for (int i = 0; i < len; i++) {
            ((float*)(po + i * os))[0] = 0.0f;
        }
    }
}