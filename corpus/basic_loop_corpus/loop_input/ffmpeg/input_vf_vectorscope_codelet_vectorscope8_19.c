#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int slinesizex;
int slinesizey;
int slinesized;
int dlinesize;
int intensity;
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
    // Set parameters to achieve ~0.01 sec runtime on modern CPU
    // Estimate: aim for moderate data size, approx 16-32 million pixels
    h = 4096;
    w = 4096;
    
    slinesizex = w;
    slinesizey = w;
    slinesized = w;
    dlinesize = w * 2; // larger than w to allow scatter without bounds overflow
    
    intensity = 50;
    tmin = 10;
    tmax = 245;
    
    // Allocate source arrays
    spx = (uint8_t*)aligned_alloc(32, (size_t)h * w * sizeof(uint8_t));
    spy = (uint8_t*)aligned_alloc(32, (size_t)h * w * sizeof(uint8_t));
    spd = (uint8_t*)aligned_alloc(32, (size_t)h * w * sizeof(uint8_t));
    
    // Allocate destination arrays with padding to prevent out-of-bounds
    const size_t dest_size = (size_t)dlinesize * h * 2;
    dpx = (uint8_t*)aligned_alloc(32, dest_size);
    dpy = (uint8_t*)aligned_alloc(32, dest_size);
    dpd = (uint8_t*)aligned_alloc(32, dest_size);
    
    // Initialize source data with pseudo-random but valid values
    srand((unsigned int)time(NULL));
    for (int idx = 0; idx < h * w; idx++) {
        spx[idx] = (uint8_t)(rand() % w);
        spy[idx] = (uint8_t)(rand() % h);
        spd[idx] = (uint8_t)(rand() % 256);
    }
    
    // Initialize destination arrays to zero
    memset(dpx, 0, dest_size);
    memset(dpy, 0, dest_size);
    memset(dpd, 0, dest_size);
}