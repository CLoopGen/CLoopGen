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
    static struct regnode_charclass reg_data = {0};
    ret = (regnode*)&reg_data;
}