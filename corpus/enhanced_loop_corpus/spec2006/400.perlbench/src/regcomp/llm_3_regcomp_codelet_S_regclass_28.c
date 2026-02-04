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
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    // Iterates in reverse order with a strided pattern to simulate non-consecutive access,
    // potentially useful in cache behavior analysis or alignment testing.

    UV value_even, value_odd;
    // Process values in reverse, with stride of 2: first even steps down, then odd
    for (value_even = 254; value_even < 256; value_even -= 2) {
        if (!((value_even) == ' ' || (value_even) == '\t'))
            (((((struct regnode_charclass *)(ret))->bitmap)[(value_even >> 3) & 31]) |= (1 << (value_even & 7)));
        value_odd = value_even + 1;
        if (value_odd < 256 && !((value_odd) == ' ' || (value_odd) == '\t'))
            (((((struct regnode_charclass *)(ret))->bitmap)[(value_odd >> 3) & 31]) |= (1 << (value_odd & 7)));
    }
    // Handle value = 1 if started from odd
    if (!((1) == ' ' || (1) == '\t') && 1 < 256)
        (((((struct regnode_charclass *)(ret))->bitmap)[(1 >> 3) & 31]) |= (1 << (1 & 7)));
}
