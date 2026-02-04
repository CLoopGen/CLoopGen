#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
} Node;

extern int nb_codes;
extern Node *nodes;
extern int i;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 0;
int step = 1;
for (i = start; i < nb_codes; i += step) {
    nodes[i].sym = i;
    nodes[i].n0 = -2;
    sum += nodes[i].count;
}
}
