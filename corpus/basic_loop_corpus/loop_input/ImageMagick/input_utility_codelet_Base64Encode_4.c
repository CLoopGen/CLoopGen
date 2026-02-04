#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char Base64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char *blob;
size_t blob_length;
char *encode;
unsigned char *p;
size_t i;

void init_vars() {
    blob_length = 192 * 1024 * 1024; // ~192MB to target ~0.01s runtime on modern CPU
    blob = (unsigned char*)malloc(blob_length);
    encode = (char*)malloc(blob_length * 4 / 3 + 4);

    if (!blob || !encode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize blob with pseudo-random data for realistic access patterns
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&blob));
    for (size_t idx = 0; idx < blob_length; ++idx) {
        blob[idx] = (unsigned char)(rand() & 0xFF);
    }

    p = NULL;
    i = 0;
}