#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

s3cipid_t *lc;
lextree_lcroot_t *lcroot;
int32 n_lc;
int32 i;

void init_vars() {
    n_lc = 134217728; // ~128MB of data: 134M elements * (1 + padding) bytes per s3cipid_t and lextree_lcroot_t
    lc = (s3cipid_t*)calloc(n_lc, sizeof(s3cipid_t));
    lcroot = (lextree_lcroot_t*)calloc(n_lc, sizeof(lextree_lcroot_t));
    
    if (!lc || !lcroot) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (int32 j = 0; j < n_lc; j++) {
        lc[j] = (s3cipid_t)(j & 0x7F);
    }
}