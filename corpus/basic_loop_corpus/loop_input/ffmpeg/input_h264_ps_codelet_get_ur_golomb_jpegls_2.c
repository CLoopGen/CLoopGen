#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit;
unsigned int re_index;
unsigned int re_cache;
unsigned int re_size_plus8;
int i;

void init_vars() {
    limit = 10000000;
    re_index = 0;
    re_cache = 0;
    re_size_plus8 = 32;
    i = 0;
}