#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE 624
#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(unsigned long))
#define TOTAL_SIZE (DATA_SIZE_MB * ELEMENTS_PER_MB)

unsigned long UPPER_MASK = 0x80000000UL;
unsigned long LOWER_MASK = 0x7FFFFFFFUL;
unsigned long * mt = NULL;
int kk;

void init_vars() {
    mt = (unsigned long *)calloc(TOTAL_SIZE, sizeof(unsigned long));
    if (!mt) {
        exit(1);
    }

    for (size_t i = 0; i < TOTAL_SIZE; i++) {
        mt[i] = rand();
    }
}