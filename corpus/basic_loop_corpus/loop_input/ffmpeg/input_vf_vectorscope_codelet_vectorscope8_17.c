#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int slinesizex;
int slinesizey;
int slinesized;
int dlinesize;
int h;
int w;
uint8_t *spx;
uint8_t *spy;
uint8_t *spd;
uint8_t *dpx;
uint8_t *dpy;
uint8_t *dpd;
int tmin;
int tmax;
int i;
int j;

void init_vars() {
    // Set image dimensions to achieve desired memory footprint (~64MB total)
    w = 1024;
    h = 512;

    slinesizex = w;
    slinesizey = w;
    slinesized = w;
    dlinesize = 2048;

    tmin = 10;
    tmax = 245;

    // Allocate source arrays: spx, spy, spd (each of size h * w)
    const size_t src_size = h * w * sizeof(uint8_t);
    spx = (uint8_t*)malloc(src_size);
    spy = (uint8_t*)malloc(src_size);
    spd = (uint8_t*)malloc(src_size);

    // Allocate destination arrays: dpx, dpy, dpd (each of size up to dlinesize * h)
    const size_t dst_pitch = dlinesize;
    const size_t dst_size = h * dst_pitch * sizeof(uint8_t);
    dpx = (uint8_t*)malloc(dst_size);
    dpy = (uint8_t*)malloc(dst_size);
    dpd = (uint8_t*)malloc(dst_size);

    // Initialize source data with pseudo-random but valid values
    for (int idx = 0; idx < h * w; idx++) {
        spx[idx] = (uint8_t)(idx % 256);
        spy[idx] = (uint8_t)((idx * 7) % 256);
        spd[idx] = (uint8_t)((idx * 13 + 17) % 256);
    }

    // Clear destination arrays
    memset(dpx, 0, dst_size);
    memset(dpy, 0, dst_size);
    memset(dpd, 0, dst_size);
}