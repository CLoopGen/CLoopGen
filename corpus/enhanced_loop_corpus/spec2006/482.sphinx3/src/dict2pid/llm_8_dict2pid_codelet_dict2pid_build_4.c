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
    for (gn = g; gn; gn = ((gn)->next)) {
        he = (hash_entry_t *)((gn)->data.ptr);
        i = ((he)->val) * 2 + 1;
        if (i < dict2pid->n_comsseq && i >= 0) {
            dict2pid->comsseq[i] = (s3senid_t *)((he)->key);
        }
    }
}
