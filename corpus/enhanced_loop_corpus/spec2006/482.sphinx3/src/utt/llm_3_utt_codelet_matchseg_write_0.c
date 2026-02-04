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

typedef struct {
    int32 id;
    int32 vhid;
    int32 sf;
    int32 ef;
    int32 ascr;
    int32 lscr;
    int32 type;
} hyp_t;

extern glist_t hyp;
extern gnode_t *gn;
extern hyp_t *h;
extern int32 ascr;
extern int32 lscr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Array-like Indexing Using Auxiliary Array
    // Convert list into an array of pointers first (simulating indirect access),
    // then iterate over indices with non-sequential access (e.g., reverse order).

    #define MAX_NODES 1024
    static gnode_t* node_array[MAX_NODES];
    int32 count = 0;

    // First pass: collect nodes into an array (indirect access preparation)
    gnode_t* temp;
    for (temp = hyp; temp && count < MAX_NODES; temp = temp->next) {
        node_array[count++] = temp;
    }

    // Second pass: process in reverse (indirect and non-sequential access pattern)
    for (int32 i = count - 1; i >= 0; i--) {
        h = (hyp_t *)(node_array[i]->data.ptr);
        ascr += h->ascr;
        lscr += h->lscr;
    }
}
