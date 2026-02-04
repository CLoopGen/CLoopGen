#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (1024 * 1024 / sizeof(unsigned long))

unsigned long *ap;
unsigned long *rp;
unsigned long carry;
int nl;
int i;

void init_vars() {
    nl = DATA_SIZE;
    carry = 0x12345678UL;

    ap = (unsigned long *)calloc(nl, sizeof(unsigned long));
    rp = (unsigned long *)calloc(nl, sizeof(unsigned long));

    if (!ap || !rp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < nl; j++) {
        ap[j] = 0xDEADBEEFDEADBEEFUL ^ j;
        rp[j] = 0xBAADF00DBAADF00DUL ^ j;
    }
}