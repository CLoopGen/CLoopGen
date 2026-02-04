#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum ws_interval_type {
    WS_SINE = (('S') | (('I') << 8) | (('N') << 16) | ((unsigned int)('E') << 24)),
    WS_NOISE = (('N') | (('O') << 8) | (('I') << 16) | ((unsigned int)('S') << 24))
};

struct ws_interval {
    int64_t ts_start;
    int64_t ts_end;
    uint64_t phi0;
    uint64_t dphi0;
    uint64_t ddphi;
    uint64_t amp0;
    uint64_t damp;
    uint64_t phi;
    uint64_t dphi;
    uint64_t amp;
    uint32_t channels;
    enum ws_interval_type type;
    int next;
};

int32_t *channels;
int32_t *cv;
unsigned int val;
struct ws_interval *in;
uint32_t c;

static int32_t *channels_buf;
static struct ws_interval *in_buf;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB of channel data (1M int32_t elements)

    channels_buf = calloc(data_size, sizeof(int32_t));
    if (!channels_buf) exit(1);

    in_buf = malloc(sizeof(struct ws_interval));
    if (!in_buf) exit(1);

    // Initialize in
    in_buf->channels = 0xAAAAAAAA; // Multiple bits set (32-bit mask)
    in_buf->ts_start = 0;
    in_buf->ts_end = 1000;
    in_buf->phi0 = 100;
    in_buf->dphi0 = 10;
    in_buf->ddphi = 1;
    in_buf->amp0 = 500;
    in_buf->damp = 5;
    in_buf->phi = 0;
    in_buf->dphi = 0;
    in_buf->amp = 0;
    in_buf->type = WS_SINE;
    in_buf->next = -1;

    // Link external pointers
    channels = channels_buf;
    in = in_buf;
    val = 42; // Arbitrary non-zero value
    cv = NULL;
    c = 0;
}

__attribute__((constructor)) void auto_init() {
    init_vars();
}