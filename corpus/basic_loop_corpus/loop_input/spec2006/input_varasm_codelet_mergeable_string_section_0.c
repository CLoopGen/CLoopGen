#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *str;
int i;
int j;
int len;
int unit;

static char *internal_str;
static int internal_len;
static int internal_unit;

void init_vars() {
    internal_len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    internal_unit = 64;
    
    internal_str = (char *)malloc(internal_len);
    if (!internal_str) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(internal_str, 0, internal_len);

    int pattern_pos = internal_len / 2;
    int zero_run_length = internal_unit + 10;
    if (pattern_pos + zero_run_length <= internal_len) {
        for (int k = 0; k < zero_run_length; k++) {
            internal_str[pattern_pos + k] = '\x00';
        }
    }

    str = internal_str;
    len = internal_len;
    unit = internal_unit;
}