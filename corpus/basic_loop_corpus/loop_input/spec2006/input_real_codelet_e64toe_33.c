#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short *p;
unsigned short *q;
int i;

static unsigned short buffer_p[6];
static unsigned short buffer_q[6];

void init_vars() {
    p = buffer_p;
    q = buffer_q;
}