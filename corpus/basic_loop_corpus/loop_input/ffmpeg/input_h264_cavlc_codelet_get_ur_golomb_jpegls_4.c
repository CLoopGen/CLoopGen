#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit = 1000000;
unsigned int re_index = 0;
__attribute__((unused)) unsigned int re_cache = 0x40000000;
int i = 0;

void init_vars() {
    re_cache = 0x40000000;
    re_index = 0;
    i = 0;
    limit = 1000000;
}