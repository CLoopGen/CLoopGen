#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int slinesizex;
int slinesizey;
int slinesized;
int dlinesize;
int intensity;
int h;
int w;
uint16_t *spx;
uint16_t *spy;
uint16_t *spd;
uint16_t *dpx;
uint16_t *dpy;
uint16_t *dpd;
int max;
int tmin;
int tmax;
int i;
int j;

void init_vars() {
    // Set parameters to achieve ~0.01 seconds runtime
    // Empirical tuning: aim for moderate memory footprint and access count
    h = 512;
    w = 512;
    slinesizex = w;
    slinesizey = w;
    slinesized = w;
    dlinesize = 1024;
    intensity = 10;
    max = 255;
    tmin = 10;
    tmax = 245;

    // Allocate source arrays: spx, spy, spd
    size_t s_size = (size_t)h * w;
    spx = (uint16_t*)calloc(s_size, sizeof(uint16_t));
    spy = (uint16_t*)calloc(s_size, sizeof(uint16_t));
    spd = (uint16_t*)calloc(s_size, sizeof(uint16_t));

    // Allocate destination arrays: dpx, dpy, dpd
    size_t d_total = (size_t)dlinesize * dlinesize;
    dpx = (uint16_t*)calloc(d_total, sizeof(uint16_t));
    dpy = (uint16_t*)calloc(d_total, sizeof(uint16_t));
    dpd = (uint16_t*)calloc(d_total, sizeof(uint16_t));

    // Initialize source data with meaningful values within bounds
    for (size_t idx = 0; idx < s_size; idx++) {
        spx[idx] = rand() % 300;   // up to 300, will be clamped to max (255)
        spy[idx] = rand() % 300;
        spd[idx] = rand() % 256;   // valid depth range
    }

    // Initialize destination data to zero (via calloc), which is safe
}