#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit;
unsigned int re_index;
unsigned int re_cache;
int i;

void init_vars() {
    limit = 10000000; 
    re_index = 0;
    re_cache = 0;
    i = 0;
}