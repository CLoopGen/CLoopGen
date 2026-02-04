#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;
typedef unsigned int U32;

I32 PL_regnpar = 1000000;
I32 PL_regsize = 500000;
I32 *PL_regstartp;
I32 *PL_regendp;
U32 *PL_reglastparen;
U32 paren;

void init_vars() {
    PL_regstartp = (I32*)calloc(PL_regnpar + 1, sizeof(I32));
    PL_regendp = (I32*)calloc(PL_regnpar + 1, sizeof(I32));
    PL_reglastparen = (U32*)malloc(sizeof(U32));
    *PL_reglastparen = 0;
}