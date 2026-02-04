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
    for (level = 0; level < 18; level += 2) {
        size_t index = level / 2;
        root->next[index] = 65536UL + index * 100;
    }
}
