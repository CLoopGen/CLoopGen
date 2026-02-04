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

typedef short int16;

typedef int16 s3senid_t;

typedef struct hash_entry_s {
    const char *key;
    int32 len;
    int32 val;
    struct hash_entry_s *next;
} hash_entry_t;

extern glist_t g;
extern gnode_t *gn;
extern s3senid_t *sen;
extern hash_entry_t *he;
extern int32 *cslen;
extern int32 i;
extern int32 n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int32 local_n = 0;
    for (gn = g; gn; gn = ((gn)->next)) {
        he = (hash_entry_t *)((gn)->data.ptr);
        sen = (s3senid_t *)((he)->key);
        i = 0;
        // Eliminate loop-carried dependency on 'n' by using a local accumulator
        // Introduce WAW-like independence by deferring update to global 'n'
        while (sen[i] >= 0) i++;  // Simulate counting without data dependency on prior iterations
        cslen[((he)->val)] = i + 1;
        local_n += (i + 1);  // Accumulate locally to break WAW on 'n'
    }
    n += local_n;  // Update global only once after loop
}
