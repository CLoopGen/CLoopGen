#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_linesize;
int src_linesize;
int w;
int h;
int x;
int y;

float *dstp_r;
float *dstp_g;
float *dstp_b;
uint8_t *srcp_r;
uint8_t *srcp_g;
uint8_t *srcp_b;

void init_vars() {
    // Set image dimensions to achieve ~100ms processing time
    // Estimate: 10 million pixels should be sufficient for ~0.01-0.1s on modern CPU
    w = 2048;
    h = 512;

    // Linesize in bytes for source is typically aligned; assume 4-byte alignment per row
    src_linesize = ((w + 3) / 4) * 4;  // Align to multiple of 4
    dst_linesize = w;  // Float arrays, no extra alignment needed beyond natural

    // Allocate buffers
    size_t src_size = (size_t)h * src_linesize;
    size_t dst_size = (size_t)h * dst_linesize * sizeof(float);

    uint8_t *src_r_data = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    uint8_t *src_g_data = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    uint8_t *src_b_data = (uint8_t*)calloc(src_size, sizeof(uint8_t));

    float *dst_r_data = (float*)calloc(h, dst_linesize * sizeof(float));
    float *dst_g_data = (float*)calloc(h, dst_linesize * sizeof(float));
    float *dst_b_data = (float*)calloc(h, dst_linesize * sizeof(float));

    // Assign plane pointers
    srcp_r = src_r_data;
    srcp_g = src_g_data;
    srcp_b = src_b_data;
    dstp_r = dst_r_data;
    dstp_g = dst_g_data;
    dstp_b = dst_b_data;

    // Initialize input data with non-zero values to ensure meaningful computation
    for (size_t i = 0; i < src_size; i++) {
        src_r_data[i] = (uint8_t)((i * 7) % 256);
        src_g_data[i] = (uint8_t)((i * 11) % 256);
        src_b_data[i] = (uint8_t)((i * 13) % 256);
    }
}