#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct MLZDict {
    int string_code;
    int parent_code;
    int char_code;
    int match_len;
} MLZDict;

MLZDict *dict;
int i;

void init_vars() {
    dict = (MLZDict*)calloc(35023, sizeof(MLZDict));
    if (!dict) {
        exit(1);
    }
}