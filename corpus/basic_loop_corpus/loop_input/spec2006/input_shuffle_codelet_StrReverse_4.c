#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *s1;
char *s2;
int len;
int pos;
char c;

static char s1_buffer[131072];
static char s2_buffer[131072];

void init_vars() {
    len = 131072;
    s1 = s1_buffer;
    s2 = s2_buffer;
    for (int i = 0; i < len; i++) {
        s1[i] = (char)(i & 0xFF);
        s2[i] = (char)((len - i) & 0xFF);
    }
}