#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 67108864; // ~64MB to ensure loop runtime around 0.01s on modern CPU
    s = 0;
    e = s + 1;

    key = (char*)malloc(keylen);
    if (!key) {
        exit(1);
    }

    // Fill with random characters, but place '}' at a position far enough to allow full loop execution
    size_t write_pos = 0;
    while (write_pos < keylen - 1) {
        int block_size = rand() % 1024 + 1;
        for (int i = 0; i < block_size && write_pos < keylen - 1; ++i) {
            key[write_pos++] = 'a' + (rand() % 26);
        }
    }
    // Place the closing brace near the end to ensure loop runs long enough
    key[keylen - 1] = '}';
}