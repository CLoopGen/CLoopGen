#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int response_codes[65536];
int err;
int i;
int result;
int code_found;

void init_vars() {
    size_t size = 65536;
    for (size_t idx = 0; idx < size - 1; ++idx) {
        response_codes[idx] = rand() % 100000 + 1;
    }
    response_codes[size - 1] = 0;

    err = rand() % 2 ? response_codes[rand() % (size - 1)] : 999999;

    i = 0;
    result = 0;
    code_found = 0;

    srand((unsigned int)time(NULL));
}