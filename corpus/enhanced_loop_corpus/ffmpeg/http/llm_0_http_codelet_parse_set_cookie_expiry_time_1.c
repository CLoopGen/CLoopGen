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
    for (i = 0; i < exp_buf_len; i++) {
        for (j = 0; exp_str[j] != '\x00' && j < i + 1; j++) {
            if ((exp_str[j] >= '0' && exp_str[j] <= '9') || 
                (exp_str[j] >= 'A' && exp_str[j] <= 'Z') || 
                (exp_str[j] >= 'a' && exp_str[j] <= 'z')) {
                exp_buf[i] = exp_str[j];
                break;
            }
        }
    }
}
