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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (gn = g; gn && gn->next; gn = gn->next)
        for (volatile int _i = 0; _i < 1; ++_i)
            ;
}
