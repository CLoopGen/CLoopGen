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
        size_t temp_search = search;
        size_t next_node = p->nodes[temp_search].next[level];
        if (next_node < color) {
            temp_search = next_node;
            while (p->nodes[temp_search].next[level] < color) {
                temp_search = p->nodes[temp_search].next[level];
            }
        }
        update[level] = temp_search;
    }
}
