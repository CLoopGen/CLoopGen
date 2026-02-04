#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;

int32 i;
int32 j;
int32 k;
char *tmp_word_str;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    tmp_word_str = (char*)malloc(data_size);
    if (!tmp_word_str) {
        exit(1);
    }

    // Randomly insert null bytes with ~10% density to ensure some work in loop
    for (size_t idx = 0; idx < data_size; ++idx) {
        tmp_word_str[idx] = (rand() % 10 == 0) ? '\x00' : 'A';
    }

    k = data_size - 1; // Ensure tmp_word_str[k] is accessible and loop stays within bounds
    i = 0;
    j = 0;

    // Seed rand for reproducibility
    srand((unsigned int)(time(NULL)));
}