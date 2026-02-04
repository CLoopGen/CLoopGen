#include <stdio.h>
#include <inttypes.h>

typedef long IV;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};

IV prevvalue;
struct regnode *ret;
IV i;
IV ceilvalue;

static struct regnode_charclass internal_regnode_charclass;

void init_vars() {
    prevvalue = 0;
    ceilvalue = 255; 
    ret = (struct regnode*)&internal_regnode_charclass;
}