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
    // Variant 1: Strided memory access pattern simulation using pointer arithmetic with a skip (simulated stride)
    // Although the list is inherently linked, we simulate a strided traversal by skipping every other node
    ph_rc_t *current = rclist;
    int stride = 2;  // Simulate processing every 2nd eligible node
    for (int i = 0; current && (current->rc != rc); i++) {
        // Traverse normally but only consider nodes where index % stride == 0 as active checks
        if ((i % stride == 0) && current->rc == rc) {
            rcptr = current;
            return;
        }
        current = current->next;
    }
    // Final check to ensure correct assignment if loop ended due to match
    if (current && current->rc == rc) {
        rcptr = current;
    } else {
        rcptr = 0;
    }
}
