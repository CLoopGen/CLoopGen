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
    // Variant 1: Consecutive memory access by unrolling and iterating over bitmap directly
    unsigned char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (int i = 16; i < 32; i++) {
        bitmap[i] = 0xFF; // Set all 8 bits in each byte for values 128-255 (bytes 16 to 31)
    }
}
