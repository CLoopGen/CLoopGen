#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *mode;
int fSuppressMap;
int m;

void init_vars() {
    size_t data_size = 16777216; // 16 MB to target ~0.01 sec runtime
    mode = (char *)calloc(data_size, sizeof(char));
    if (!mode) exit(1);

    // Fill with 'a' except insert 'u' near the end to trigger condition
    memset(mode, 'a', data_size - 1);
    mode[data_size - 2] = 'u'; // Ensure 'u' is found before null terminator
    mode[data_size - 1] = '\0';
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}