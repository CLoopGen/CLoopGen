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
    UV temp_value;
    struct regnode_charclass *node = (struct regnode_charclass *)ret;
    for (temp_value = '9' + 1; temp_value < 256; temp_value++) {
        value = temp_value;
        ((node->bitmap[(value >> 3) & 31]) |= (1 << (value & 7)));
    }
}
