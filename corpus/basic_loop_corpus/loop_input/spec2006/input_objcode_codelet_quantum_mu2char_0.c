#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned long long mu;
unsigned char *buf;
int i;
int size;

void init_vars() {
    size = 16777216; // ~16MB, should take around 0.01s on modern CPUs for this loop
    buf = (unsigned char *)malloc(size * sizeof(unsigned char));
    if (!buf) {
        size = 0;
        return;
    }
    mu = 123456789ULL * (unsigned long long)(size); // arbitrary large value for meaningful computation
    memset(buf, 0, size * sizeof(unsigned char));
}