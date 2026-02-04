#include <stdio.h>

#include <inttypes.h>

typedef char int8;

typedef int8 s3cipid_t;

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

typedef struct {
    s3cipid_t lc;
    glist_t root;
} lextree_lcroot_t;

extern s3cipid_t *lc;
extern lextree_lcroot_t *lcroot;
extern int32 n_lc;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n_lc; i++) {
    if (lc[i] >= 0) {
        lcroot[i].lc = lc[i];
        lcroot[i].root = ((void *)0);
    } else {
        continue;
    }
}
}
