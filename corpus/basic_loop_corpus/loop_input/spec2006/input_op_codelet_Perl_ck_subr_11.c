#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct op OP;

typedef unsigned long PADOFFSET;
typedef unsigned short U16;
typedef unsigned char U8;

struct op {
    OP *op_next;
    OP *op_sibling;
    OP *(*op_ppaddr)();
    PADOFFSET op_targ;
    U16 op_type;
    U16 op_seq;
    U8 op_flags;
    U8 op_private;
};

OP *o2 = NULL;
OP *cvop = NULL;

#define DATA_SIZE (128 << 20)  // 128 MB

static OP* op_pool = NULL;

void init_vars() {
    if (op_pool) return;  // already initialized

    op_pool = calloc(DATA_SIZE, 1);
    if (!op_pool) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    size_t num_ops = DATA_SIZE / sizeof(OP);
    for (size_t i = 0; i < num_ops - 1; i++) {
        op_pool[i].op_next = &op_pool[i + 1];
        op_pool[i].op_sibling = &op_pool[i + 1];
        op_pool[i].op_ppaddr = NULL;
        op_pool[i].op_targ = 0;
        op_pool[i].op_type = 0;
        op_pool[i].op_seq = 0;
        op_pool[i].op_flags = 0;
        op_pool[i].op_private = 0;
    }
    // Last element points to NULL
    op_pool[num_ops - 1].op_next = NULL;
    op_pool[num_ops - 1].op_sibling = NULL;
    op_pool[num_ops - 1].op_ppaddr = NULL;
    op_pool[num_ops - 1].op_targ = 0;
    op_pool[num_ops - 1].op_type = 0;
    op_pool[num_ops - 1].op_seq = 0;
    op_pool[num_ops - 1].op_flags = 0;
    op_pool[num_ops - 1].op_private = 0;

    o2 = &op_pool[0];
    cvop = o2;
}