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
    OP **ptr_array = &gvop;
    for (; (*ptr_array)->op_sibling; ptr_array = (OP**)(&(*ptr_array)->op_sibling))
        ;
    gvop = *ptr_array;
}
