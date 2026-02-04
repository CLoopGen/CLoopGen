#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
} Node;

extern uint8_t coeff_model[];
extern  uint8_t *map;
extern unsigned int size;
extern Node nodes[24];
extern Node *tmp;
extern int a;
extern int b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (size >> 1); i++) {
        int idx1 = 2 * i;
        int idx2 = 2 * i + 1;
        uint32_t count1 = tmp[idx1].count;
        uint32_t count2 = tmp[idx2].count;

        a = (count1 * coeff_model[idx1]) >> 9;
        b = (count2 * coeff_model[idx2]) >> 9;

        int map_idx1 = map[2 * idx1];
        int map_idx2 = map[2 * idx1 + 1];
        int map_idx3 = map[2 * idx2];
        int map_idx4 = map[2 * idx2 + 1];

        nodes[map_idx1].count = a ? a : 1;
        nodes[map_idx2].count = (count1 - a) ? (count1 - a) : 1;
        nodes[map_idx3].count = b ? b : 1;
        nodes[map_idx4].count = (count2 - b) ? (count2 - b) : 1;
    }
}
