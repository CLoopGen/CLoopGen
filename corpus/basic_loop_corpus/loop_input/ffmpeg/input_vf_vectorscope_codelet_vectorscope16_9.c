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
uint16_t *spx;
uint16_t *spy;
uint16_t *spd;
uint16_t *dpx;
uint16_t *dpy;
uint16_t *dpd;
int max;
int mid;
int tmin;
int tmax;
int i;
int j;

void init_vars() {
    // Set parameters to create approximately 64-128MB of total data
    h = 1024;
    w = 1024;
    
    slinesizex = w;
    slinesizey = w;
    slinesized = w;
    dlinesize = w;
    
    max = 511;  // since we clamp spx/spy to max, keep it under 1024
    mid = w / 2;
    tmin = 100;
    tmax = 400;
    
    // Allocate input arrays: each is h x w = 1M elements -> ~2MB per array (uint16_t)
    spx = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * h * w);
    spy = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * h * w);
    spd = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * h * w);
    
    // Output arrays: dpx, dpy, dpd are indexed by y*dlinesize + x, so size h*w
    dpx = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * h * w);
    dpy = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * h * w);
    dpd = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * h * w);
    
    // Initialize input data with pseudo-random but valid values
    for (int idx = 0; idx < h * w; idx++) {
        spx[idx] = rand() % 700;      // some above max to test clamping
        spy[idx] = rand() % 700;
        spd[idx] = rand() % 500;      // range includes tmin..tmax
    }
    
    // Initialize output arrays to zero
    memset(dpx, 0, sizeof(uint16_t) * h * w);
    memset(dpy, 0, sizeof(uint16_t) * h * w);
    memset(dpd, 0, sizeof(uint16_t) * h * w);
}