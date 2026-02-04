#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    // Allocate memory for ret as a regnode_charclass (larger than regnode)
    struct regnode_charclass *charclass_ret = (struct regnode_charclass *)calloc(1, sizeof(struct regnode_charclass));
    
    // Initialize fields to zero; bitmap will be modified by the loop
    charclass_ret->flags = 0;
    charclass_ret->type = 0;
    charclass_ret->next_off = 0;
    charclass_ret->arg1 = 0;
    memset(charclass_ret->bitmap, 0, 32);
    
    // Assign to ret pointer
    ret = (regnode *)charclass_ret;
    
    // Initialize value to 0 (loop control variable)
    value = 0;
}