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
    // Variant 1: Consecutive memory access by unrolling and accessing bitmap in increasing order
    char *bm = ((struct regnode_charclass *)ret)->bitmap;
    for (UV i = 0; i < '0'; i += 8) {
        UV end = (i + 8 > '0') ? '0' : i + 8;
        for (UV j = i; j < end; j++) {
            bm[j >> 3] |= (1 << (j & 7));
        }
    }
}
