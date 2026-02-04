#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

UV value;
regnode *ret;

void init_vars() {
    struct regnode_charclass *node = (struct regnode_charclass *)calloc(1, sizeof(struct regnode_charclass));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    ret = (regnode *)node;
}