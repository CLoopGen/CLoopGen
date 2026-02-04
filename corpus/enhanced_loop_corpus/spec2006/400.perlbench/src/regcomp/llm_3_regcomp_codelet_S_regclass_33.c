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
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    // Accesses are now non-sequential, stepping through every second element first forward, then backward
    U8* bitmap = ((struct regnode_charclass *)(ret))->bitmap;
    UV start = '9' + 1;
    UV end = 256;

    // First pass: strided forward — even offsets
    for (UV value = start + ((start % 2) == 0 ? 0 : 1); value < end; value += 2) {
        bitmap[(value >> 3) & 31] |= (1 << (value & 7));
    }
    // Second pass: strided backward — odd offsets
    for (UV value = end - 1 - ((end - 1) % 2 == 0 ? 1 : 0); value >= start; value -= 2) {
        if (value < start) break; // Prevent underflow due to unsigned
        bitmap[(value >> 3) & 31] |= (1 << (value & 7));
    }
}
