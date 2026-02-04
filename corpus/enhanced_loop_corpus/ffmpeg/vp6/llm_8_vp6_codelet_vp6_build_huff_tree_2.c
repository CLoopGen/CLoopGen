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
    for (i = 0; i < size - 1; i += 2) {
        if (i + 1 >= size - 1) break;
        a = tmp[i].count * coeff_model[i] >> 7;
        b = tmp[i].count * (255 - coeff_model[i]) >> 7;
        nodes[map[2 * i]].count = a + (a == 0);
        nodes[map[2 * i + 1]].count = b + (b == 0);

        a = tmp[i + 1].count * coeff_model[i + 1] >> 7;
        b = tmp[i + 1].count * (255 - coeff_model[i + 1]) >> 7;
        nodes[map[2 * (i + 1)]].count = a + (a == 0);
        nodes[map[2 * (i + 1) + 1]].count = b + (b == 0);
    }
}
