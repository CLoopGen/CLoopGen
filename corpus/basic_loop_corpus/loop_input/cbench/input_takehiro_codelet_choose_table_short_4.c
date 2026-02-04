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
        ht[i].xlen = 0;
        ht[i].linmax = (i < 24) ? (max - 10 + i) : (max + (i - 24) * 50);

        size_t table_size = 1 << 16;
        ht[i].table = malloc(table_size * sizeof(unsigned long));
        if (ht[i].table == NULL) {
            exit(1);
        }

        ht[i].hlen = malloc(table_size * sizeof(unsigned char));
        if (ht[i].hlen == NULL) {
            free(ht[i].table);
            exit(1);
        }

        for (size_t j = 0; j < table_size; j++) {
            ht[i].table[j] = j ^ 0xDEADBEEF;
            ht[i].hlen[j] = (unsigned char)(j % 256);
        }
    }
}