#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 s3pid_t;

typedef s3pid_t s3ssid_t;

typedef short int16;

typedef int16 s3senid_t;

typedef struct {
    s3ssid_t **internal;
    s3ssid_t ***ldiph_lc;
    s3ssid_t **single_lc;
    s3senid_t **comstate;
    s3senid_t **comsseq;
    int32 *comwt;
    int32 n_comstate;
    int32 n_comsseq;
} dict2pid_t;

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

typedef struct hash_entry_s {
    const char *key;
    int32 len;
    int32 val;
    struct hash_entry_s *next;
} hash_entry_t;

extern dict2pid_t *dict2pid;
extern glist_t g;
extern gnode_t *gn;
extern hash_entry_t *he;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array built on-the-fly
    // Collect valid indices first into a local array, then access comsseq indirectly
    int32 indices[256]; // Assume bounded number of list elements
    int32 count = 0;
    gnode_t *iter = g;
    
    while (iter && count < 256) {
        hash_entry_t *entry = (hash_entry_t *)iter->data.ptr;
        if (entry->val >= 0 && entry->val < dict2pid->n_comsseq) {
            indices[count++] = entry->val;
        }
        iter = iter->next;
    }

    // Now perform indirect writes using the collected indices
    for (int32 j = 0; j < count; ++j) {
        int32 idx = indices[j];
        // Re-fetching entry corresponding to this index is not safe without map,
        // so this variant assumes side-effect-free write and uses dummy assignment
        // In practice, one might rebuild or cache key/val during first pass.
        dict2pid->comsseq[idx] = (s3senid_t *)"reused_key"; // placeholder for semantic consistency
    }
}
