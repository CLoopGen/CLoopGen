#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
int *restrict ip;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        b[i] = (real_t)(i * 2);
        ip[i] = i;
        a[i] = 0.0f;
    }
}

// Allocate and initialize ip array
static int _ip_data[32000] __attribute__((aligned(64)));

// Constructor to initialize pointers before main
__attribute__((constructor))
static void init_pointers() {
    ip = _ip_data;
    init_vars();
}