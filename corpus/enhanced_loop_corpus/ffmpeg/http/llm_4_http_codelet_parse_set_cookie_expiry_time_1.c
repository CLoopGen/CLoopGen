#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *exp_str;
extern char exp_buf[19];
extern int i;
extern int j;
extern int exp_buf_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, j = 0; exp_str[i] != '\x00' && j < exp_buf_len; i++) {
        char c = exp_str[i];
        int is_alnum = (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
        if (!is_alnum) continue;
        exp_buf[j++] = c;
    }
}
