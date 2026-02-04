#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

extern int *coefs;
extern int len;
extern int s;
extern int i;
extern int c;

static int *local_coefs;
static int local_len;
static int local_s;
static int local_c;
static int local_i;

void init_vars() {
    local_len = 1 << 24; // ~16.7 million elements, roughly 64MB for int array
    local_coefs = (int*)aligned_alloc(32, local_len * sizeof(int));
    if (!local_coefs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < local_len; j++) {
        local_coefs[j] = rand() % 1000 - 500; // Random values between -500 and 499
    }

    local_s = 3; // Must be positive to avoid undefined behavior with left shift by negative count
    local_c = 5;
    local_i = 0;
}

int *coefs = NULL;
int len = 0;
int s = 0;
int i = 0;
int c = 0;

__attribute__((constructor))
static void init() {
    init_vars();
    coefs = local_coefs;
    len = local_len;
    s = local_s;
    c = local_c;
    i = local_i;
}