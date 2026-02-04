#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int channel_id;
int64_t layout;

void init_vars() {
    i = 32;
    channel_id = 0;
    layout = 1LL << 40;
}