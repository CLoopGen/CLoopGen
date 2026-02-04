#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int nseq;
int alen;
int M;
int **ins;
int *master_ins;
int apos;
int idx;

void init_vars() {
    // Set data size to target ~0.01 seconds runtime
    // Based on typical performance, use M ~ 10000 and nseq ~ 100 for reasonable workload
    M = 10000;
    nseq = 100;
    alen = 0;

    // Allocate master_ins array of size M+1 (indexed from 0 to M)
    master_ins = (int*)calloc(M + 1, sizeof(int));

    // Allocate ins as array of nseq pointers
    ins = (int**)malloc(nseq * sizeof(int*));
    
    // Allocate each ins[idx] array of size M+1 and initialize with random small values
    for (int i = 0; i < nseq; i++) {
        ins[i] = (int*)malloc((M + 1) * sizeof(int));
        for (int j = 0; j <= M; j++) {
            ins[i][j] = rand() % 5;  // Small positive integers
        }
    }
}