#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _SkipNode {
    size_t next[9];
    size_t count;
    size_t signature;
} SkipNode;

int level;
SkipNode *root;

void init_vars() {
    root = (SkipNode*)malloc(sizeof(SkipNode));
    if (!root) {
        exit(1);
    }
    for (int i = 0; i < 9; i++) {
        root->next[i] = 0;
    }
    root->count = 0;
    root->signature = 0;
}