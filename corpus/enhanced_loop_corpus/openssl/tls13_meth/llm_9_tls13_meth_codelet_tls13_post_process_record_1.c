#include <stdio.h>

#include <inttypes.h>

typedef struct tls_rl_record_st {
    int rec_version;
    int type;
    size_t length;
    size_t orig_len;
    size_t off;
    unsigned char *data;
    unsigned char *input;
    unsigned char *comp;
    uint16_t epoch;
    unsigned char seq_num[8];
} TLS_RL_RECORD;

extern TLS_RL_RECORD *rec;
extern size_t end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    end = rec->length - 1;
    for (; end > 1; end -= step) {
        if (rec->data[end] != 0 || rec->data[end-1] != 0) {
            while (end > 0 && rec->data[end] == 0) end--;
            break;
        }
    }
    if (end == 1) {
        if (rec->data[1] == 0 && rec->data[0] != 0)
            end = 0;
        else if (rec->data[1] == 0 && rec->data[0] == 0)
            end = 0;
    }
}
