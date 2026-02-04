#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;

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

typedef int I32;

SV **lelem;
SV **firstlelem;
OP *leftop;
I32 i;

#define DATA_SIZE (1 << 20)  // ~1MB of SV pointers

static SV *sv_pool;
static OP *op_chain;

void init_vars() {
    // Allocate pool of SVs
    sv_pool = calloc(DATA_SIZE, sizeof(SV));
    if (!sv_pool) exit(1);

    // Allocate array of SV pointers
    SV **sv_ptr_array = malloc((DATA_SIZE + 1) * sizeof(SV*));
    if (!sv_ptr_array) exit(1);

    // Initialize each SV pointer to point into the pool
    for (int j = 0; j < DATA_SIZE + 1; j++) {
        sv_ptr_array[j] = &sv_pool[j];
    }

    // Set lelem and firstlelem such that difference is DATA_SIZE
    lelem = &sv_ptr_array[DATA_SIZE];
    firstlelem = &sv_ptr_array[0];

    // Allocate a chain of OP structures
    op_chain = calloc(DATA_SIZE + 1, sizeof(OP));
    if (!op_chain) exit(1);

    // Link each op_sibling backwards
    for (int j = 0; j < DATA_SIZE; j++) {
        op_chain[j].op_sibling = &op_chain[j + 1];
    }
    op_chain[DATA_SIZE].op_sibling = NULL;  // terminal

    // Set leftop to the head of the chain so that after (lelem - firstlelem) steps, we end at NULL safely
    leftop = &op_chain[0];
}