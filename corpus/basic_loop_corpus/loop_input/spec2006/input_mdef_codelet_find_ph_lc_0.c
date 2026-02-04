#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

ph_lc_t *lclist = NULL;
s3cipid_t lc = 0;
ph_lc_t *lcptr = NULL;

#define LIST_SIZE 100000

static ph_lc_t lc_array[LIST_SIZE];
static ph_rc_t rc_array[LIST_SIZE];

void init_vars() {
    for (int i = 0; i < LIST_SIZE; i++) {
        lc_array[i].lc = (s3cipid_t)(i + 1);
        lc_array[i].rclist = &rc_array[i];
        lc_array[i].next = (i == LIST_SIZE - 1) ? NULL : &lc_array[i + 1];
        
        rc_array[i].rc = (s3cipid_t)(i % 127);
        rc_array[i].pid = (s3pid_t)(i * 100);
        rc_array[i].next = NULL;
    }
    
    lclist = &lc_array[0];
    lc = LIST_SIZE; 
}