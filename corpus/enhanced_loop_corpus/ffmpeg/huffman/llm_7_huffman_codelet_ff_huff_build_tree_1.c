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
    if (nb_codes > 0) {
        nodes[0].sym = 0;
        nodes[0].n0 = -2;
        sum += nodes[0].count;
        for (i = 1; i < nb_codes; i++) {
            nodes[i].sym = nodes[i-1].sym + 1;
            nodes[i].n0 = -2;
            sum += nodes[i].count;
        }
    }
}
