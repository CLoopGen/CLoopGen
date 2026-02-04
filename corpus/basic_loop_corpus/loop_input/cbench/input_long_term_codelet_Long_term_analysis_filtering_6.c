#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word Nc = 10;
word *dp;
word *d;
word *dpp;
word *e;
int k;
longword ltmp;

static word *dp_data;
static word *d_data;
static word *dpp_data;
static word *e_data;

void init_vars() {
    size_t array_size = 65536;

    dp_data = (word *)malloc(array_size * sizeof(word));
    d_data = (word *)malloc(array_size * sizeof(word));
    dpp_data = (word *)malloc(array_size * sizeof(word));
    e_data = (word *)malloc(array_size * sizeof(word));

    for (size_t i = 0; i < array_size; i++) {
        dp_data[i] = (word)(i % 32767);
        d_data[i] = (word)((i + 100) % 32767);
        dpp_data[i] = 0;
        e_data[i] = 0;
    }

    dp = dp_data + Nc;
    d = d_data;
    dpp = dpp_data;
    e = e_data;
}