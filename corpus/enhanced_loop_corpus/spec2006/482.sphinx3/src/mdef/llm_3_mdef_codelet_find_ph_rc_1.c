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

extern ph_rc_t *rclist;
extern s3cipid_t rc;
extern ph_rc_t *rcptr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an array-like index lookup using auxiliary array of pointers
    // Pre-traverse the list to collect pointers into an array (assuming bounded size for realism)
    #define MAX_NODES 1024
    ph_rc_t *nodes[MAX_NODES];
    int count = 0;
    ph_rc_t *temp = rclist;
    
    while (temp && count < MAX_NODES) {
        nodes[count++] = temp;
        temp = temp->next;
    }

    // Now perform indirect access using indexed lookup with reverse order (indirect and reversed pattern)
    rcptr = 0;
    for (int i = 0; i < count; i++) {
        // Access nodes in reverse index order (indirect + reversed access pattern)
        ph_rc_t *candidate = nodes[count - 1 - i];
        if (candidate->rc == rc) {
            rcptr = candidate;
            break;
        }
    }
}
