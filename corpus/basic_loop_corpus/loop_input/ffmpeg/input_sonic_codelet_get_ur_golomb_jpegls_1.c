#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit = 10000000;
unsigned int re_index = 0;
__attribute__((unused)) unsigned int re_cache = 0;
unsigned int re_size_plus8 = 32;
int i = 0;

void init_vars() {
    re_cache = 0x40000000U;
    re_index = 0;
    re_size_plus8 = 32;
    i = 0;
    limit = 10000000;
}