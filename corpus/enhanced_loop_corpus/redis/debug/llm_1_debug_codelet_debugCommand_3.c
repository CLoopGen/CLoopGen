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

extern quicklist *ql;
extern unsigned long sz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (quicklistNode *outer = ql->head; outer; outer = outer->next) {
        sz += outer->sz;
        for (quicklistNode *inner = outer->next; inner; inner = inner->next) {
            sz += inner->sz;
        }
    }
}
