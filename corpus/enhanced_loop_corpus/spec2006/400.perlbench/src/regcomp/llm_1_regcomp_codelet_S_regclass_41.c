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
    for (UV chunk = 0; chunk < 32; chunk++) {
        UV base = chunk << 3;
        U8 mask = 0;
        for (UV bit = 0; bit < 8; bit++) {
            UV value = base | bit;
            if (value < 256 && !(((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f') || (value) == '\v')) {
                mask |= (1 << bit);
            }
        }
        if (base < 256) {
            (((struct regnode_charclass *)(ret))->bitmap)[chunk] = mask;
        }
    }
}
