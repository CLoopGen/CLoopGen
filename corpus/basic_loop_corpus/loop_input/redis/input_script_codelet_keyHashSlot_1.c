#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    // Allocate a large buffer to ensure loop takes ~0.01 seconds
    // Assume modern CPU can scan ~1-2 GB/s, so 10-20 MB should take ~0.01s
    keylen = 16 * 1024 * 1024; // 16 MB
    key = (char*)malloc(keylen);
    
    if (!key) {
        keylen = 0;
        return;
    }
    
    // Fill with 'a' except place a '}' near the end to trigger break
    memset(key, 'a', keylen - 1);
    key[keylen - 1] = '}';
    
    // Set initial value of s such that s+1 is valid and loop can run
    s = keylen / 2;  // Start halfway through
    e = s;           // Will be incremented in loop
}