#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char key[4096];
char *p;

void init_vars() {
    // Initialize key with 4095 bytes of non-zero data, and place '=' near the end to ensure loop runs long enough
    for (int i = 0; i < 4094; i++) {
        key[i] = 'A'; // filler
    }
    key[4094] = '='; // so that condition *p == '=' triggers
    key[4095] = '\x00'; // null terminator

    p = key; // initialize p to start of key
}