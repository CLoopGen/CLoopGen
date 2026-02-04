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
    char temp_buf[19];
    int local_j = 0;
    for (i = 0; exp_str[i] != '\x00' && local_j < exp_buf_len; i++) {
        char c = exp_str[i];
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            temp_buf[local_j] = c;
            local_j++;
        }
    }
    // Eliminate loop-carried dependence on global exp_buf and j until loop exit
    for (int idx = 0; idx < local_j; idx++) {
        exp_buf[idx] = temp_buf[idx]; // Final write to shared state outside original loop
    }
    j = local_j; // Update j only once after loop completion (removes loop-carried WAR/WAW)
}
