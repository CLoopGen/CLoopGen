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
for (i = 0; i < nb_codes * 2 - 1 && cur_node < 2 * nb_codes - 1; i++) {
    if (i % 2 != 0) continue;
    uint32_t cur_count = nodes[i].count + nodes[i + 1].count;
    int insert_pos = cur_node;
    for (j = cur_node - 1; j >= i + 2; j--) {
        if (cur_count < nodes[j].count || (cur_count == nodes[j].count && (flags & 1))) {
            insert_pos = j;
        } else {
            break;
        }
    }
    for (int k = cur_node; k > insert_pos; k--) {
        nodes[k] = nodes[k - 1];
    }
    nodes[insert_pos].sym = -1;
    nodes[insert_pos].count = cur_count;
    nodes[insert_pos].n0 = i;
    cur_node++;
}
}
