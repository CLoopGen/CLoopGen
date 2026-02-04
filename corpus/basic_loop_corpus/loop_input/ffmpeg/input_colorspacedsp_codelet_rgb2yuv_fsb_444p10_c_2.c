#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1048576; // Approximately 4MB of data (1M integers), targets ~0.01 sec on modern CPU
int x;
int rnd = 0xdeadbeef;

static int *scratch_ptr_0_0;
static int *scratch_ptr_0_1;

int *rnd_scratch[3][2];

void init_vars() {
    scratch_ptr_0_0 = (int*)aligned_alloc(32, w * sizeof(int));
    scratch_ptr_0_1 = (int*)aligned_alloc(32, w * sizeof(int));

    if (!scratch_ptr_0_0 || !scratch_ptr_0_1) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    rnd_scratch[0][0] = scratch_ptr_0_0;
    rnd_scratch[0][1] = scratch_ptr_0_1;

    for (int i = 0; i < w; i++) {
        scratch_ptr_0_0[i] = 0;
        scratch_ptr_0_1[i] = 0;
    }

    rnd = rand();
}