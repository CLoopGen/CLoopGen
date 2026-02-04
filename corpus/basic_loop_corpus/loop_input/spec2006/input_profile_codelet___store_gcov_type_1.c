#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *dest;
size_t bytes;
size_t i;

void init_vars() {
    bytes = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPU
    dest = (char *)calloc(bytes, sizeof(char));
    if (!dest) {
        exit(1);
    }
    i = 0;
}