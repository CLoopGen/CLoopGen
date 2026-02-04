#include <stdio.h>
#include <inttypes.h>

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

OP *gvop;

#define DATA_SIZE (1 << 20)  // ~1MB of data, adjust as needed for timing

static OP op_array[DATA_SIZE];

void init_vars() {
    for (int i = 0; i < DATA_SIZE - 1; i++) {
        op_array[i].op_sibling = &op_array[i + 1];
        op_array[i].op_next = NULL;
        op_array[i].op_ppaddr = NULL;
        op_array[i].op_targ = 0;
        op_array[i].op_type = 0;
        op_array[i].op_seq = 0;
        op_array[i].op_flags = 0;
        op_array[i].op_private = 0;
    }
    op_array[DATA_SIZE - 1].op_sibling = NULL;
    op_array[DATA_SIZE - 1].op_next = NULL;
    op_array[DATA_SIZE - 1].op_ppaddr = NULL;
    op_array[DATA_SIZE - 1].op_targ = 0;
    op_array[DATA_SIZE - 1].op_type = 0;
    op_array[DATA_SIZE - 1].op_seq = 0;
    op_array[DATA_SIZE - 1].op_flags = 0;
    op_array[DATA_SIZE - 1].op_private = 0;

    gvop = &op_array[0];
}