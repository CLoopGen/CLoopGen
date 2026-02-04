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
        for (i = 0; i < nb_codes; i += 2) {
            int limit = (i + 1 < nb_codes) ? 2 : 1;
            for (int j = 0; j < limit; j++) {
                int idx = i + j;
                nodes[idx].sym = idx;
                nodes[idx].n0 = -2;
                sum += nodes[idx].count;
            }
        }
    }
}
