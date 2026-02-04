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
    int64_t local_sum = 0;
    for (i = 0; i < nb_codes; i++) {
        nodes[i].sym = i;
        nodes[i].n0 = -2;
        local_sum += nodes[i].count;
    }
    sum += local_sum;
}
