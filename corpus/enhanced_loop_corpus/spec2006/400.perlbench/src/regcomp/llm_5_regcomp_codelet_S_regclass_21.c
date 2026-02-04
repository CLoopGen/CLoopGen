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
    int is_alnum;
    for (value = 0; value < 256; value++) {
        is_alnum = 0;
        if (value >= 'A' && value <= 'Z')
            is_alnum = 1;
        else if (value >= 'a' && value <= 'z')
            is_alnum = 1;
        else if (value >= '0' && value <= '9')
            is_alnum = 1;

        if (is_alnum)
            (((struct regnode_charclass *)ret)->bitmap[(value >> 3) & 31]) |= (1 << (value & 7));
    }
}
