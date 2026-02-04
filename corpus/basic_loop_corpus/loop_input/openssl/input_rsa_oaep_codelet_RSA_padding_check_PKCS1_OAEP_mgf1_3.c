#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
int dblen;
unsigned char *maskeddb;
unsigned char *db;

void init_vars() {
    size_t data_size = 512 * 1024; // 512 KB for ~0.01 sec runtime on modern CPU

    dblen = (int)data_size;

    db = (unsigned char *)malloc(data_size);
    maskeddb = (unsigned char *)malloc(data_size);

    if (!db || !maskeddb) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        db[idx] = (unsigned char)(idx & 0xFF);
        maskeddb[idx] = (unsigned char)((idx + 64) & 0xFF);
    }
}