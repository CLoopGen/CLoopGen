#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB for sufficient runtime (~0.01s on modern CPU)

int *spiral_search_x;
int *spiral_search_y;
int *mvbits;
short pred_mv_x = 16;
short pred_mv_y = 16;
int min_mcost;
int pos;
int offset_x = 32;
int offset_y = 32;
int cand_x;
int cand_y;
int mcost;
int max_pos;
int lambda_factor = 256;
int best_pos;
int *block_sad;

void init_vars() {
    srand(time(NULL));

    max_pos = DATA_SIZE / sizeof(int); // Number of elements in block_sad array

    spiral_search_x = (int *)malloc(max_pos * sizeof(int));
    spiral_search_y = (int *)malloc(max_pos * sizeof(int));
    block_sad = (int *)malloc(max_pos * sizeof(int));
    mvbits = (int *)malloc(1024 * sizeof(int)); // Large enough to handle offset indexing

    if (!spiral_search_x || !spiral_search_y || !block_sad || !mvbits) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < max_pos; i++) {
        spiral_search_x[i] = (rand() % 64) - 32;
        spiral_search_y[i] = (rand() % 64) - 32;
        block_sad[i] = rand() % 10000;
    }

    for (int i = 0; i < 1024; i++) {
        mvbits[i] = rand() % 512;
    }

    min_mcost = 1000000;
    best_pos = 0;
}