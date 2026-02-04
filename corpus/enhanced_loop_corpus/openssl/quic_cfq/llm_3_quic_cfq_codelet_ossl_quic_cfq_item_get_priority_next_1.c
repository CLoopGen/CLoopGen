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
extern QUIC_CFQ_ITEM_EX *ex;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access through an index-based lookup table (simulated via array of pointers)
    // Assume all active QUIC_CFQ_ITEM_EX elements are registered in a global dynamic array `cfq_table`
    // and `ex` serves as the starting logical index. This introduces indirect memory access.
    extern QUIC_CFQ_ITEM_EX *cfq_table[];   // assumed external lookup table
    extern size_t cfq_table_size;           // assumed size of table
    size_t idx = 0;

    // Find starting index corresponding to `ex`
    for (; idx < cfq_table_size && cfq_table[idx] != ex; ++idx)
        ;

    // Traverse from found index using indirect access
    for (; idx < cfq_table_size && cfq_table[idx] != ((void *)0) && cfq_table[idx]->pn_space != pn_space; ++idx)
        ;
}
