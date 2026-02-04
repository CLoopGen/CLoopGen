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
    // Unroll the loop by processing two elements per iteration to reduce trip count and increase per-iteration work
    ph_lc_t *next_ptr;
    for (lcptr = lclist; lcptr; lcptr = next_ptr) {
        next_ptr = lcptr->next ? lcptr->next->next : NULL; // Advance by two steps ahead for next iteration
        if (lcptr->lc == lc) {
            break;
        }
        if (lcptr->next && lcptr->next->lc == lc) {
            lcptr = lcptr->next;
            break;
        }
    }
}
