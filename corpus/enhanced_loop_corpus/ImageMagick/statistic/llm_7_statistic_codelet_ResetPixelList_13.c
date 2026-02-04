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
    size_t base_value = 65536UL;
    size_t step = 1;
    for (int level = 0; level < 9; level++) {
        root->next[level] = base_value;
        base_value += step; // Introduces WAW and loop-carried dependency on base_value
        step = base_value % 5 + 1;
    }
}
