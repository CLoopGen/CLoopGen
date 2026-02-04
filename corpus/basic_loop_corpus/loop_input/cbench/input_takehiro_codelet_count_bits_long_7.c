#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct huffcodetab {
    unsigned int xlen;
    unsigned int linmax;
    unsigned long *table;
    unsigned char *hlen;
};

struct huffcodetab ht[34];
int ix[576];
int i;
int a1;
int bits;

static unsigned long ht_table_32_data[256];
static unsigned char ht_hlen_32_data[16];

void init_vars() {
    for (int j = 0; j < 34; j++) {
        ht[j].xlen = 0;
        ht[j].linmax = 0;
        ht[j].table = NULL;
        ht[j].hlen = NULL;
    }

    ht[32].xlen = 256;
    ht[32].linmax = 16;
    ht[32].table = ht_table_32_data;
    ht[32].hlen = ht_hlen_32_data;

    for (int j = 0; j < 256; j++) {
        ht_table_32_data[j] = j * 0x12345678UL;
    }

    for (int j = 0; j < 16; j++) {
        ht_hlen_32_data[j] = (j * 7) % 13;
    }

    for (int j = 0; j < 576; j++) {
        ix[j] = (j % 4 == 0) ? 2 : 1;
    }

    i = 576;
    a1 = 0;
    bits = 0;
}