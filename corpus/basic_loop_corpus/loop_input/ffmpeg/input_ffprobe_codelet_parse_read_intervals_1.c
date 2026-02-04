#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int n;
char *p;
char *spec;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    spec = (char*)malloc(data_size);
    if (!spec) {
        exit(1);
    }

    // Initialize with printable characters, include commas to trigger the condition
    for (size_t i = 0; i < data_size - 1; i++) {
        spec[i] = (rand() % 100) == 0 ? ',' : 'a' + (i % 26);
    }
    spec[data_size - 1] = '\0'; // Null terminate
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}