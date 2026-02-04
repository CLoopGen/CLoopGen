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
    // Variant 2: Strided memory access - iterate over bytes first, then bits within each byte
    struct regnode_charclass *node = (struct regnode_charclass *)ret;
    for (UV byte_idx = 0; byte_idx < 32; byte_idx++) {
        U8 byte_val = 0;
        for (UV bit = 0; bit < 8; bit++) {
            UV value = (byte_idx << 3) | bit; // Reconstruct original value
            if (!(((value) >= 33 && (value) <= 47) || ((value) >= 58 && (value) <= 64) || ((value) >= 91 && (value) <= 96) || ((value) >= 123 && (value) <= 126))) {
                byte_val |= (1 << bit);
            }
        }
        node->bitmap[byte_idx] = byte_val;
    }
}
