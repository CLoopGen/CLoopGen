#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *out_funcname;
int j;
char *sha;

void init_vars() {
    size_t out_size = 1024 * 1024; 
    size_t sha_size = 40;

    out_funcname = (char*)malloc(out_size);
    sha = (char*)malloc(sha_size);

    for (size_t i = 0; i < sha_size; i++) {
        sha[i] = 'A' + (i % 26);
    }

    for (size_t i = 0; i < out_size; i++) {
        out_funcname[i] = '\0';
    }
}