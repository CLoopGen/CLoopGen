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
    size_t temp_next[9];
    for (int level = 0; level < 9; level++)
        temp_next[level] = 65536UL;
    for (int level = 0; level < 9; level++)
        root->next[level] = temp_next[level];
}
