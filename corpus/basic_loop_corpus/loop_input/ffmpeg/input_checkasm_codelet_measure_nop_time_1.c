#include <stdint.h>
#include <stddef.h>

uint16_t nops[10000];
int i;
uint64_t t;

void init_vars() {
    t = 42ULL;
    for (i = 0; i < 10000; i++) {
        nops[i] = 0;
    }
    i = 0;
}