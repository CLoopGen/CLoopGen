#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s *otr;
int ntr;
int i;

void init_vars() {
    // Allocate a large enough array to make the loop run ~0.01 seconds
    // Assuming simple memory-bound loop, aim for ~64-128MB of data
    const int data_size = 134217728; // 128 million elements

    // Allocate otr structure
    otr = (struct p7trace_s*)malloc(sizeof(struct p7trace_s));
    if (!otr) exit(1);

    otr->tlen = data_size;

    // Allocate statetype array
    otr->statetype = (char*)malloc(data_size * sizeof(char));
    if (!otr->statetype) exit(1);

    // Initialize statetype with random pattern where some values are 6
    // Use deterministic seed for reproducibility
    srand(12345);
    for (int j = 0; j < data_size; j++) {
        otr->statetype[j] = (rand() % 10 == 0) ? 6 : (rand() % 10 + 1); // ~10% chance of being 6
    }

    // Allocate dummy arrays for nodeidx and pos (not used in loop but part of struct)
    otr->nodeidx = (int*)malloc(data_size * sizeof(int));
    otr->pos = (int*)malloc(data_size * sizeof(int));
    if (!otr->nodeidx || !otr->pos) exit(1);

    // Initialize other variables
    ntr = 0;
    i = 0;
}