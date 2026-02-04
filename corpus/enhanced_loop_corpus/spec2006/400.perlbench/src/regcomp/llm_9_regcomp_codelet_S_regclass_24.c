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
    UV limit = 256;
    UV step;
    for (value = 0; value < limit; value++) {
        step = (value & 1) ? 1 : 2;
        UV v1 = value;
        UV v2 = (value + step) & 0xFF;
        
        // Process two values per iteration with conditional bounds check
        if (v1 < 256 && !(((v1) >= 'A' && (v1) <= 'Z') || ((v1) >= 'a' && (v1) <= 'z')))
            (((((struct regnode_charclass *)(ret))->bitmap)[(v1 >> 3) & 31]) |= (1 << (v1 & 7)));

        if (v2 < 256 && !(((v2) >= 'A' && (v2) <= 'Z') || ((v2) >= 'a' && (v2) <= 'z')))
            (((((struct regnode_charclass *)(ret))->bitmap)[(v2 >> 3) & 31]) |= (1 << (v2 & 7)));
        
        value += (step - 1); // Compensate so total increment is 'step'
    }
}
