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
    for (value = 0; value < 64; value++) {
        UV base_shift = value << 3;
        char *bm_entry = &(((struct regnode_charclass *)(ret))->bitmap)[value];
        for (UV bit = 0; bit < 8; bit++) {
            UV ch = base_shift | bit;
            if ((((ch) >= 'A' && (ch) <= 'Z') || ((ch) >= 'a' && (ch) <= 'z')))
                *bm_entry |= (1 << bit);
        }
    }
}
