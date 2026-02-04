#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char key[4096];
char *p;

void init_vars() {
    for (int i = 0; i < 4095; i++) {
        key[i] = 'A' + (i % 26);
    }
    key[4095] = '=';
    key[4094] = 'X'; 
    key[4093] = 'Y';
    key[4092] = '=';
    key[4091] = 'Z';
}