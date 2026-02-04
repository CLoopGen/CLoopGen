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
    UV super_chunk, chunk, byte;
    for (super_chunk = 0; super_chunk < 2; super_chunk++) {
        for (chunk = 0; chunk < 4; chunk++) {
            for (byte = 0; byte < 32; byte++) {
                value = (super_chunk << 8) | (chunk << 3) | byte;
                if (value >= 256) continue;
                if ((((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f') || (value) == '\v'))
                    (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
            }
        }
    }
}
