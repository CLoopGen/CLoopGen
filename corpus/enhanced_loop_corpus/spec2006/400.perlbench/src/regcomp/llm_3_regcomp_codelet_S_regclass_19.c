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
    // Variant 2: Strided memory access - iterate by bit position first, then stride through bytes
    char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (int i = 0; i < 32; i++) {
        bitmap[i] = 0; // Clear bitmap
    }

    for (int bit = 0; bit < 8; bit++) {
        for (int byte_idx = 0; byte_idx < 32; byte_idx++) {
            UV value = (byte_idx << 3) | bit;
            if ((((value) >= 'A' && (value) <= 'Z') || ((value) >= 'a' && (value) <= 'z')) || 
                ((value) >= '0' && (value) <= '9') || (value) == '_') {
                bitmap[byte_idx] |= (1 << bit);
            }
        }
    }
}
