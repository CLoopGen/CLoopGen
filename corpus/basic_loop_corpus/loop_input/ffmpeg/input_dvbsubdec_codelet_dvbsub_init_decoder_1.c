#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DVBSubCLUT {
    int id;
    int version;
    uint32_t clut4[4];
    uint32_t clut16[16];
    uint32_t clut256[256];
    struct DVBSubCLUT *next;
} DVBSubCLUT;

DVBSubCLUT default_clut;

int i;
int r;
int g;
int b;
int a;

void init_vars() {
    default_clut.id = 0;
    default_clut.version = 1;
    for (int j = 0; j < 4; j++) {
        default_clut.clut4[j] = 0;
    }
    for (int j = 0; j < 16; j++) {
        default_clut.clut16[j] = 0;
    }
    for (int j = 0; j < 256; j++) {
        default_clut.clut256[j] = 0;
    }
    default_clut.next = NULL;

    i = 0;
    r = 0;
    g = 0;
    b = 0;
    a = 0;
}