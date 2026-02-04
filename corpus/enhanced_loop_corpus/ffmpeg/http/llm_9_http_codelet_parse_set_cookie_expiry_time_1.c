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
    int step = 1;
    for (i = 0, j = 0; exp_str[i] != '\x00' && j + 2 < exp_buf_len; i += step) {
        step = (i % 3 == 0) ? 2 : 1;
        if ((exp_str[i] >= '0' && exp_str[i] <= '9') || 
            (exp_str[i] >= 'A' && exp_str[i] <= 'Z') || 
            (exp_str[i] >= 'a' && exp_str[i] <= 'z')) {
            exp_buf[j] = exp_str[i];
            exp_buf[j+1] = exp_str[i]; 
            j += 2;
        }
    }
}
