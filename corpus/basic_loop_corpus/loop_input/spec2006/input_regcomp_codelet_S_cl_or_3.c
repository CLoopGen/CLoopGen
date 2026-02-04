#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

struct regnode_charclass_class *cl;
struct regnode_charclass_class *or_with;
int i;

static struct regnode_charclass_class cl_storage;
static struct regnode_charclass_class or_with_storage;

void init_vars() {
    cl = &cl_storage;
    or_with = &or_with_storage;

    for (int j = 0; j < 32; j++) {
        cl->bitmap[j] = (char)(j * 7);
        or_with->bitmap[j] = (char)(j * 13);
    }

    cl->flags = 1;
    cl->type = 2;
    cl->next_off = 3;
    cl->arg1 = 4;
    memset(cl->classflags, 0x1, sizeof(cl->classflags));

    or_with->flags = 5;
    or_with->type = 6;
    or_with->next_off = 7;
    or_with->arg1 = 8;
    memset(or_with->classflags, 0x2, sizeof(or_with->classflags));
}