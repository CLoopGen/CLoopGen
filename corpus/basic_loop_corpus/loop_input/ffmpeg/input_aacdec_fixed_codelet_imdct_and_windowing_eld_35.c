#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int INTFLOAT;

INTFLOAT *out;
INTFLOAT *saved;
INTFLOAT *buf;
int i;
int n = 1048576; // 1M elements
int n2;
int n4;
INTFLOAT *window;

void init_vars() {
    n2 = n / 2;
    n4 = n / 4;

    // Allocate arrays with sufficient size to prevent out-of-bounds access
    // Maximum index in buf: i < n2 => max i = n2-1 => buf[n2-1] => need n2 elements
    buf = (INTFLOAT*)calloc(n2, sizeof(INTFLOAT));

    // saved accessed at indices: [n - 1 - i], [n + i], [2*n + n - 1 - i] = [3*n - 1 - i]
    // i from 0 to n2-1 => max index: 3*n - 1 => need 3*n elements
    saved = (INTFLOAT*)calloc(3 * n, sizeof(INTFLOAT));

    // window accessed at: [i + n2 - n4], [i + n2 + n - n4], [i + n2 + 2*n - n4], [i + n2 + 3*n - n4]
    // i up to n2-1 => max offset: (n2-1) + n2 + 3*n - n4 = 2*n2 + 3*n - n4 - 1
    // n2 = n/2, n4 = n/4 => total = 2*(n/2) + 3*n - n/4 - 1 = n + 3n - n/4 -1 = 4n - n/4 -1 = (15n/4)
    int window_size = (15 * n) / 4 + 1;
    window = (INTFLOAT*)calloc(window_size, sizeof(INTFLOAT));

    // out accessed at [n4 + i], i < n2 => indices n4 to n4+n2-1 => need at least n4+n2
    out = (INTFLOAT*)calloc(n4 + n2, sizeof(INTFLOAT));

    // Initialize buffer contents with non-zero values for meaningful computation
    for (int j = 0; j < n2; j++) {
        buf[j] = rand() % 1000 - 500;
    }
    for (int j = 0; j < 3 * n; j++) {
        saved[j] = rand() % 1000 - 500;
    }
    for (int j = 0; j < window_size; j++) {
        window[j] = rand() % 1000 - 500;
    }
    for (int j = 0; j < n4 + n2; j++) {
        out[j] = 0;
    }

    // Ensure consistent behavior across runs
    srand(time(NULL));
}