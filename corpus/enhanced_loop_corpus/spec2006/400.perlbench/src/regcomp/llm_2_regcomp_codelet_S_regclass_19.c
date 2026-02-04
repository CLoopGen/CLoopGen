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
    // Variant 1: Consecutive memory access by precomputing index and iterating linearly over bitmap
    char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (int i = 0; i < 32; i++) {
        bitmap[i] = 0; // Clear bitmap
    }

    for (int offset = 0; offset < 32; offset++) {
        for (int bit = 0; bit < 8; bit++) {
            UV value = (offset << 3) | bit;
            if ((((value) >= 'A' && (value) <= 'Z') || ((value) >= 'a' && (value) <= 'z')) || 
                ((value) >= '0' && (value) <= '9') || (value) == '_') {
                bitmap[offset] |= (1 << bit);
            }
        }
    }
}
