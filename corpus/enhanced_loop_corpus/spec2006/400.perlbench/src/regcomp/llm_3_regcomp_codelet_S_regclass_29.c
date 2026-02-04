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
    // Variant 2: Strided memory access — process every 4th character value
    // This changes access pattern to non-unit stride, still covering full range via multiple passes
    char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (int stride = 0; stride < 8; stride++) {
        for (value = stride; value < 256; value += 8) {
            if ((value < ' ' || value == 127)) {
                (((((struct regnode_charclass *)(ret))->bitmap)[(value >> 3) & 31]) |= (1 << (value & 7)));
            }
        }
    }
}
