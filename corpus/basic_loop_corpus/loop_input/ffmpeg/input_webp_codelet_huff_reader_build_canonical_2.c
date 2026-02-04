#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int alphabet_size = 1048576; // ~1M elements to target ~0.01 sec runtime
int max_code_length = 0;
int sym;

int *code_lengths;

void init_vars() {
    code_lengths = (int*)malloc(alphabet_size * sizeof(int));
    if (!code_lengths) {
        exit(1);
    }
    for (int i = 0; i < alphabet_size; i++) {
        code_lengths[i] = rand() % 32; // Random code lengths between 0 and 31
    }
}