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
    end = rec->length;
    for (size_t i = rec->length - 1; i < rec->length; i--) {
        if (rec->data[i] != 0) {
            end = i;
            break;
        }
        if (i == 0) {
            end = 0;
            break;
        }
    }
    end = (end == 0 && rec->length > 0 && rec->data[0] == 0) ? 0 : end;
}
