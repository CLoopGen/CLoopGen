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
    for (UV value = 0; value < 128; value += 2) {
        UV val_upper = value;
        UV val_lower = value + 1;
        U8 cond_upper = !((val_upper >= 'A' && val_upper <= 'Z') || 
                          (val_upper >= 'a' && val_upper <= 'z') || 
                          (val_upper >= '0' && val_upper <= '9'));
        U8 cond_lower = !((val_lower >= 'A' && val_lower <= 'Z') || 
                          (val_lower >= 'a' && val_lower <= 'z') || 
                          (val_lower >= '0' && val_lower <= '9'));
        if (cond_upper)
            (((((struct regnode_charclass *)(ret))->bitmap)[(val_upper >> 3) & 31]) |= (1 << (val_upper & 7)));
        if (cond_lower)
            (((((struct regnode_charclass *)(ret))->bitmap)[(val_lower >> 3) & 31]) |= (1 << (val_lower & 7)));
    }
}
