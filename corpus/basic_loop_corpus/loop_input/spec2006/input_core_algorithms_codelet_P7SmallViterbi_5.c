#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s *ctr;
struct p7trace_s *tr;
struct p7trace_s **tarr;
int ndom = 1000;
int i;
int pos;
int tpos;
int t2;

void init_vars() {
    // Allocate tr and ctr
    tr = (struct p7trace_s*)calloc(1, sizeof(struct p7trace_s));
    ctr = (struct p7trace_s*)calloc(1, sizeof(struct p7trace_s));

    // Set up sizes to control data volume
    ndom = 1000;
    int max_tlen = 1000;
    int total_length_estimate = ndom * (max_tlen + 10); // Estimate for output size

    // Allocate tr arrays with sufficient space
    tr->tlen = total_length_estimate;
    tr->statetype = (char*)calloc(tr->tlen, sizeof(char));
    tr->nodeidx = (int*)calloc(tr->tlen, sizeof(int));
    tr->pos = (int*)calloc(tr->tlen, sizeof(int));

    // Allocate ctr arrays: pos array of size (ndom*2 + 3) to safely access (i+1)*2+1
    int ctr_pos_size = ndom * 2 + 3;
    ctr->pos = (int*)calloc(ctr_pos_size, sizeof(int));
    // Initialize pos values to create valid ranges
    for (int idx = 0; idx < ctr_pos_size; idx++) {
        ctr->pos[idx] = idx * 5; // Increasing sequence for valid differences
    }

    // Allocate tarr
    tarr = (struct p7trace_s**)calloc(ndom, sizeof(struct p7trace_s*));

    // Allocate each tarr[i] and initialize
    for (int idx = 0; idx < ndom; idx++) {
        tarr[idx] = (struct p7trace_s*)calloc(1, sizeof(struct p7trace_s));
        tarr[idx]->tlen = (idx % 200) + 10; // Vary length between 10 and 210

        // Allocate arrays
        tarr[idx]->statetype = (char*)calloc(tarr[idx]->tlen, sizeof(char));
        tarr[idx]->nodeidx = (int*)calloc(tarr[idx]->tlen, sizeof(int));
        tarr[idx]->pos = (int*)calloc(tarr[idx]->tlen, sizeof(int));

        // Initialize values
        for (int j = 0; j < tarr[idx]->tlen; j++) {
            tarr[idx]->statetype[j] = 'M';
            tarr[idx]->nodeidx[j] = j;
            tarr[idx]->pos[j] = (j % 2 == 0) ? j : -1; // Some positive, some negative
        }
    }

    // Initialize loop indices
    tpos = 0;
}