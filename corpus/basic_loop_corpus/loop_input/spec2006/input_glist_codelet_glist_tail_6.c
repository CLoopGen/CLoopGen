#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

glist_t g;
gnode_t *gn;

#define LIST_SIZE (1 << 20)

static gnode_t node_pool[LIST_SIZE];

void init_vars() {
    for (int i = 0; i < LIST_SIZE; i++) {
        node_pool[i].data.int32 = i;
        if (i == LIST_SIZE - 1) {
            node_pool[i].next = NULL;
        } else {
            node_pool[i].next = &node_pool[i + 1];
        }
    }
    g = &node_pool[0];
    gn = NULL;
}