#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ali1;
int nseq = 65536;
int alen = 3840;
int i;

void init_vars() {
    ali1 = (char **)calloc(nseq, sizeof(char *));
    if (!ali1) {
        exit(1);
    }
    for (int idx = 0; idx < nseq; idx++) {
        ali1[idx] = (char *)calloc(alen + 1, sizeof(char));
        if (!ali1[idx]) {
            exit(1);
        }
    }
}