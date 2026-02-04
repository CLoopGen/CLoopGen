#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *key;
int keylen;
int s;

void init_vars() {
    // Set data size to achieve approximately 0.01 seconds runtime
    // For a simple loop like this, on a modern CPU, ~64MB should be sufficient
    // to have measurable execution time without being too long
    keylen = 64 * 1024 * 1024; // 64 MB
    key = (char*)malloc(keylen);
    
    if (!key) {
        // In case malloc fails, fallback to smaller size
        keylen = 8 * 1024 * 1024; // 8 MB
        key = (char*)malloc(keylen);
    }
    
    // Initialize most of the array with non-'{' characters
    memset(key, 'A', keylen - 1);
    
    // Place '{' at or near the end to ensure loop runs through much of the data
    key[keylen - 1] = '{';
}

// Force initialization to occur before any call to loop()
__attribute__((constructor))
static void initialize() {
    init_vars();
}