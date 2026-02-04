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
    for (value = 0; value < 128; ++value) {
        UV offset = value << 1;
        UV fold_low = PL_fold[offset];
        UV fold_high = PL_fold[offset | 1];
        U8 *bm_low = &(((((struct regnode_charclass *)(ret))->bitmap)[(offset >> 3) & 31]));
        U8 *bm_high = &(((((struct regnode_charclass *)(ret))->bitmap)[((offset | 1) >> 3) & 31]));
        U8 mask_low = (1 << (offset & 7));
        U8 mask_high = (1 << ((offset | 1) & 7));

        if (*bm_low & mask_low && fold_low != offset)
            *bm_low |= (1 << (fold_low & 7)) & (fold_low >> 3 == offset >> 3 ? 0xFF : 0);
        
        if (*bm_high & mask_high && fold_high != (offset | 1)) {
            U8 *target_byte = &(((((struct regnode_charclass *)(ret))->bitmap)[(fold_high >> 3) & 31]));
            *target_byte |= (1 << (fold_high & 7));
        }
    }
}
