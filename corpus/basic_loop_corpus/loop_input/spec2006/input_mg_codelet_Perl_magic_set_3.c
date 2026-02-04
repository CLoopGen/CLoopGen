#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;

int PL_origargc = 100000;
char **PL_origargv;
I32 i;

void init_vars() {
    PL_origargv = (char**)calloc(PL_origargc, sizeof(char*));
    if (!PL_origargv) {
        PL_origargc = 0;
        return;
    }
    for (int j = 0; j < PL_origargc; j++) {
        PL_origargv[j] = (char*)malloc(1);
        if (PL_origargv[j]) {
            PL_origargv[j][0] = 1;
        }
    }
}