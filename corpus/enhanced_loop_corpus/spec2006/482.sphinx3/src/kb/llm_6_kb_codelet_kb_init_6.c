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
    s3wid_t temp_wid;
    for (i = 0; i < n; i++) {
        temp_wid = wp[i].wid;
        wp[i].prob = -1;
        wp[i].wid = temp_wid;
    }
}
