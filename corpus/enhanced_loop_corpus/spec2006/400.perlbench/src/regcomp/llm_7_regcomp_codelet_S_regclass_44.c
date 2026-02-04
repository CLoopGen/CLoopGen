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
    UV local_value;
    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    U8 bitmap_cache[32];
    
    // Eliminate loop-carried dependency by using local cache
    for (int i = 0; i < 32; i++)
        bitmap_cache[i] = 0;

    for (local_value = 0; local_value < 256; local_value++) {
        if ((local_value == ' ' || local_value == '\t' || 
             local_value == '\n' || local_value == '\r' || 
             local_value == '\f')) {
            UV idx = (local_value >> 3) & 31;
            UV bit = local_value & 7;
            bitmap_cache[idx] |= (1 << bit);
        }
    }
    
    // Write back cached updates in a single pass (reduces RAW dependencies in loop)
    for (int i = 0; i < 32; i++) {
        rcc->bitmap[i] = bitmap_cache[i];
    }
}
