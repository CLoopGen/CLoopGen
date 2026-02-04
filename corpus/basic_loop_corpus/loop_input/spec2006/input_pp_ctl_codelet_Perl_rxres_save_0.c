#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef unsigned long UV;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};

typedef struct regnode regnode;

struct reg_substr_data {};
struct reg_data {};

struct regexp {
    I32 *startp;
    I32 *endp;
    regnode *regstclass;
    struct reg_substr_data *substrs;
    char *precomp;
    struct reg_data *data;
    char *subbeg;
    U32 *offsets;
    I32 sublen;
    I32 refcnt;
    I32 minlen;
    I32 prelen;
    U32 nparens;
    U32 lastparen;
    U32 lastcloseparen;
    U32 reganch;
    regnode program[1];
};

typedef struct regexp REGEXP;

REGEXP *rx;
UV *p;
U32 i;

static I32 *startp_data;
static I32 *endp_data;
static regnode *program_data;
static UV *p_buffer;

void init_vars() {
    const size_t data_size = 1 << 20;
    rx = (REGEXP*)malloc(sizeof(REGEXP));
    startp_data = (I32*)calloc(data_size, sizeof(I32));
    endp_data = (I32*)calloc(data_size, sizeof(I32));
    program_data = (regnode*)calloc(data_size, sizeof(regnode));
    p_buffer = (UV*)calloc(data_size * 2, sizeof(UV));

    for (size_t idx = 0; idx < data_size; ++idx) {
        startp_data[idx] = (I32)(idx * 2);
        endp_data[idx] = (I32)(idx * 2 + 1);
    }

    rx->startp = startp_data;
    rx->endp = endp_data;
    rx->regstclass = NULL;
    rx->substrs = NULL;
    rx->precomp = NULL;
    rx->data = NULL;
    rx->subbeg = NULL;
    rx->offsets = NULL;
    rx->sublen = 0;
    rx->refcnt = 1;
    rx->minlen = 0;
    rx->prelen = 0;
    rx->nparens = (U32)(data_size - 1);
    rx->lastparen = 0;
    rx->lastcloseparen = 0;
    rx->reganch = 0;
    memcpy(program_data, rx->program, sizeof(regnode));
    rx->program[0] = program_data[0];

    p = p_buffer;
}