#include <stdio.h>

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

extern glist_t g;
extern gnode_t *gn;
extern int32 n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using array-like traversal
    // Assuming the list is linearized in memory (e.g., nodes are allocated in contiguous blocks)
    // We simulate consecutive access by treating 'g' as if it points to a dense array of gnode_t
    gnode_t *base = g;
    for (gn = base, n = 0; gn && n < 1000; gn = (gnode_t*)((char*)gn + sizeof(gnode_t)), n++) {
        if (((gnode_t*)((char*)gn + sizeof(gnode_t)))->data.ptr == NULL) break;
    }
}
