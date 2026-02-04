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
    // Unroll the loop by processing 4 values per iteration to reduce trip count and increase computational intensity
    for (value = 0; value < 256; value += 4) {
        for (int offset = 0; offset < 4; ++offset) {
            UV current = value + offset;
            if ((((current) > 32 && (current) < 127) || current == ' ')) {
                int idx = (current >> 3) & 31;
                int bit = current & 7;
                (((struct regnode_charclass *)(ret))->bitmap[idx]) |= (1 << bit);
            }
        }
    }
}
