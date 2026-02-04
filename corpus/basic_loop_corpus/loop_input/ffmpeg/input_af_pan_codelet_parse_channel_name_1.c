#include <inttypes.h>
#include <stdlib.h>

int i;
int channel_id;
int64_t layout;

void init_vars() {
    i = 32;
    channel_id = 0;
    layout = (int64_t)1 << 40;
}