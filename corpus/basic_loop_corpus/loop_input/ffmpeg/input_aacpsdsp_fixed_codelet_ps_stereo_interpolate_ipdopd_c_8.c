#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;
typedef unsigned int UINTFLOAT;

#define DATA_SIZE (64 * 1024)

INTFLOAT (*l)[2];
INTFLOAT (*r)[2];
int len;
INTFLOAT h00;
INTFLOAT h10;
INTFLOAT h01;
INTFLOAT h11;
INTFLOAT h02;
INTFLOAT h12;
INTFLOAT h03;
INTFLOAT h13;
UINTFLOAT hs00;
UINTFLOAT hs10;
UINTFLOAT hs01;
UINTFLOAT hs11;
UINTFLOAT hs02;
UINTFLOAT hs12;
UINTFLOAT hs03;
UINTFLOAT hs13;
int n;

void init_vars() {
    len = DATA_SIZE;
    
    l = (INTFLOAT(*)[2])calloc(len, sizeof(INTFLOAT[2]));
    r = (INTFLOAT(*)[2])calloc(len, sizeof(INTFLOAT[2]));

    for (int i = 0; i < len; i++) {
        l[i][0] = (INTFLOAT)(i * 31);
        l[i][1] = (INTFLOAT)(i * 17 + 1);
        r[i][0] = (INTFLOAT)(i * 13 + 2);
        r[i][1] = (INTFLOAT)(i * 7 + 3);
    }

    h00 = 1000;
    h10 = 500;
    h01 = 900;
    h11 = 450;
    h02 = 800;
    h12 = 400;
    h03 = 700;
    h13 = 350;

    hs00 = 1;
    hs10 = 1;
    hs01 = 1;
    hs11 = 1;
    hs02 = 1;
    hs12 = 1;
    hs03 = 1;
    hs13 = 1;

    n = 0;
}