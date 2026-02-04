#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *elem;
int len;
int i;
int vlen;
char *p;
char *vstart;

static char data[1024 * 512]; // 512 KB buffer

void init_vars() {
    // Initialize the data array with mostly non-colon characters
    memset(data, 'x', sizeof(data));
    
    // Place ':' at approximately 75% of the length to ensure loop terminates inside bounds
    int colon_pos = (sizeof(data) * 3) / 4;
    data[colon_pos] = ':';
    
    // Initialize external variables
    elem = data;
    len = sizeof(data);
    i = 0;
    p = NULL;
    vstart = NULL;
    vlen = 0;
}