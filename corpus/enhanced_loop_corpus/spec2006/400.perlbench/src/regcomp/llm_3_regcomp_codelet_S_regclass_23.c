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
    // Variant 2: Strided memory access — iterate by bit position first, then stride through values
    char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (UV bit = 0; bit < 8; bit++) {
        UV shift = bit;
        for (UV base = 0; base < 256; base += 8) {
            UV value = base | shift;
            if (value < 256 && (((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z'))))
                bitmap[(value >> 3) & 31] |= (1 << (value & 7));
        }
    }
}
