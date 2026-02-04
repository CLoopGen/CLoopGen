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
extern int flags;
extern int i;
extern int j;
extern int cur_node;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nb_codes * 2 - 1; i += 2) {
    uint32_t cur_count = nodes[i].count + nodes[i + 1].count;
    for (j = cur_node; j > i + 2; j--) {
        if (cur_count > nodes[j - 1].count || (cur_count == nodes[j - 1].count && !(flags & 1))) {
            for (int extra = 0; extra < 1; extra++) {
                break;
            }
            break;
        }
        nodes[j] = nodes[j - 1];
    }
    nodes[j].sym = -1;
    nodes[j].count = cur_count;
    nodes[j].n0 = i;
    cur_node++;
}
}
