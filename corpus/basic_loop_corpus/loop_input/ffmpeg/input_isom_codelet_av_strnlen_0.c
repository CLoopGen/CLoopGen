#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static size_t internal_len;

void init_vars() {
    internal_len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    internal_s = (char*)malloc(internal_len);
    if (!internal_s) {
        exit(1);
    }
    
    // Fill with non-zero bytes to simulate typical string data
    memset(internal_s, 'x', internal_len - 1);
    // Place null terminator near the end to ensure loop runs long but terminates
    internal_s[internal_len - 1] = '\0';
    
    s = internal_s;
    len = internal_len;
    i = 0;
}