#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *temp_coefs = coefs;
    int local_len = len;
    for (i = 0; i < local_len; i++) {
        temp_coefs[i] = 0;
    }
}
