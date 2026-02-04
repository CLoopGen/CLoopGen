#include <inttypes.h>

unsigned short *q;
int i;

static unsigned short q_buffer[128 * 1024]; // 256KB of data (128k elements)

void init_vars() {
    q = q_buffer;
}