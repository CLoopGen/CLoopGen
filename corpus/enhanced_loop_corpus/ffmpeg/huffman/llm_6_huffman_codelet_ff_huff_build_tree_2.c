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
    int insert_pos = cur_node;
    for (j = cur_node; j > i + 2; j--) {
        if (cur_count > nodes[j - 1].count || (cur_count == nodes[j - 1].count && !(flags & 1))) {
            insert_pos = j;
            break;
        }
        nodes[j] = nodes[j - 1];
        insert_pos = j - 1;
    }
    if (j == i + 2) insert_pos = i + 2;
    nodes[insert_pos].sym = -1;
    nodes[insert_pos].count = cur_count;
    nodes[insert_pos].n0 = i;
    cur_node++;
}
}
