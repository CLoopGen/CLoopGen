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


extern uint32_t pn_space;
extern QUIC_CFQ_ITEM_EX *item;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; item != ((void *)0); item = item->next) {
        if (item->pn_space == pn_space)
            break;
    }
}
