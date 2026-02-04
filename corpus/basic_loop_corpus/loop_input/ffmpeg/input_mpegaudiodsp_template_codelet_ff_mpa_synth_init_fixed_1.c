#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t MPA_INT;

MPA_INT *window;
int i;
int j;

static MPA_INT window_data[1024];

void init_vars() {
    window = window_data;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}