#include <stdio.h>
#include <inttypes.h>
#include <string.h>

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

UV value;
regnode *ret;

void init_vars() {
    static struct regnode_charclass storage = {0};
    ret = (regnode*)&storage;
    memset(storage.bitmap, 0, 32);
}