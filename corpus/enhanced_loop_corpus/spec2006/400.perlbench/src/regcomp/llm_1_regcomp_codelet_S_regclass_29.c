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
    UV base;
    for (base = 0; base < 256; base += 8) {
        value = base;
        if (((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        value = base + 1;
        if (value < 256 && ((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        value = base + 2;
        if (value < 256 && ((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        value = base + 3;
        if (value < 256 && ((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        value = base + 4;
        if (value < 256 && ((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        value = base + 5;
        if (value < 256 && ((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        value = base + 6;
        if (value < 256 && ((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        value = base + 7;
        if (value < 256 && ((value) < ' ' || (value) == 127))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
    }
}
