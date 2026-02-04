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

typedef struct _PixelList {
    size_t length;
    size_t seed;
    SkipList skip_list;
    size_t signature;
} PixelList;

PixelList *pixel_list;
ssize_t level;

void init_vars() {
    // Allocate a single SkipNode for the SkipList
    SkipNode *nodes = (SkipNode *)calloc(1, sizeof(SkipNode));
    if (!nodes) exit(1);

    // Initialize node data to ensure predictable behavior
    for (int i = 0; i < 9; i++) {
        nodes->next[i] = 0;
    }
    nodes->count = 0;
    nodes->signature = 0xABCDEF00;

    // Allocate and initialize pixel_list
    pixel_list = (PixelList *)calloc(1, sizeof(PixelList));
    if (!pixel_list) exit(1);

    pixel_list->length = 1;
    pixel_list->seed = 123456789;  // Initial seed value chosen to allow multiple loop iterations
    pixel_list->skip_list.level = 0;
    pixel_list->skip_list.nodes = nodes;
    pixel_list->signature = 0xDEADBEEF;
}