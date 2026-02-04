#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned char DES_cblock[8];

char *str;
DES_cblock *key1;
DES_cblock *key2;
int i;
size_t length;

static char str_buf[512 * 1024];
static DES_cblock key1_buf;
static DES_cblock key2_buf;

void init_vars() {
    length = sizeof(str_buf);
    str = str_buf;
    key1 = &key1_buf;
    key2 = &key2_buf;
    
    for (size_t idx = 0; idx < length; idx++) {
        str[idx] = (char)(idx & 0xFF);
    }
    
    memset(key1_buf, 0, sizeof(DES_cblock));
    memset(key2_buf, 0, sizeof(DES_cblock));
    
    i = 0;
}