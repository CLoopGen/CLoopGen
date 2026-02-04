#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct huffcodetab {
    unsigned int xlen;
    unsigned int linmax;
    unsigned long *table;
    unsigned char *hlen;
};

struct huffcodetab ht[34];
int max;
int choice1;

void init_vars() {
    max = 1000;

    for (int i = 0; i < 34; i++) {
        ht[i].xlen = 1024;
        ht[i].linmax = (i < 24) ? (max - 10 + i) : (max + (i - 24) * 5);

        ht[i].table = (unsigned long *)calloc(ht[i].xlen, sizeof(unsigned long));
        ht[i].hlen = (unsigned char *)calloc(ht[i].xlen, sizeof(unsigned char));

        for (unsigned int j = 0; j < ht[i].xlen; j++) {
            ht[i].table[j] = j * 37;
            ht[i].hlen[j] = (unsigned char)(j % 256);
        }
    }

    choice1 = 0;
}