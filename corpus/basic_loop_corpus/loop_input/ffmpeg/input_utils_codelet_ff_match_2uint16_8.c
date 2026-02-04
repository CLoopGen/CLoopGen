#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define NUM_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t[2]))

static uint16_t tab_data[NUM_ELEMENTS][2];
uint16_t (*tab)[2] = tab_data;
int size = NUM_ELEMENTS;
int a = 0;
int b = 0;
int i;

void init_vars() {
    srand((unsigned int)time(NULL));

    for (int idx = 0; idx < NUM_ELEMENTS; idx++) {
        tab[idx][0] = (uint16_t)(rand() % 65535);
        tab[idx][1] = (uint16_t)(rand() % 65535);
    }

    a = (uint16_t)(rand() % 65535);
    b = (uint16_t)(rand() % 65535);

    int target_index = rand() % (NUM_ELEMENTS / 2) + (NUM_ELEMENTS / 2);
    tab[target_index][0] = a;
    tab[target_index][1] = b;

    i = 0;
}