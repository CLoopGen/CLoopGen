#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

ssize_t i;
size_t count;
ZeroCrossing *zero_crossing;

void init_vars() {
    count = 1000000; // Approximately 1.6MB of data (1e6 * sizeof(ZeroCrossing) ~ 1.6MB)
    zero_crossing = (ZeroCrossing*)calloc(count, sizeof(ZeroCrossing));
    if (!zero_crossing) {
        exit(1);
    }
}