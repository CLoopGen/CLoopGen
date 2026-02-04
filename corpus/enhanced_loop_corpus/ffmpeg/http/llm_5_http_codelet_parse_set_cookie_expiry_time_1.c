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
    for (i = 0, j = 0; exp_str[i] != '\x00' && j < exp_buf_len; ) {
        char c = exp_str[i];
        if ((c >= '0' && c <= '9')) {
            exp_buf[j++] = c;
        } else if ((c >= 'A' && c <= 'Z')) {
            exp_buf[j++] = c;
        } else if ((c >= 'a' && c <= 'z')) {
            exp_buf[j++] = c;
        }
        i++;
    }
}
