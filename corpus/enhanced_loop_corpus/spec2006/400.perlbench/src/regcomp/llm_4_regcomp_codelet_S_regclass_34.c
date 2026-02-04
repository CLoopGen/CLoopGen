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
        if (!(((((value) >= 'A' && (value) <= 'Z') || ((value) >= 'a' && (value) <= 'z')) || 
               ((value) >= '0' && (value) <= '9') || (value) == '_') || 
              (((value) >= 33 && (value) <= 47) || ((value) >= 58 && (value) <= 64) || 
               ((value) >= 91 && (value) <= 96) || ((value) >= 123 && (value) <= 126)))) {
            continue;
        }
        (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
    }
}
