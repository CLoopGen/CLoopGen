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
    // Variant 1: Strided memory access with stride of 2, then process in-order
    for (i = 0, j = 0; i < 2 && exp_str[i] != '\x00'; i++) {
        for (int k = i; exp_str[k] != '\x00' && j < exp_buf_len; k += 2) {
            if ((exp_str[k] >= '0' && exp_str[k] <= '9') || 
                (exp_str[k] >= 'A' && exp_str[k] <= 'Z') || 
                (exp_str[k] >= 'a' && exp_str[k] <= 'z')) {
                exp_buf[j] = exp_str[k];
                j++;
            }
        }
    }
}
