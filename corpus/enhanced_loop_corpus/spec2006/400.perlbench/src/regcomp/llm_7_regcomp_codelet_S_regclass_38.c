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



void loop() {
    UV i, val[256];
    // Precompute values to eliminate loop-carried dependency and create parallelism
    for (i = 0; i < 256; i++) {
        val[i] = i;
    }
    for (i = 0; i < 256; i++) {
        value = val[i]; // Break direct use of loop index; introduce array-based data flow
        if ((((value) > 32 && (value) < 127) || (value) == ' '))
            (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
    }
}
