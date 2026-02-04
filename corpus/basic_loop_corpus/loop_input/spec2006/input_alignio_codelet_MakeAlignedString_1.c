#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *aseq;
int alen;
char *ss;
char *new;
int apos;
int rpos;

void init_vars() {
    alen = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU

    aseq = (char *)malloc(alen);
    ss = (char *)malloc(alen);
    new = (char *)malloc(alen);

    if (!aseq || !ss || !new) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < alen; i++) {
        int choice = rand() % 8;
        switch (choice) {
            case 0: aseq[i] = ' '; break;
            case 1: aseq[i] = '.'; break;
            case 2: aseq[i] = '_'; break;
            case 3: aseq[i] = '-'; break;
            case 4: aseq[i] = '~'; break;
            default: aseq[i] = 'A' + (rand() % 26); break;
        }
        ss[i] = 'a' + (i % 26);
    }

    apos = 0;
    rpos = 0;
}