#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

integer *idx;
integer *idxp;
integer *idxq;
integer *perm;
integer i__1;
integer j;
integer jp;
integer nlp1;

static integer idx_data[1048576];
static integer idxp_data[1048576];
static integer idxq_data[1048576];
static integer perm_data[1048576];

void init_vars() {
    const size_t N = 1048576; 

    idx = idx_data;
    idxp = idxp_data;
    idxq = idxq_data;
    perm = perm_data;

    i__1 = (integer)N - 1;
    nlp1 = (integer)(N / 2);

    for (size_t i = 0; i < N; ++i) {
        idx[i] = (integer)(i % (N - 1));
        idxp[i] = (integer)(i % N);
        idxq[i] = (integer)(rand() % N);
        perm[i] = 0;
    }
}