#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *s1;
char *s2;
int idents;
int len1;
int len2;
int x;

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB to target ~0.01 sec runtime

static char buffer1[DATA_SIZE] __attribute__((aligned(64)));
static char buffer2[DATA_SIZE] __attribute__((aligned(64)));

void init_vars() {
    // Initialize counters
    idents = 0;
    len1 = 0;
    len2 = 0;
    x = 0;

    // Set up s1 and s2 to point to buffers
    s1 = buffer1;
    s2 = buffer2;

    // Initialize buffers with random printable characters
    srand((unsigned int)(time(NULL) ^ (unsigned long long)init_vars));

    for (int i = 0; i < DATA_SIZE - 1; i++) {
        // Generate printable ASCII from 32 to 126
        unsigned char c1 = (rand() % 95) + 32;
        unsigned char c2 = (rand() % 95) + 32;

        buffer1[i] = (char)c1;
        buffer2[i] = (char)c2;
    }

    // Ensure both strings are null-terminated within bounds
    buffer1[DATA_SIZE - 1] = '\0';
    buffer2[DATA_SIZE - 1] = '\0';
}