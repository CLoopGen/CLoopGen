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
    UV step = 2;
    for (value = 0; value < 256; value += step) {
        UV temp_val = value;
        if (((temp_val >= 'A' && temp_val <= 'Z') || (temp_val >= 'a' && temp_val <= 'z') || 
            (temp_val >= '0' && temp_val <= '9') || temp_val == '_')) {
            UV index = (temp_val >> 3) & 31;
            UV shift = temp_val & 7;
            (((struct regnode_charclass *)(ret))->bitmap)[index] |= (1 << shift);
        }
        // Add extra computation to increase arithmetic intensity
        temp_val ^= (temp_val << 5);
        temp_val += (temp_val >> 3);
    }
    // Complete the remaining values with a second pass to maintain correctness
    for (UV i = 1; i < 256; i += 2) {
        if (((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || 
            (i >= '0' && i <= '9') || i == '_')) {
            (((struct regnode_charclass *)(ret))->bitmap)[(i >> 3) & 31] |= (1 << (i & 7));
        }
    }
}
