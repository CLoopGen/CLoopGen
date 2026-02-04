#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *secret_len;
int i;
unsigned char *secret;

void init_vars() {
    static int len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime
    secret_len = &len;
    secret = (unsigned char *)calloc(len, sizeof(unsigned char));
    if (!secret) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i = 0;
}