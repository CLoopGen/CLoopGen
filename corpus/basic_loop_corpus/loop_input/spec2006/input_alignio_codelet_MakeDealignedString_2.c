#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *aseq;
char *ss;
char *new;
int alen;
int apos;
int rpos;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    alen = data_size;

    aseq = (char *)malloc(alen * sizeof(char));
    ss = (char *)malloc(alen * sizeof(char));
    new = (char *)malloc(alen * sizeof(char));

    if (!aseq || !ss || !new) {
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < alen; i++) {
        int rand_char = rand() % 128;
        if (rand_char < 0) rand_char = -rand_char;
        aseq[i] = (char)rand_char;
        ss[i] = (char)((rand_char + 17) % 128);
    }

    apos = 0;
    rpos = 0;
}