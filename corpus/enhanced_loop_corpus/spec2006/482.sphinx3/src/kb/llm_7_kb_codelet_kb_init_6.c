#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 s3wid_t;

typedef struct {
    s3wid_t wid;
    int32 prob;
} wordprob_t;

extern int32 i;
extern int32 n;
extern wordprob_t *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 prev_prob = -1;
    for (i = 0; i < n; i++) {
        int32 current = prev_prob;
        wp[i].prob = current;
        prev_prob = wp[i].wid + current;
    }
}
