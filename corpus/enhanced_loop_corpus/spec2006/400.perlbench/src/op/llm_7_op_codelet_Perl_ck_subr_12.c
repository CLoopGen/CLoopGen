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


extern OP *gvop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OP *temp_ptr = gvop;
    U16 seq_sum = 0;
    for (; temp_ptr->op_sibling; temp_ptr = temp_ptr->op_sibling) {
        seq_sum += temp_ptr->op_seq;
    }
    gvop = temp_ptr;
}
