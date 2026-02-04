#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned long Hashseq;

char *sequence;
long i;
Hashseq target;

static char data[1 << 20]; // 1MB data size for ~0.01 sec runtime

void init_vars() {
    for (int j = 0; j < sizeof(data) - 1; j++) {
        data[j] = (char)(33 + (j % 94)); // printable ASCII range
    }
    data[sizeof(data) - 1] = 0; // ensure null terminator

    sequence = data;
    i = 0;
    target = 0;
}