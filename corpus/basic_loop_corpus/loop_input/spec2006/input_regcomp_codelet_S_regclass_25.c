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

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};

UV value;
struct regnode_charclass regnode_data;
struct regnode *ret = (struct regnode *)&regnode_data;

void init_vars() {
    value = 0;
    ret = (struct regnode *)&regnode_data;
}