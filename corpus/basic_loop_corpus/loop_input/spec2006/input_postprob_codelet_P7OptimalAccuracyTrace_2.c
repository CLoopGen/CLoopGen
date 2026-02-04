#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

int M = 1000;
struct p7trace_s *tr;
int tpos = 0;
int i = 500;
int k;

int **xmx;
int **mmx;

void init_vars() {
    // Allocate tr structure
    tr = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
    tr->tlen = 1000;
    tr->statetype = (char *)calloc(tr->tlen, sizeof(char));
    tr->nodeidx = (int *)calloc(tr->tlen, sizeof(int));
    tr->pos = (int *)calloc(tr->tlen, sizeof(int));

    // Allocate xmx and mmx as 2D arrays with dimensions [i+1][M+1] to prevent out-of-bounds access
    int rows = i + 10; // Add padding for safety
    int cols = M + 1;

    xmx = (int **)calloc(rows, sizeof(int *));
    mmx = (int **)calloc(rows, sizeof(int *));
    for (int r = 0; r < rows; r++) {
        xmx[r] = (int *)calloc(cols, sizeof(int));
        mmx[r] = (int *)calloc(cols, sizeof(int));
    }

    // Initialize xmx[i][1] and mmx[i][k] so that the condition can be true when k=M
    // Set up so that on first iteration (k=M), the condition triggers and loop breaks
    if (i >= 0 && M >= 1) {
        xmx[i][1] = 42;
        mmx[i][M] = 42;
    }

    // Ensure other values won't trigger break prematurely
    for (int kk = M-1; kk >= 1; kk--) {
        if (i > 0) {
            mmx[i][kk] = 0; // not equal to xmx[i][1]
        }
    }
}