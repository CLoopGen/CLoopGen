#include <stdio.h>

#include <inttypes.h>

typedef int I32;

typedef unsigned char U8;

typedef unsigned short U16;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};


typedef struct regnode regnode;

typedef unsigned int U32;

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

typedef unsigned long UV;

extern REGEXP *rx;
extern UV *p;
extern U32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements in startp and endp,
    // access every second element first, then the odd-indexed ones (interleaved stride pattern).
    U32 n = rx->nparens;
    
    // Process even indices first with a stride of 2
    for (i = 0; i <= n; i += 2) {
        *p++ = (UV)rx->startp[i];
        *p++ = (UV)rx->endp[i];
    }
    
    // Then process odd indices with a stride of 2
    for (i = 1; i <= n; i += 2) {
        *p++ = (UV)rx->startp[i];
        *p++ = (UV)rx->endp[i];
    }
}
