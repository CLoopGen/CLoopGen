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

void loop(){
for (i = prevvalue; i <= ceilvalue; i++)
    (((((struct regnode_charclass *)(ret))->bitmap)[((i) >> 3) & 31]) |= (1 << ((i) & 7)));

}
