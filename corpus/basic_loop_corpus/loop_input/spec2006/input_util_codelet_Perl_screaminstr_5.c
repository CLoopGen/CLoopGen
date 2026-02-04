#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;

unsigned char *s;
unsigned char *x;
unsigned char *big;
I32 pos;
unsigned char *little;
unsigned char *littleend;

#define BIG_SIZE (128 << 20)  // 128 MB
#define LITTLE_SIZE 64

static unsigned char big_data[BIG_SIZE];
static unsigned char little_data[LITTLE_SIZE];

void init_vars() {
    // Initialize big and little arrays with predictable data
    for (size_t i = 0; i < BIG_SIZE; ++i) {
        big_data[i] = (unsigned char)(i & 0xFF);
    }
    for (size_t i = 0; i < LITTLE_SIZE; ++i) {
        little_data[i] = (unsigned char)(i & 0xFF);
    }

    // Set pointers
    big = big_data;
    little = little_data;
    littleend = little_data + LITTLE_SIZE;

    // Set starting position within bounds so that x starts inside big
    pos = 1024;  // Offset within big

    // Ensure x will be within bounds: x = big + pos + 1, and we access up to x + (LITTLE_SIZE - 1)
    if (pos + 1 + LITTLE_SIZE > BIG_SIZE) {
        pos = BIG_SIZE - LITTLE_SIZE - 1;
    }

    // Initialize s and x to trigger the loop logic safely
    s = NULL;
    x = NULL;
}