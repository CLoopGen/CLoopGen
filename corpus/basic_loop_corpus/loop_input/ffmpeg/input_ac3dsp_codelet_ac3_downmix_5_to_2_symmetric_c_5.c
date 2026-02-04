#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **samples;
int len;
int i;
float v0;
float v1;
float front_mix;
float center_mix;
float surround_mix;

void init_vars() {
    len = 8000000; // Approximate size for ~0.01 sec runtime on modern CPU

    front_mix = 0.8f;
    center_mix = 0.6f;
    surround_mix = 0.4f;

    samples = (float**)malloc(5 * sizeof(float*));
    for (int idx = 0; idx < 5; idx++) {
        samples[idx] = (float*)malloc(len * sizeof(float));
        for (int k = 0; k < len; k++) {
            samples[idx][k] = (float)(rand()) / RAND_MAX * 2.0f - 1.0f;
        }
    }
}