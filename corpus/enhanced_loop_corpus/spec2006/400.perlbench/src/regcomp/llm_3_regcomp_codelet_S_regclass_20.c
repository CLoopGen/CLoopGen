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


extern UV value;
extern regnode *ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UV byte_idx;
    struct regnode_charclass *node = (struct regnode_charclass *)ret;
    U8 *bm = (U8*)node->bitmap;
    for (byte_idx = 0; byte_idx < 32; ++byte_idx) {
        UV base_val = byte_idx << 3;
        U8 mask = 0;
        UV v;
        for (v = 0; v < 8; ++v) {
            UV val = base_val | v;
            if (!((((val) >= 'A' && (val) <= 'Z') || ((val) >= 'a' && (val) <= 'z')) || ((val) >= '0' && (val) <= '9') || val == '_'))
                mask |= (1 << v);
        }
        bm[byte_idx] |= mask;
    }
}
