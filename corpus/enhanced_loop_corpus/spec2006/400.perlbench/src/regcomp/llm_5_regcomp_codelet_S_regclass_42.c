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
        int in_range = 0;
        if ((value) >= 33 && (value) <= 47) in_range = 1;
        else if ((value) >= 58 && (value) <= 64) in_range = 1;
        else if ((value) >= 91 && (value) <= 96) in_range = 1;
        else if ((value) >= 123 && (value) <= 126) in_range = 1;

        if (in_range) {
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        }
    }
}
