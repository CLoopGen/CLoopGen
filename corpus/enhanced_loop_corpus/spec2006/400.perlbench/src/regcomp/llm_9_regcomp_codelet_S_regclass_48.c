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
    // Unroll the loop by processing 4 values per iteration to reduce trip count and increase arithmetic density
    for (value = 0; value < 256; value += 4) {
        UV v0 = value;
        UV v1 = value + 1;
        UV v2 = value + 2;
        UV v3 = value + 3;

        if ((v0 >= '0' && v0 <= '9') || (v0 >= 'a' && v0 <= 'f') || (v0 >= 'A' && v0 <= 'F'))
            ((((struct regnode_charclass *)(ret))->bitmap)[(v0 >> 3) & 31]) |= (1 << (v0 & 7));

        if (v1 < 256 && ((v1 >= '0' && v1 <= '9') || (v1 >= 'a' && v1 <= 'f') || (v1 >= 'A' && v1 <= 'F')))
            ((((struct regnode_charclass *)(ret))->bitmap)[(v1 >> 3) & 31]) |= (1 << (v1 & 7));

        if (v2 < 256 && ((v2 >= '0' && v2 <= '9') || (v2 >= 'a' && v2 <= 'f') || (v2 >= 'A' && v2 <= 'F')))
            ((((struct regnode_charclass *)(ret))->bitmap)[(v2 >> 3) & 31]) |= (1 << (v2 & 7));

        if (v3 < 256 && ((v3 >= '0' && v3 <= '9') || (v3 >= 'a' && v3 <= 'f') || (v3 >= 'A' && v3 <= 'F')))
            ((((struct regnode_charclass *)(ret))->bitmap)[(v3 >> 3) & 31]) |= (1 << (v3 & 7));
    }
}
