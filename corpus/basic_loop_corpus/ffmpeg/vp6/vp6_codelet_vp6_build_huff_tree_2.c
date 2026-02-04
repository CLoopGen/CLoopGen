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
for (i = 0; i < size - 1; i++) {
    a = tmp[i].count * coeff_model[i] >> 8;
    b = tmp[i].count * (255 - coeff_model[i]) >> 8;
    nodes[map[2 * i]].count = a + !a;
    nodes[map[2 * i + 1]].count = b + !b;
}

}
