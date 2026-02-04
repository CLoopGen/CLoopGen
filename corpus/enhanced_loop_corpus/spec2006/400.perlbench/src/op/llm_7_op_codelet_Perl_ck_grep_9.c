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
    OP *current;
    OP *next_ptr;
    for (current = ((UNOP *)kid)->op_first; current != NULL; current = next_ptr) {
        next_ptr = current->op_next;
        current->op_private ^= 0xFF; 
        if (current->op_flags & 1) {
            current->op_targ = 0;
        }
        kid = current; 
    }
}
