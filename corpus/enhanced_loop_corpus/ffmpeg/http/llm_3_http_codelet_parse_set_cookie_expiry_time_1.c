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
    // Variant 2: Consecutive reverse traversal of exp_str
    int len = 0;
    while (exp_str[len] != '\x00') len++; // Compute length without using standard library

    for (i = len - 1, j = 0; i >= 0 && j < exp_buf_len; i--) {
        if ((exp_str[i] >= '0' && exp_str[i] <= '9') || 
            (exp_str[i] >= 'A' && exp_str[i] <= 'Z') || 
            (exp_str[i] >= 'a' && exp_str[i] <= 'z')) {
            exp_buf[j] = exp_str[i];
            j++;
        }
    }
}
