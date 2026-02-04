#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *lsp;
int f[12];
int i;

void init_vars() {
    lsp = (int16_t*)aligned_alloc(32, sizeof(int16_t) * 10);
    if (!lsp) exit(1);
    for (int idx = 0; idx < 10; idx++) {
        lsp[idx] = (int16_t)(idx * 37); 
    }
    for (int idx = 0; idx < 12; idx++) {
        f[idx] = idx * 13;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}