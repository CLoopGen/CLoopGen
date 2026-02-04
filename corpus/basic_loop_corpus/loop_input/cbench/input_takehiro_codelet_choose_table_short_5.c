#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct huffcodetab {
    unsigned int xlen;
    unsigned int linmax;
    unsigned long *table;
    unsigned char *hlen;
};

static unsigned long dummy_table_data[1024];
static unsigned char dummy_hlen_data[1024];

struct huffcodetab ht[34];
int max;
int choice0;
int choice1;

void init_vars() {
    max = 1000;
    choice1 = 32;
    
    for (int i = 0; i < 34; i++) {
        ht[i].xlen = i * 17 + 1;
        ht[i].linmax = (i < 24) ? (i * 50) : (i * 50 + 1000);
        ht[i].table = dummy_table_data;
        ht[i].hlen = dummy_hlen_data;
    }
}