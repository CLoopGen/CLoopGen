#include <stdio.h>
#include <inttypes.h>

typedef unsigned long UV;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};

typedef struct regnode regnode;

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};

UV value;
regnode *ret;

void init_vars() {
    static struct regnode_charclass regnode_instance = {0};
    ret = (regnode*)&regnode_instance;
}

// Ensure the loop runs with bounded memory access and valid data
// The loop runs from 0 to '0' (48), which is within bounds of bitmap[32] when index is ((value) >> 3) & 31
// Maximum index: (47 >> 3) & 31 = 5 & 31 = 5, so only uses first 6 bytes of bitmap – safe.