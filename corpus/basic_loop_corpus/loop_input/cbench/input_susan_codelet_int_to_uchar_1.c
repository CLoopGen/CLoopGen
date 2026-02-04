#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

typedef unsigned char uchar;

int *r;
uchar *in;
int size;
int i;
int max_r;
int min_r;

void init_vars() {
    size = 64 * 1024 * 1024; // Approx. 256MB of data (64M integers for r, 64M bytes for in)

    // Allocate memory
    r = (int*)aligned_alloc(32, size * sizeof(int));
    in = (uchar*)aligned_alloc(32, size * sizeof(uchar));

    // Initialize min_r and max_r
    min_r = 100;
    max_r = 1000;

    // Initialize r with sample data to ensure meaningful computation
    for (int idx = 0; idx < size; idx++) {
        r[idx] = min_r + (rand() % (max_r - min_r + 1));
    }

    // Initialize loop index variable
    i = 0;
}