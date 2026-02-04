#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *ix;
int sum;
int sign;
unsigned char *hlen;
int *p;
int i;

static int ix_data[1000000];
static unsigned char hlen_data[256];
static int p_data[1000000];

void init_vars() {
    ix = ix_data;
    p = p_data;
    hlen = hlen_data;
    sum = 0;
    sign = 0;
    i = 0;

    for (int j = 0; j < 1000000; j++) {
        ix_data[j] = (j % 255) + 1;
    }

    for (int j = 0; j < 256; j++) {
        hlen_data[j] = j % 128;
    }

    memset(p_data, 0, sizeof(p_data));
}