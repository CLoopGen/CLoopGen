#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int num_ents;
    int entries[256][2];
} C_cell;

int i;
C_cell *ptr;
int next_n;
int tmp;
int n;

void init_vars() {
    ptr = (C_cell *)malloc(sizeof(C_cell));
    if (!ptr) exit(1);

    ptr->num_ents = 256;

    srand(0);
    for (int idx = 0; idx < 256; ++idx) {
        ptr->entries[idx][0] = rand() % 1000;
        ptr->entries[idx][1] = rand() % 1000;
    }

    i = 0;
    next_n = 0;
    tmp = 0;
    n = 0;
}