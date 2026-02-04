#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

dict2pid_t *dict2pid;
glist_t g;
gnode_t *gn;
hash_entry_t *he;
int32 i;

static char **mock_strings;
static int32 num_nodes = 100000;

void init_vars() {
    mock_strings = (char**)calloc(num_nodes, sizeof(char*));
    for (int32 idx = 0; idx < num_nodes; ++idx) {
        mock_strings[idx] = (char*)malloc(32);
        sprintf(mock_strings[idx], "key_%d", idx);
    }

    gnode_t **nodes = (gnode_t**)calloc(num_nodes, sizeof(gnode_t*));
    for (int32 idx = 0; idx < num_nodes; ++idx) {
        nodes[idx] = (gnode_t*)malloc(sizeof(gnode_t));
        hash_entry_t *entry = (hash_entry_t*)malloc(sizeof(hash_entry_t));
        entry->key = mock_strings[idx];
        entry->len = strlen(mock_strings[idx]);
        entry->val = idx;
        entry->next = NULL;
        nodes[idx]->data.ptr = entry;
        nodes[idx]->next = (idx == num_nodes - 1) ? NULL : nodes[idx + 1];
    }
    g = nodes[0];

    dict2pid = (dict2pid_t*)malloc(sizeof(dict2pid_t));
    dict2pid->n_comsseq = num_nodes + 1000;
    dict2pid->comsseq = (s3senid_t**)calloc(dict2pid->n_comsseq, sizeof(s3senid_t*));

    gn = NULL;
    he = NULL;
    i = 0;
}