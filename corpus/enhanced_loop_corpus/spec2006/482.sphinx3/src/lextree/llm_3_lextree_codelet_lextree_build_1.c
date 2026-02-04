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
    // Variant 2: Indirect access via index array (simulating gather pattern)
    // Create local index map to simulate reordering or indirect traversal
    int32 indices[512]; // Assuming n_lc <= 512 for stack allocation safety
    if (n_lc > 512) return; // Prevent buffer overflow

    for (i = 0; i < n_lc; i++) {
        indices[i] = i; // Identity mapping, could be randomized or reordered in real use cases
    }

    for (i = 0; i < n_lc; i++) {
        int32 idx = indices[i]; // Indirect access through index array
        lcroot[idx].lc = lc[idx];
        lcroot[idx].root = ((void *)0);
    }
}
