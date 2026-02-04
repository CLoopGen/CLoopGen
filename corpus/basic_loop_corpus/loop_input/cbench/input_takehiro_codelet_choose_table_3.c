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

struct huffcodetab ht[34];
int max;
int choice0;
int choice1;

void init_vars() {
    // Set reasonable values for control variables
    choice1 = 16;  // Ensures loop starts at choice1 - 8 = 8
    max = 1000;    // A value that won't cause immediate break in loop

    // Allocate and initialize each element of ht
    for (int i = 0; i < 34; i++) {
        ht[i].xlen = 256;
        ht[i].linmax = (i >= choice1 - 8) ? 1500 : 500; // Ensure condition triggers break only when intended

        // Allocate table and hlen arrays of size 256 to match typical Huffman table sizes
        ht[i].table = (unsigned long *)calloc(256, sizeof(unsigned long));
        ht[i].hlen = (unsigned char *)calloc(256, sizeof(unsigned char));

        // Initialize with dummy data
        for (int j = 0; j < 256; j++) {
            ht[i].table[j] = (unsigned long)(j * i);
            ht[i].hlen[j] = (unsigned char)(j % 16);
        }
    }
}