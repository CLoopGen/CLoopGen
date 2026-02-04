#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char **rseqs;
int nseq;
char **aseqs;
int alen;
int M;
int **ins;
int *master_ins;
int apos;
int rpos;
int idx;
int statepos;
int count;

void init_vars() {
    nseq = 1000;
    alen = 512;
    M = 100;

    // Allocate and initialize rseqs and aseqs
    rseqs = (char**)calloc(nseq, sizeof(char*));
    aseqs = (char**)calloc(nseq, sizeof(char*));
    for (int i = 0; i < nseq; i++) {
        rseqs[i] = (char*)malloc((alen + M + 10) * sizeof(char));
        aseqs[i] = (char*)malloc((alen + 1) * sizeof(char));
        // Fill rseqs[i] with non-space printable characters
        for (int j = 0; j < alen + M + 10; j++) {
            rseqs[i][j] = 'A' + (i * 789 + j * 31) % 26;
        }
    }

    ins = (int**)malloc(nseq * sizeof(int*));
    for (int i = 0; i < nseq; i++) {
        ins[i] = (int*)calloc(M + 1, sizeof(int));
        for (int j = 0; j <= M; j++) {
            ins[i][j] = (i * 13 + j * 257) % 5; // Small counts to ensure progress in loop
        }
    }

    master_ins = (int*)malloc((M + 1) * sizeof(int));
    for (int j = 0; j <= M; j++) {
        master_ins[j] = (j * 17) % 7; // Ensure master_ins >= ins[idx][statepos]
    }
}