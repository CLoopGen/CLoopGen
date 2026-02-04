#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
int mid;
int size;
int thra;
int thrb;
uint16_t *src;
uint16_t **srcf;
uint16_t *dst;

void init_vars() {
    // Set parameters to control data size and loop behavior
    w = 8192;                  // Width of the image-like data
    mid = 4;                   // Middle index for symmetric traversal
    size = 9;                  // Total number of rows in srcf (must be > mid)
    thra = 50;                 // Threshold for individual difference
    thrb = 100;                // Threshold for accumulated difference

    // Allocate and initialize src array
    src = (uint16_t*)calloc(w, sizeof(uint16_t));
    for (int x = 0; x < w; x++) {
        src[x] = rand() % 256;
    }

    // Allocate and initialize srcf as a 2D jagged array with 'size' rows and 'w' columns
    srcf = (uint16_t**)calloc(size, sizeof(uint16_t*));
    for (int i = 0; i < size; i++) {
        srcf[i] = (uint16_t*)calloc(w, sizeof(uint16_t));
        for (int x = 0; x < w; x++) {
            srcf[i][x] = rand() % 256;
        }
    }

    // Allocate and initialize dst array
    dst = (uint16_t*)calloc(w, sizeof(uint16_t));

    // Seed random number generator for predictable initialization
    srand(time(NULL) ^ (uintptr_t)&w);
}