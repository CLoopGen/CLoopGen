#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int int32;
typedef unsigned int uint32;
typedef float float32;
typedef double float64;

typedef union anytype_s {
    void *ptr;
    int32 int32;
    uint32 uint32;
    float32 float32;
    float64 float64;
} anytype_t;

typedef struct gnode_s {
    anytype_t data;
    struct gnode_s *next;
} gnode_t;

typedef gnode_t *glist_t;

glist_t g = NULL;
gnode_t *gn = NULL;
gnode_t *nextgn = NULL;
gnode_t *rev = NULL;

#define LIST_SIZE 1000000

void init_vars() {
    gnode_t **nodes = (gnode_t**)malloc(LIST_SIZE * sizeof(gnode_t*));
    if (!nodes) exit(1);

    for (int i = 0; i < LIST_SIZE; i++) {
        nodes[i] = (gnode_t*)malloc(sizeof(gnode_t));
        if (!nodes[i]) exit(1);
        nodes[i]->data.int32 = i;
        nodes[i]->next = (i == LIST_SIZE - 1) ? NULL : nodes[i + 1];
    }

    g = nodes[0];
    rev = NULL;

    free(nodes);
}