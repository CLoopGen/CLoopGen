#include <stdio.h>

#include <inttypes.h>

typedef char int8;

typedef int8 s3cipid_t;

typedef int int32;

typedef int32 s3pid_t;

typedef struct ph_rc_s {
    s3cipid_t rc;
    s3pid_t pid;
    struct ph_rc_s *next;
} ph_rc_t;

typedef struct ph_lc_s {
    s3cipid_t lc;
    ph_rc_t *rclist;
    struct ph_lc_s *next;
} ph_lc_t;

extern ph_lc_t *lclist;
extern s3cipid_t lc;
extern ph_lc_t *lcptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect access through an auxiliary array
    // Pre-collect pointers into an array (indirect access), then search linearly through that array
    // Assuming a maximum reasonable size to avoid dynamic allocation
    #define MAX_NODES 1024
    ph_lc_t *node_array[MAX_NODES];
    int count = 0;
    ph_lc_t *curr;

    for (curr = lclist; curr && count < MAX_NODES; curr = curr->next) {
        node_array[count++] = curr;
    }

    lcptr = NULL;
    for (int i = 0; i < count; ++i) {
        if (node_array[i]->lc == lc) {
            lcptr = node_array[i];
            break;
        }
    }
    #undef MAX_NODES
}
