#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
uint16_t *dpd;
int max;
int tmin;
int tmax;
int i;
int j;

void init_vars() {
    max = 1023;
    tmin = 100;
    tmax = 900;
    intensity = 50;
    h = 1024;
    w = 1024;
    slinesizex = w;
    slinesizey = w;
    slinesized = w;
    dlinesize = 2048;

    size_t spx_size = h * slinesizex * sizeof(uint16_t);
    size_t spy_size = h * slinesizey * sizeof(uint16_t);
    size_t spd_size = h * slinesized * sizeof(uint16_t);
    size_t dpd_size = dlinesize * dlinesize * sizeof(uint16_t);

    spx = (uint16_t*)aligned_alloc(64, spx_size);
    spy = (uint16_t*)aligned_alloc(64, spy_size);
    spd = (uint16_t*)aligned_alloc(64, spd_size);
    dpd = (uint16_t*)aligned_alloc(64, dpd_size);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            spx[i * slinesizex + j] = rand() % (max + 1);
            spy[i * slinesizey + j] = rand() % (max + 1);
            spd[i * slinesized + j] = rand() % (tmax + 100);
        }
    }

    for (int i = 0; i < dlinesize * dlinesize; i++) {
        dpd[i] = rand() % (max + 1);
    }
}