#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *tgt;
char *src;
int len;
int i;
long case_adjust;

static char src_buffer[131072];
static char tgt_buffer[131072];

void init_vars() {
    len = 131072 - 1; 
    case_adjust = 0xFF; 

    for (int j = 0; j < len; j++) {
        src_buffer[j] = 'A' + (j % 26);
    }
    src_buffer[len] = '\x00';

    src = src_buffer;
    tgt = tgt_buffer;
}