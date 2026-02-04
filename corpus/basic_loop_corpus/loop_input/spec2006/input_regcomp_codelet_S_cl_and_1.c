#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

struct regnode_charclass_class {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
    char classflags[4];
};

static struct regnode_charclass_class cl_storage;
static struct regnode_charclass_class and_with_storage;

struct regnode_charclass_class *cl = &cl_storage;
struct regnode_charclass_class *and_with = &and_with_storage;
int i;

void init_vars() {
    for (int j = 0; j < 32; j++) {
        cl->bitmap[j] = (char)0xFF;
        and_with->bitmap[j] = (char)(j % 2 ? 0xAA : 0x55);
    }
    cl->flags = 1;
    cl->type = 2;
    cl->next_off = 3;
    cl->arg1 = 4;
    and_with->flags = 5;
    and_with->type = 6;
    and_with->next_off = 7;
    and_with->arg1 = 8;
    memset(cl->classflags, 0x1, 4);
    memset(and_with->classflags, 0x2, 4);
}