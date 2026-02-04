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
    int32 stride = 4;
    for (i = 0; i < n; i++) {
        wp[i].prob = -1;
        wp[i].wid = (i % stride == 0) ? wp[i].wid * 2 : wp[i].wid;
    }
}
