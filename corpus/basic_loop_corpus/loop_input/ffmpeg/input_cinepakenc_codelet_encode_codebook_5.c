#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

extern int *codebook;
extern int size;
extern unsigned char *buf;
extern int x;
extern int y;
extern int ret;
extern int entry_size;

int *codebook;
int size;
unsigned char *buf;
int x;
int y;
int ret;
int entry_size;

void init_vars() {
    entry_size = 8;
    size = (1 << 22) / entry_size;  // ~4M total elements, leads to ~32MB codebook
    ret = 0;

    codebook = (int*)malloc(size * entry_size * sizeof(int));
    buf = (unsigned char*)malloc(size * entry_size * sizeof(unsigned char));

    for (int i = 0; i < size * entry_size; i++) {
        codebook[i] = rand() % 256;
    }
}