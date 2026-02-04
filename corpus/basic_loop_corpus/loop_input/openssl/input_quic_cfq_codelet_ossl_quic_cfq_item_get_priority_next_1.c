#include <stdio.h>
#include <stdlib.h>
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

uint32_t pn_space = 1;
QUIC_CFQ_ITEM_EX *ex = NULL;

static QUIC_CFQ_ITEM_EX *items = NULL;
static unsigned char *encoded_data = NULL;

void init_vars() {
    const size_t num_items = 50000;
    encoded_data = malloc(num_items * 256);
    if (!encoded_data) exit(1);

    items = calloc(num_items, sizeof(QUIC_CFQ_ITEM_EX));
    if (!items) exit(1);

    for (size_t i = 0; i < num_items; ++i) {
        items[i].encoded = &encoded_data[i * 256];
        items[i].encoded_len = 256;
        items[i].pn_space = (i == num_items - 1) ? pn_space : (pn_space + 1);
        items[i].frame_type = i;
        items[i].priority = (uint32_t)(i % 100);
        items[i].flags = (uint32_t)i;
        items[i].state = (int)(i % 5);
        items[i].free_cb = NULL;
        items[i].free_cb_arg = NULL;

        if (i > 0) {
            items[i].prev = &items[i - 1];
            items[i - 1].next = &items[i];
        } else {
            items[i].prev = NULL;
        }
    }
    items[num_items - 1].next = NULL;

    ex = &items[0];
}