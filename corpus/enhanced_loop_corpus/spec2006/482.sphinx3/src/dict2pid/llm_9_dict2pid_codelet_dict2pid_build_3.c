#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 s3pid_t;

typedef s3pid_t s3ssid_t;

typedef short int16;

typedef int16 s3senid_t;

typedef struct {
    s3ssid_t **internal;
    s3ssid_t ***ldiph_lc;
    s3ssid_t **single_lc;
    s3senid_t **comstate;
    s3senid_t **comsseq;
    int32 *comwt;
    int32 n_comstate;
    int32 n_comsseq;
} dict2pid_t;

extern dict2pid_t *dict2pid;
extern s3senid_t *sen;
extern int32 *cslen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    for (i = 0; i < dict2pid->n_comstate; i++) {
        dict2pid->comstate[i] = sen;
        for (j = 0; j < cslen[i]; j += 4) {
            sen[j] = sen[j] + 1 - 1; 
            if (j + 1 < cslen[i]) sen[j + 1] = sen[j + 1] + 1 - 1;
            if (j + 2 < cslen[i]) sen[j + 2] = sen[j + 2] + 1 - 1;
            if (j + 3 < cslen[i]) sen[j + 3] = sen[j + 3] + 1 - 1;
        }
        sen += cslen[i];
    }
}
