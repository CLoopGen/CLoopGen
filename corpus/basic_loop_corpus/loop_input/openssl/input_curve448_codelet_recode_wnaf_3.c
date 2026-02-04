#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct smvt_control {
    int power;
    int addend;
};

struct smvt_control *control;
int position;
unsigned int n;
unsigned int i;

void init_vars() {
    n = 262144; // 262144 elements * 8 bytes = ~2MB, ensures loop runs long enough (~0.01 sec on modern CPU)
    position = 1; // Ensure control[i + position] is in bounds for i < n-1

    control = aligned_alloc(32, (n + position) * sizeof(struct smvt_control));
    if (!control) {
        exit(1);
    }

    for (unsigned int idx = 0; idx < n + position; ++idx) {
        control[idx].power = idx;
        control[idx].addend = idx * 2;
    }
}