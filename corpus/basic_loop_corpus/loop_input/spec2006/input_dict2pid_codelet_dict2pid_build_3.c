#include <stdio.h>
#include <stdlib.h>
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

dict2pid_t *dict2pid;
s3senid_t *sen;
int32 *cslen;
int32 i;

void init_vars() {
    const int32 total_data_size = 64 * 1024 * 1024; // ~64MB of sen data
    const int32 avg_segment_length = 16;
    const int32 n_comstate = total_data_size / avg_segment_length;

    dict2pid = (dict2pid_t*)calloc(1, sizeof(dict2pid_t));
    if (!dict2pid) exit(1);

    dict2pid->n_comstate = n_comstate;
    dict2pid->n_comsseq = n_comstate / 2;

    cslen = (int32*)malloc(n_comstate * sizeof(int32));
    if (!cslen) exit(1);

    sen = (s3senid_t*)malloc(total_data_size * sizeof(s3senid_t));
    if (!sen) exit(1);

    dict2pid->comstate = (s3senid_t**)malloc(n_comstate * sizeof(s3senid_t*));
    if (!dict2pid->comstate) exit(1);

    dict2pid->comsseq = (s3senid_t**)malloc(dict2pid->n_comsseq * sizeof(s3senid_t*));
    if (!dict2pid->comsseq) exit(1);

    dict2pid->comwt = (int32*)malloc(n_comstate * sizeof(int32));
    if (!dict2pid->comwt) exit(1);

    int32 accumulated = 0;
    for (int32 idx = 0; idx < n_comstate; ++idx) {
        int32 len = (total_data_size - accumulated) / (n_comstate - idx);
        if (len > 1024) len = 1024;
        if (len < 1) len = 1;
        cslen[idx] = len;
        accumulated += len;
    }

    for (int32 idx = 0; idx < dict2pid->n_comsseq; ++idx) {
        dict2pid->comsseq[idx] = sen + (idx * 32) % total_data_size;
    }

    for (int32 idx = 0; idx < n_comstate; ++idx) {
        dict2pid->comwt[idx] = idx * 789;
    }
}