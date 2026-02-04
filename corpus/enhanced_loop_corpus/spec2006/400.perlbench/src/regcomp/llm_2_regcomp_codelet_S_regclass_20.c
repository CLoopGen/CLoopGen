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
    UV index;
    struct regnode_charclass *node = (struct regnode_charclass *)ret;
    char *bm = node->bitmap;
    for (value = 0; value < 256; value += 4) {
        for (index = 0; index < 4 && (value + index) < 256; ++index) {
            UV v = value + index;
            if (((((v) >= 'A' && (v) <= 'Z') || ((v) >= 'a' && (v) <= 'z')) || ((v) >= '0' && (v) <= '9') || v == '_'))
                continue;
            UV word_offset = (v >> 3) & 31;
            UV bit = 1 << (v & 7);
            bm[word_offset] |= bit;
        }
    }
}
