#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _SkipNode {
    size_t next[9];
    size_t count;
    size_t signature;
} SkipNode;

typedef struct _SkipList {
    ssize_t level;
    SkipNode *nodes;
} SkipList;

extern  size_t color;
extern SkipList *p;
extern ssize_t level;
extern size_t search;
extern size_t update[9];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (level = p->level; level >= 0; level--) {
        size_t current = search;
        if (!(p->nodes[current].next[level] < color)) {
            update[level] = current;
            continue;
        }
        while (1) {
            size_t next_index = p->nodes[current].next[level];
            if (!(next_index < color)) break;
            current = next_index;
        }
        update[level] = current;
    }
}
