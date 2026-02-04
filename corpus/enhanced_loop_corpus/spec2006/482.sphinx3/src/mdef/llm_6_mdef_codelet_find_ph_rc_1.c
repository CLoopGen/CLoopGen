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



void loop(){
    ph_rc_t *temp = rclist;
    s3cipid_t local_rc = rc;
    for (; temp != NULL; temp = temp->next) {
        if (temp->rc == local_rc) {
            rcptr = temp;
            break;
        }
    }
    if (temp == NULL) {
        rcptr = NULL;
    }
}
