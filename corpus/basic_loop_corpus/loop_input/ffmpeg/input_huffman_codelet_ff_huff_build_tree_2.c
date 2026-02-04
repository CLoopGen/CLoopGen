#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
} Node;

int nb_codes = 65536;
Node* nodes;
int flags = 1;
int i;
int j;
int cur_node;

void init_vars() {
    size_t total_nodes = nb_codes * 2;
    nodes = (Node*)calloc(total_nodes, sizeof(Node));
    
    for (int idx = 0; idx < nb_codes; idx++) {
        nodes[idx].sym = (int16_t)(idx & 0x7FFF);
        nodes[idx].n0 = -1;
        nodes[idx].count = (uint32_t)(idx * 3 + 100);
    }
    
    cur_node = nb_codes;
}

void loop();