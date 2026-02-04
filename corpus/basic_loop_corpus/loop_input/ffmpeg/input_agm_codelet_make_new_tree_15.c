#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int node_idx[1024];

void init_vars() {
    for (int i = 0; i < 1024; i++) {
        node_idx[i] = 0;
    }
}