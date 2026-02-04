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


extern OP *o2;
extern OP *cvop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    cvop = o2;
    while (cvop->op_sibling && cvop->op_targ < 100) {
        cvop = cvop->op_sibling;
        cvop->op_seq += cvop->op_flags * 2;
    }
}
