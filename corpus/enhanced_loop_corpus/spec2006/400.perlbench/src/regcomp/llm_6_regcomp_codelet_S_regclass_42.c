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
    UV local_value;
    U8 temp_bitmap[32] = {0};
    struct regnode_charclass *ret_cast = (struct regnode_charclass *)ret;

    for (local_value = 0; local_value < 256; local_value++) {
        if ((((local_value) >= 33 && (local_value) <= 47) || 
             ((local_value) >= 58 && (local_value) <= 64) || 
             ((local_value) >= 91 && (local_value) <= 96) || 
             ((local_value) >= 123 && (local_value) <= 126))) {
            U32 index = (local_value >> 3) & 31;
            U32 bit = 1 << (local_value & 7);
            temp_bitmap[index] |= bit;
        }
    }

    for (int i = 0; i < 32; i++) {
        ret_cast->bitmap[i] |= temp_bitmap[i];
    }
}
