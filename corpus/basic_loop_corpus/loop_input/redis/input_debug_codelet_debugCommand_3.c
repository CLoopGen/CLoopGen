#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct quicklistNode {
    struct quicklistNode *prev;
    struct quicklistNode *next;
    unsigned char *entry;
    size_t sz;
    unsigned int count : 16;
    unsigned int encoding : 2;
    unsigned int container : 2;
    unsigned int recompress : 1;
    unsigned int attempted_compress : 1;
    unsigned int dont_compress : 1;
    unsigned int extra : 9;
} quicklistNode;

typedef struct quicklistBookmark {
    quicklistNode *node;
    char *name;
} quicklistBookmark;

typedef struct quicklist {
    quicklistNode *head;
    quicklistNode *tail;
    unsigned long count;
    unsigned long len;
    size_t alloc_size;
    int fill : 16;
    unsigned int compress : 16;
    unsigned int bookmark_count : 4;
    quicklistBookmark bookmarks[];
} quicklist;

quicklist *ql;
unsigned long sz;

static quicklistNode* nodes;
static unsigned char** entries;

void init_vars() {
    const int num_nodes = 100000;
    const size_t entry_size = 100;

    nodes = calloc(num_nodes, sizeof(quicklistNode));
    entries = calloc(num_nodes, sizeof(unsigned char*));

    for (int i = 0; i < num_nodes; i++) {
        entries[i] = calloc(entry_size, sizeof(unsigned char));
        nodes[i].sz = entry_size;
        nodes[i].entry = entries[i];
        nodes[i].encoding = 0;
        nodes[i].container = 0;
        nodes[i].recompress = 0;
        nodes[i].attempted_compress = 0;
        nodes[i].dont_compress = 0;
        nodes[i].extra = 0;
        nodes[i].count = 1;

        if (i > 0) {
            nodes[i].prev = &nodes[i-1];
        } else {
            nodes[i].prev = NULL;
        }
        if (i < num_nodes - 1) {
            nodes[i].next = &nodes[i+1];
        } else {
            nodes[i].next = NULL;
        }
    }

    ql = malloc(sizeof(quicklist));
    ql->head = &nodes[0];
    ql->tail = &nodes[num_nodes - 1];
    ql->count = num_nodes;
    ql->len = num_nodes;
    ql->alloc_size = sizeof(quicklist) + sizeof(quicklistBookmark) * 0;
    ql->fill = 32;
    ql->compress = 0;
    ql->bookmark_count = 0;

    sz = 0;
}