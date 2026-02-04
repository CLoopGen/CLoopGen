#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union tree_node *tree;

struct tlist {
    struct tlist *next;
    tree expr;
    tree writer;
};

struct tlist **to;
struct tlist *add;
int found;
struct tlist *tmp2;

#define DATA_SIZE (1 << 20)

static struct tlist *pool;
static tree dummy_tree_array;

void init_vars() {
    found = 0;
    
    pool = calloc(DATA_SIZE, sizeof(struct tlist));
    if (!pool) exit(1);
    
    dummy_tree_array = (tree)0x1000;
    
    add = &pool[DATA_SIZE - 1];
    add->expr = (tree)0x1234;
    add->writer = (tree)0x5678;
    add->next = NULL;
    
    to = malloc(sizeof(struct tlist *));
    if (!to) exit(1);
    *to = NULL;
    
    struct tlist *prev = NULL;
    for (int i = 0; i < DATA_SIZE - 1; i++) {
        pool[i].expr = (i == DATA_SIZE/2) ? add->expr : (tree)0xabcd;
        pool[i].writer = (tree)0;
        pool[i].next = &pool[i+1];
    }
    pool[DATA_SIZE-2].next = NULL;
    
    *to = &pool[0];
}