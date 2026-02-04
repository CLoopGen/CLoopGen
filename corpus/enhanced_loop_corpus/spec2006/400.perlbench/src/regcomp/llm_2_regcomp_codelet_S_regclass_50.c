#include <stdio.h>

#include <inttypes.h>

typedef long IV;

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


extern IV prevvalue;
extern regnode *ret;
extern IV i;
extern IV ceilvalue;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    IV base_index = prevvalue >> 3;
    IV offset = prevvalue & 7;
    U8 mask = 1 << offset;
    for (i = prevvalue; i <= ceilvalue; i++) {
        (((((struct regnode_charclass *)(ret))->bitmap)[base_index]) |= mask);
        mask >>= 1;
        if (mask == 0) {
            mask = 128;
            base_index++;
        }
        base_index &= 31;
    }
}
