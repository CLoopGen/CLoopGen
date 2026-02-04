#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint64_t *stats;
int stats_size;
int skip0;
uint16_t *map;
int i;
int size;

void init_vars() {
    // Set data size to achieve ~0.01 seconds runtime
    // Heuristic: use 64MB of stats (approx. 8M uint64_t elements)
    stats_size = 8 * 1024 * 1024;
    size = 0;
    skip0 = 0; // Include zero entries
    i = 0;

    // Allocate dst: one byte per stat element
    dst = (uint8_t*)calloc(stats_size, sizeof(uint8_t));
    if (!dst) exit(1);

    // Allocate stats
    stats = (uint64_t*)malloc(stats_size * sizeof(uint64_t));
    if (!stats) exit(1);

    // Initialize stats with mixed values to trigger conditional branch
    for (int j = 0; j < stats_size; j++) {
        stats[j] = (j % 7) ? (j % 257) : 0; // Some zeros, some non-zeros
    }

    // Allocate map: worst case, every element could be added
    map = (uint16_t*)malloc(stats_size * sizeof(uint16_t));
    if (!map) exit(1);
}