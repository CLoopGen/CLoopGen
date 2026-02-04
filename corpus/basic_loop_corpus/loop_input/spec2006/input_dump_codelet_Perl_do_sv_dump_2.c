#include <stdio.h>
#include <inttypes.h>

typedef double NV;

int freq[200];
int i;
int max;
NV sum;

void init_vars() {
    max = 199;
    sum = 0.0;
    for (i = 0; i < 200; i++) {
        freq[i] = i * 2 + 1;
    }
}