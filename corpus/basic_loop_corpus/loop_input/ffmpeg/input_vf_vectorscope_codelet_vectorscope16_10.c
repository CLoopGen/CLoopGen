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
    h = 512;
    w = 512;
    slinesizex = w;
    slinesizey = w;
    slinesized = w;
    dlinesize = 1024;
    max = 1000;
    tmin = 10;
    tmax = 900;

    size_t sp_size = (size_t)h * w;
    size_t dp_size = (size_t)dlinesize * dlinesize;

    spx = (uint16_t*)calloc(sp_size, sizeof(uint16_t));
    spy = (uint16_t*)calloc(sp_size, sizeof(uint16_t));
    spd = (uint16_t*)calloc(sp_size, sizeof(uint16_t));
    dpx = (uint16_t*)calloc(dp_size, sizeof(uint16_t));
    dpy = (uint16_t*)calloc(dp_size, sizeof(uint16_t));
    dpd = (uint16_t*)calloc(dp_size, sizeof(uint16_t));

    if (!spx || !spy || !spd || !dpx || !dpy || !dpd) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < sp_size; idx++) {
        spx[idx] = (uint16_t)(rand() % (max + 1));
        spy[idx] = (uint16_t)(rand() % (max + 1));
        spd[idx] = (uint16_t)(rand() % 1000);
    }

    for (size_t idx = 0; idx < dp_size; idx++) {
        dpx[idx] = 0;
        dpy[idx] = 0;
        dpd[idx] = 0;
    }
}