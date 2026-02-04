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
    // Variant 2: Indirect Access via Index Array to Simulate Irregular Memory Access
    int *indices = (int*)malloc(nb_codes * sizeof(int));
    if (!indices) return; // Handle allocation failure

    for (i = 0; i < nb_codes; ++i) {
        indices[i] = i * 2; // Store base indices for even positions
    }

    for (i = 0; i < nb_codes; i++) {
        int idx = indices[i]; // Use indirect access
        uint32_t cur_count = nodes[idx].count + nodes[idx + 1].count;
        for (j = cur_node; j > idx + 2; j--) {
            if (cur_count > nodes[j - 1].count || (cur_count == nodes[j - 1].count && !(flags & 1)))
                break;
            nodes[j] = nodes[j - 1];
        }
        nodes[j].sym = -1;
        nodes[j].count = cur_count;
        nodes[j].n0 = idx;
        cur_node++;
    }

    free(indices);
}
