#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _SkipNode {
    size_t next[9];
    size_t count;
    size_t signature;
} SkipNode;

extern int level;
extern SkipNode *root;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (level = 8; level >= 0; level--) {
        root->next[level] = 65536UL;
        root->next[level] *= (level + 1);
    }
}
