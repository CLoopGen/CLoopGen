#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct neighbor {
    char entry[49];
    double dist;
};

int j;
int k = 5000000; // Approximately 238 MB of data (5e6 * 57 bytes ≈ 285 MB), adjust to hit ~0.01 sec runtime
struct neighbor *neighbors;

void init_vars() {
    neighbors = (struct neighbor *)calloc(k, sizeof(struct neighbor));
    if (!neighbors) {
        exit(1);
    }
    for (int i = 0; i < k; i++) {
        neighbors[i].dist = 0.0;
    }
}