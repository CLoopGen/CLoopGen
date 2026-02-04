#include <stdio.h>
#include <inttypes.h>

typedef struct quic_cfq_item_st QUIC_CFQ_ITEM;

struct quic_cfq_item_st {
    QUIC_CFQ_ITEM *pkt_prev;
    QUIC_CFQ_ITEM *pkt_next;
};

typedef struct quic_cfq_item_ex_st QUIC_CFQ_ITEM_EX;

typedef void (cfq_free_cb)(unsigned char *, size_t, void *);

struct quic_cfq_item_ex_st {
    QUIC_CFQ_ITEM public;
    QUIC_CFQ_ITEM_EX *prev;
    QUIC_CFQ_ITEM_EX *next;
    unsigned char *encoded;
    cfq_free_cb *free_cb;
    void *free_cb_arg;
    uint64_t frame_type;
    size_t encoded_len;
    uint32_t priority;
    uint32_t pn_space;
    uint32_t flags;
    int state;
};

uint32_t pn_space = 3;

static QUIC_CFQ_ITEM_EX items[1024];
static unsigned char encoded_data[1024 * 128]; // 128KB

void init_vars() {
    for (int i = 0; i < 1024; ++i) {
        items[i].public.pkt_prev = (i == 0) ? NULL : &items[i - 1].public;
        items[i].public.pkt_next = (i == 1023) ? NULL : &items[i + 1].public;
        items[i].prev = (i == 0) ? NULL : &items[i - 1];
        items[i].next = (i == 1023) ? NULL : &items[i + 1];
        items[i].encoded = &encoded_data[i * 128];
        items[i].free_cb = NULL;
        items[i].free_cb_arg = NULL;
        items[i].frame_type = 0;
        items[i].encoded_len = 128;
        items[i].priority = 0;
        items[i].pn_space = (i == 1023) ? 3 : 2; // Match at last element
        items[i].flags = 0;
        items[i].state = 0;
    }
}

QUIC_CFQ_ITEM_EX *item = &items[0];