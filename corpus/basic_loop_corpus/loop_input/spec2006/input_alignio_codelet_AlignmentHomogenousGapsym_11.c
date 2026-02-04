#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char **aseq;
int nseq;
int alen;
char gapsym;
int i;
int apos;

void init_vars() {
    gapsym = '-';
    nseq = 2000;
    alen = 60000;
    
    aseq = (char**)calloc(nseq, sizeof(char*));
    if (!aseq) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (int idx = 0; idx < nseq; idx++) {
        aseq[idx] = (char*)malloc(alen * sizeof(char));
        if (!aseq[idx]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        
        for (int j = 0; j < alen; j++) {
            int r = rand() % 20;
            if (r == 0) aseq[idx][j] = ' ';
            else if (r == 1) aseq[idx][j] = '.';
            else if (r == 2) aseq[idx][j] = '_';
            else if (r == 3) aseq[idx][j] = '-';
            else if (r == 4) aseq[idx][j] = '~';
            else aseq[idx][j] = 'A' + (rand() % 26);
        }
    }
}