#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>

int n;
short *data;
unsigned char *converted;
int i;

void init_vars() {
    n = 1 << 20; // 1 million elements, approximately 2MB input (data) and 1MB output
    data = (short *)aligned_alloc(32, n * sizeof(short));
    converted = (unsigned char *)aligned_alloc(32, n * sizeof(unsigned char));

    for (int j = 0; j < n; j++) {
        data[j] = (short)(rand() % 65535); // fill with arbitrary data in valid short range
    }
}