#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char uchar;

unsigned char lowervec[256];
int patlen;
int skip2;
uchar *pat;
int i;

void init_vars() {
    // Initialize lowervec: map each character to its lowercase version
    for (int idx = 0; idx < 256; ++idx) {
        if (idx >= 'A' && idx <= 'Z')
            lowervec[idx] = idx + ('a' - 'A');
        else
            lowervec[idx] = idx;
    }

    // Set pattern length to ~16MB to ensure loop takes ~0.01s due to memory access
    patlen = 16 * 1024 * 1024;

    // Allocate large pattern buffer
    pat = (uchar *)malloc(patlen * sizeof(uchar));
    if (!pat) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize pattern with printable characters
    for (int idx = 0; idx < patlen; ++idx) {
        pat[idx] = (uchar)('A' + (idx % 26));
    }

    // Ensure skip2 is initialized to a safe value
    skip2 = patlen;

    // Initialize i to avoid undefined behavior
    i = 0;
}