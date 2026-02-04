#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
} Node;

int nb_codes = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
Node* nodes;
int i;
int64_t sum;

void init_vars() {
    nodes = (Node*)calloc(nb_codes, sizeof(Node));
    if (!nodes) {
        exit(1);
    }
    for (int j = 0; j < nb_codes; j++) {
        nodes[j].count = j * 7 + 1; // Arbitrary non-zero initialization
    }
    i = 0;
    sum = 0;
}