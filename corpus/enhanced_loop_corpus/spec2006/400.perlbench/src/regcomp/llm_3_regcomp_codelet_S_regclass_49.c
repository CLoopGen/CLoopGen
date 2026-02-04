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
    // Variant 2: Strided memory access with reverse traversal and stride of 4
    // Access values in a strided pattern (every 4th element) in reverse order
    // This changes both access pattern and iteration order to alter cache behavior
    UV value;
    // Reverse strided loop: starts from 252 down to 0, step -4
    for (value = 252; value < 256; value -= 4) {
        UV v;
        // Process a group of 4 consecutive values per stride
        for (v = 0; v < 4; v++) {
            UV current = value + v;
            if (current >= 256) continue;
            if (!(((current) >= '0' && (current) <= '9') || ((current) >= 'a' && (current) <= 'f') || ((current) >= 'A' && (current) <= 'F')))
                (((((struct regnode_charclass *)(ret))->bitmap)[(current >> 3) & 31]) |= (1 << (current & 7)));
        }
    }
}
