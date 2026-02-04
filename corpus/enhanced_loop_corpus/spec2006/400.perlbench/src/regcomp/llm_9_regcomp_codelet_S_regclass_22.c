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
    for (UV value = 0; value < 512; value++) {
        UV mapped_val = value % 256;
        UV shift_idx = mapped_val >> 3;
        UV bit_pos = mapped_val & 7;
        UV mask = 1ULL << bit_pos;
        U8 is_alpha = (mapped_val >= 'A' && mapped_val <= 'Z');
        U8 is_alphal = (mapped_val >= 'a' && mapped_val <= 'z');
        U8 is_digit = (mapped_val >= '0' && mapped_val <= '9');
        if (!(is_alpha || is_alphal || is_digit)) {
            ((((struct regnode_charclass *)(ret))->bitmap)[shift_idx & 31]) |= mask;
        }
    }
}
