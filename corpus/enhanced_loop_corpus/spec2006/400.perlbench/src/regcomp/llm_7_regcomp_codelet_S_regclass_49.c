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
    UV temp_value;
    // Eliminate loop-carried dependency by unrolling and batching operations
    for (value = 0; value < 256; value += 4) {
        // Process 4 iterations independently to reduce RAW hazards
        for (int offset = 0; offset < 4; offset++) {
            temp_value = value + offset;
            if (temp_value >= 256) break;
            if (!(((temp_value) >= '0' && (temp_value) <= '9') || 
                  ((temp_value) >= 'a' && (temp_value) <= 'f') || 
                  ((temp_value) >= 'A' && (temp_value) <= 'F'))) {
                (((((struct regnode_charclass *)(ret))->bitmap)[(temp_value >> 3) & 31]) |= (1 << (temp_value & 7)));
            }
        }
    }
}
