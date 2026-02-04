#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

char src = 'X';
int isrc = 10;
int ksrc = 5;
char dest = 'Y';
int idest = 20;
int kdest = 15;

struct p7trace_s **alignment;
int *min;
int *max;
int *on;
int A = 2000;
int j;
int tpos;
int tnext;
int pos;
int next;
int near;

void init_vars() {
    // Allocate alignment array of A elements
    alignment = (struct p7trace_s **)calloc(A, sizeof(struct p7trace_s *));
    
    // Allocate min, max, on arrays of A integers
    min = (int *)malloc(A * sizeof(int));
    max = (int *)malloc(A * sizeof(int));
    on = (int *)malloc(A * sizeof(int));

    // Set approximate total data size to ~64MB for meaningful runtime (~0.01 sec)
    const int avg_trace_len = 300;  // average length of each trace
    const int total_data_size = A * avg_trace_len;
    
    for (j = 0; j < A; j++) {
        alignment[j] = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
        
        int tlen = avg_trace_len + rand() % 50 - 25; // vary slightly
        if (tlen <= 0) tlen = 1;
        alignment[j]->tlen = tlen;

        alignment[j]->statetype = (char *)malloc(tlen * sizeof(char));
        alignment[j]->nodeidx = (int *)malloc(tlen * sizeof(int));
        alignment[j]->pos = (int *)malloc(tlen * sizeof(int));

        // Initialize valid ranges
        min[j] = 0;
        max[j] = tlen - 1;
        if (max[j] < min[j]) max[j] = min[j];

        // Fill statetype with plausible values: assume 0=D, 1=I, 2=M, 3=S, 4=E, 5=B, 6=G (example)
        for (int i = 0; i < tlen; i++) {
            alignment[j]->statetype[i] = rand() % 8;
            alignment[j]->nodeidx[i] = rand() % 20 + 1;
            alignment[j]->pos[i] = (i % 2 == 0) ? (rand() % 50 + 1) : 0; // some zero positions
        }

        // Ensure boundaries are safe for tnext access
        if (tlen > 1) {
            alignment[j]->statetype[tlen-1] = 4; // terminal state
        }
    }

    // Initialize scalars used in loop
    src = 6;
    dest = 2;
    isrc = 5;
    idest = 15;
    ksrc = 3;
    kdest = 7;
}