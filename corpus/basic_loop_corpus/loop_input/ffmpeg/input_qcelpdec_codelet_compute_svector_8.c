#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double qcelp_rnd_fir_coefs[11] = {
    0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1
};

float *gain;
float *cdn_vector;
int i;
int j;
int k;
uint16_t cbseed;
float *rnd;
float tmp_gain;
float fir_filter_value;

#define RND_SIZE (256 * 1024)
#define GAIN_SIZE 8
#define CDN_VECTOR_SIZE (8 * 20)

static float gain_data[GAIN_SIZE];
static float rnd_data[RND_SIZE];
static float cdn_vector_data[CDN_VECTOR_SIZE];

void init_vars() {
    for (int idx = 0; idx < GAIN_SIZE; idx++) {
        gain_data[idx] = (float)(idx + 1) * 0.5f;
    }
    for (int idx = 0; idx < RND_SIZE; idx++) {
        rnd_data[idx] = (float)((rand() % 20000) - 10000) / 10000.0f;
    }

    gain = gain_data;
    cdn_vector = cdn_vector_data;
    cbseed = 12345;
    rnd = rnd_data + 20;
    for (int idx = 0; idx < 20; idx++) {
        rnd[-idx] = rnd_data[idx];
    }
}