#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef unsigned char U8;

typedef unsigned short U16;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};


typedef struct regnode regnode;

typedef unsigned int U32;

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};


extern const unsigned char PL_fold[];
extern UV value;
extern regnode *ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-8 iteration
    // Instead of random byte access based on value, process bitmap sequentially in chunks
    unsigned char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (int i = 0; i < 32; ++i) {
        unsigned char byte = bitmap[i];
        if (byte) {
            UV base_val = i << 3;
            for (int bit = 0; bit < 8; ++bit) {
                if (byte & (1 << bit)) {
                    UV value = base_val | bit;
                    UV fold = PL_fold[value];
                    if (fold != value) {
                        int fold_byte_idx = (fold >> 3) & 31;
                        int fold_bit_idx = fold & 7;
                        bitmap[fold_byte_idx] |= (1 << fold_bit_idx);
                    }
                }
            }
        }
    }
}
