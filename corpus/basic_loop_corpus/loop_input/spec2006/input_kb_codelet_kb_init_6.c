#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

typedef int32 s3wid_t;

typedef struct {
    s3wid_t wid;
    int32 prob;
} wordprob_t;

int32 i;
int32 n = 1 << 24; // ~67M elements, each wordprob_t is 8 bytes -> ~512MB
wordprob_t *wp;

void init_vars() {
    wp = (wordprob_t*)calloc(n, sizeof(wordprob_t));
    if (!wp) {
        fprintf(stderr, "Failed to allocate memory for wp\n");
        exit(1);
    }
}