#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit = 1000000;
unsigned int re_index = 0;
__attribute__((unused)) unsigned int re_cache = 0;
unsigned int re_size_plus8 = 32;
int i = 0;

void init_vars() {
    // No dynamic initialization needed; all variables are statically initialized
}