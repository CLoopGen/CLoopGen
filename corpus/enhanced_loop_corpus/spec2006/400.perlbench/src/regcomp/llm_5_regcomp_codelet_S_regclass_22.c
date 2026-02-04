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
    for (value = 0; value < 256; value++) {
        int is_alnum = ((value) >= 'A' && (value) <= 'Z');
        is_alnum |= ((value) >= 'a' && (value) <= 'z');
        is_alnum |= ((value) >= '0' && (value) <= '9');

        if (!is_alnum) {
            int index = ((value) >> 3) & 31;
            int bit = (value) & 7;
            (((((struct regnode_charclass *)(ret))->bitmap)[index]) |= (1 << bit));
        }
    }
}
