#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *EM;
int i;
int maskedDBLen;
unsigned char *DB;

void init_vars() {
    size_t data_size = 512 * 1024; // 512 KB for ~0.01 sec runtime estimate

    maskedDBLen = (int)data_size;

    EM = (unsigned char *)malloc(data_size);
    DB = (unsigned char *)malloc(data_size);

    if (!EM || !DB) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize EM and DB with non-zero data to allow observable behavior
    for (size_t idx = 0; idx < data_size; ++idx) {
        EM[idx] = (unsigned char)(idx & 0xFF);
        DB[idx] = (unsigned char)((idx + 32) & 0xFF);
    }
}