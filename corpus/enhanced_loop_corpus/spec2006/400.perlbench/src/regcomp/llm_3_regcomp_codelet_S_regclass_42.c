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
    // Variant 2: Strided memory access — iterate by bit position first, then stride through bytes
    struct regnode_charclass *node = (struct regnode_charclass *)ret;
    for (int bit = 0; bit < 8; bit++) {
        for (UV base = 0; base < 256; base += 8) {
            UV value = base + bit;
            if (value >= 256) continue;
            if ((((value) >= 33 && (value) <= 47) || 
                 ((value) >= 58 && (value) <= 64) || 
                 ((value) >= 91 && (value) <= 96) || 
                 ((value) >= 123 && (value) <= 126))) {
                node->bitmap[(value >> 3) & 31] |= (1 << bit);
            }
        }
    }
}
