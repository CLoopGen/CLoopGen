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
    UV base_val;
    for (base_val = 0; base_val < 32; base_val++) {
        UV value1 = base_val * 8;
        UV value2 = value1 + 1;
        UV value3 = value1 + 2;
        UV value4 = value1 + 3;
        UV value5 = value1 + 4;
        UV value6 = value1 + 5;
        UV value7 = value1 + 6;
        UV value8 = value1 + 7;

        // Process 8 values per iteration using unrolled logic
        if (value1 == ' ' || value1 == '\t' || value1 == '\n' || value1 == '\r' || value1 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 0);
        if (value2 == ' ' || value2 == '\t' || value2 == '\n' || value2 == '\r' || value2 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 1);
        if (value3 == ' ' || value3 == '\t' || value3 == '\n' || value3 == '\r' || value3 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 2);
        if (value4 == ' ' || value4 == '\t' || value4 == '\n' || value4 == '\r' || value4 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 3);
        if (value5 == ' ' || value5 == '\t' || value5 == '\n' || value5 == '\r' || value5 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 4);
        if (value6 == ' ' || value6 == '\t' || value6 == '\n' || value6 == '\r' || value6 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 5);
        if (value7 == ' ' || value7 == '\t' || value7 == '\n' || value7 == '\r' || value7 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 6);
        if (value8 == ' ' || value8 == '\t' || value8 == '\n' || value8 == '\r' || value8 == '\f')
            (((struct regnode_charclass *)(ret))->bitmap)[base_val] |= (1 << 7);
    }
}
