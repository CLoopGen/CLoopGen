#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

char *path;
MagickBooleanType status;
char *p;

#define DATA_SIZE (128 << 20) // 128 MB

static char data[DATA_SIZE];

void init_vars() {
    size_t i;

    // Initialize data with mostly safe characters, insert special chars near the end to ensure loop runs long enough
    for (i = 0; i < DATA_SIZE - 100; i++) {
        data[i] = 'a' + (i % 26);
    }

    // Insert wildcard characters in the last 100 bytes to trigger status = MagickTrue
    const char specials[] = { '*', '?', '{', '}', '[', ']' };
    for (i = 0; i < 10; i++) {
        data[DATA_SIZE - 100 + i] = specials[i % 6];
    }

    // Null-terminate at the very end
    data[DATA_SIZE - 1] = '\0';

    // Initialize pointers
    path = data;
    p = NULL; // Will be set inside loop
    status = MagickFalse;
}