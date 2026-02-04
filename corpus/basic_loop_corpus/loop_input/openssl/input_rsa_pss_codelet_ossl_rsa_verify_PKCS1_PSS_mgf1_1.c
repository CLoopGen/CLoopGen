#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
int maskedDBLen;
unsigned char *DB;

void init_vars() {
    maskedDBLen = 512 * 1024; // 512 KB of data
    DB = (unsigned char *)malloc(maskedDBLen);
    if (!DB) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with leading zeros followed by a non-zero byte before the end
    memset(DB, 0, maskedDBLen - 2);
    DB[maskedDBLen - 2] = 1; // Ensures loop stops here: DB[i] != 0 and i < (maskedDBLen - 1)
    DB[maskedDBLen - 1] = 0; // Boundary safety
}