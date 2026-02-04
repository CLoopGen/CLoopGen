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
for (i = 0 , j = 0; exp_str[i] != '\x00' && j < exp_buf_len; i++) {
    if ((exp_str[i] >= '0' && exp_str[i] <= '9') || (exp_str[i] >= 'A' && exp_str[i] <= 'Z') || (exp_str[i] >= 'a' && exp_str[i] <= 'z')) {
        exp_buf[j] = exp_str[i];
        j++;
    }
}

}
