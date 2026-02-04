#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int alphabet_size = 1000000;
int *code_lengths;
int len;
int sym;
int code;

void init_vars() {
    code_lengths = (int*)calloc(alphabet_size, sizeof(int));
    if (!code_lengths) exit(1);

    for (int i = 0; i < alphabet_size; i++) {
        code_lengths[i] = (i % 7 == 0) ? (i % 16 + 1) : 0;
    }

    len = 0;
    sym = 0;
    code = 0;
}