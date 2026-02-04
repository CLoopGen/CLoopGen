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

struct unop {
    OP *op_next;
    OP *op_sibling;
    OP *(*op_ppaddr)();
    PADOFFSET op_targ;
    U16 op_type;
    U16 op_seq;
    U8 op_flags;
    U8 op_private;
    OP *op_first;
};

typedef struct unop UNOP;

OP *kid;
OP *k;

#define DATA_SIZE (128 << 20)  // 128 MB

static OP* op_pool;
static int op_count;
static int current_index;

void init_vars() {
    op_count = DATA_SIZE / sizeof(OP);
    op_pool = (OP*)calloc(op_count, sizeof(OP));
    if (!op_pool) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < op_count - 1; i++) {
        op_pool[i].op_next = &op_pool[i + 1];
    }
    op_pool[op_count - 1].op_next = NULL;

    kid = &op_pool[0];
}