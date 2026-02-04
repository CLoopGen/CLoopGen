#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef char int8;
typedef int8 s3cipid_t;
typedef int int32;
typedef int32 s3pid_t;

typedef struct ph_rc_s {
    s3cipid_t rc;
    s3pid_t pid;
    struct ph_rc_s *next;
} ph_rc_t;

ph_rc_t *rclist = NULL;
s3cipid_t rc = 42;
ph_rc_t *rcptr = NULL;

#define LIST_SIZE (1 << 20)  // Approximately 1 million nodes

void init_vars() {
    ph_rc_t *nodes = calloc(LIST_SIZE, sizeof(ph_rc_t));
    if (!nodes) {
        exit(1);
    }

    for (int i = 0; i < LIST_SIZE; i++) {
        nodes[i].rc = (i == LIST_SIZE - 1) ? rc : (rc + 1);
        nodes[i].pid = i;
        if (i < LIST_SIZE - 1) {
            nodes[i].next = &nodes[i + 1];
        } else {
            nodes[i].next = NULL;
        }
    }

    rclist = &nodes[0];
    rcptr = rclist;
}