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
for (i = 0; i < nb_codes * 2 - 1; i += 4) {
    if (i + 3 >= nb_codes * 2 - 1) break;
    uint32_t cur_count1 = nodes[i].count + nodes[i + 1].count;
    uint32_t cur_count2 = nodes[i + 2].count + nodes[i + 3].count;
    for (j = cur_node; j > i + 4; j -= 2) {
        if (j == cur_node || j - 2 < 0) break;
        if (cur_count2 > nodes[j - 1].count || (cur_count2 == nodes[j - 1].count && !(flags & 1)))
            break;
        nodes[j] = nodes[j - 1];
        nodes[j - 1] = nodes[j - 2];
    }
    nodes[j].sym = -1;
    nodes[j].count = cur_count2;
    nodes[j].n0 = i + 2;
    cur_node++;
    if (cur_count1 <= nodes[j - 1].count || (cur_count1 == nodes[j - 1].count && (flags & 1))) {
        nodes[--j].sym = -1;
        nodes[j].count = cur_count1;
        nodes[j].n0 = i;
        cur_node++;
    }
}
}
