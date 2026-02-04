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
    size_t temp_end = rec->length;
    unsigned char *local_data = rec->data;
    for (size_t i = 0; i < rec->length; i++) {
        if (temp_end > 1 && local_data[temp_end - 1] == 0) {
            temp_end--;
        } else {
            break;
        }
    }
    end = temp_end - 1;
}
