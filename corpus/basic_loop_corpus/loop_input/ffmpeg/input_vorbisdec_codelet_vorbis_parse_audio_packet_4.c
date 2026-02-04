#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct vorbis_mapping {
    uint8_t submaps;
    uint16_t coupling_steps;
    uint8_t *magnitude;
    uint8_t *angle;
    uint8_t *mux;
    uint8_t submap_floor[16];
    uint8_t submap_residue[16];
} vorbis_mapping;

int i;
uint8_t no_residue[255];
vorbis_mapping *mapping;

void init_vars() {
    // Allocate mapping structure
    mapping = (vorbis_mapping*)calloc(1, sizeof(vorbis_mapping));
    if (!mapping) exit(1);

    // Set coupling_steps to a value that makes the loop run long enough (~0.01 sec)
    // On modern CPUs, each iteration is very fast; aim for ~10 million iterations
    mapping->coupling_steps = 10000000;

    // Allocate magnitude and angle arrays with size >= coupling_steps
    mapping->magnitude = (uint8_t*)malloc(mapping->coupling_steps * sizeof(uint8_t));
    mapping->angle = (uint8_t*)malloc(mapping->coupling_steps * sizeof(uint8_t));
    if (!mapping->magnitude || !mapping->angle) exit(1);

    // Initialize magnitude and angle with valid indices into no_residue (0-254)
    for (int idx = 0; idx < mapping->coupling_steps; ++idx) {
        mapping->magnitude[idx] = (uint8_t)(idx % 255);
        mapping->angle[idx] = (uint8_t)((idx + 100) % 255);
    }

    // Initialize no_residue array with non-zero values initially
    for (int idx = 0; idx < 255; ++idx) {
        no_residue[idx] = 1;
    }

    // Initialize other fields in mapping
    mapping->submaps = 1;
    mapping->mux = NULL;
    for (int idx = 0; idx < 16; ++idx) {
        mapping->submap_floor[idx] = idx;
        mapping->submap_residue[idx] = idx;
    }
}