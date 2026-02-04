#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_KB 512
#define TOTAL_ELEMENTS (DATA_SIZE_KB * 1024 / sizeof(size_t))

unsigned int range = TOTAL_ELEMENTS;
double expected = 100.0;
double sum = 0.0;
size_t *counts = NULL;
unsigned int i = 0;

void init_vars() {
    counts = (size_t*)calloc(TOTAL_ELEMENTS, sizeof(size_t));
    if (!counts) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (unsigned int j = 0; j < TOTAL_ELEMENTS; j++) {
        counts[j] = (size_t)(expected + (rand() % 21 - 10)); // values around expected
    }
}