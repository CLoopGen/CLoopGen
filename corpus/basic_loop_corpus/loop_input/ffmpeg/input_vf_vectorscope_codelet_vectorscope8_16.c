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
uint8_t *spx;
uint8_t *spy;
uint8_t *spd;
uint8_t *dpd;
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
    intensity = 50;
    tmin = 20;
    tmax = 200;

    spx = (uint8_t*)aligned_alloc(32, (size_t)h * slinesizex);
    spy = (uint8_t*)aligned_alloc(32, (size_t)h * slinesizey);
    spd = (uint8_t*)aligned_alloc(32, (size_t)h * slinesized);
    dpd = (uint8_t*)aligned_alloc(32, (size_t)(dlinesize * (h + 100))); // extra to avoid overflow

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            spx[i * slinesizex + j] = rand() % 1024;
            spy[i * slinesizey + j] = (rand() % 100) + i; 
            spd[i * slinesized + j] = (rand() % 256);
        }
    }

    for (int i = 0; i < dlinesize * (h + 100); i++) {
        dpd[i] = rand() % 256;
    }
}