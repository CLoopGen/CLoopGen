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

extern OP *kid;
extern OP *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OP *temp = ((UNOP *)kid)->op_first;
    OP *prev_kid = NULL;
    for (k = temp; k; k = k->op_next) {
        prev_kid = kid;
        kid = k;
        if (prev_kid && prev_kid->op_type == k->op_type) {
            k->op_seq += prev_kid->op_seq;
        }
    }
}
