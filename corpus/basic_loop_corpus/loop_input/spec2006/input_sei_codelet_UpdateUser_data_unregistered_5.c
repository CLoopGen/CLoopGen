#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

typedef struct {
    int byte_pos;
    int bits_to_go;
    byte byte_buf;
    int stored_byte_pos;
    int stored_bits_to_go;
    byte stored_byte_buf;
    byte byte_buf_skip;
    int byte_pos_skip;
    int bits_to_go_skip;
    byte *streamBuffer;
    int write_flag;
} Bitstream;

typedef struct {
    char *byte;
    int total_byte;
    Bitstream *data;
    int payloadSize;
} user_data_unregistered_information_struct;

int i;
int temp_data;
int total_byte;

user_data_unregistered_information_struct seiUser_data_unregistered;

void init_vars() {
    total_byte = 64 * 1024 * 1024; // 64MB to target ~0.01 sec runtime on modern CPU

    seiUser_data_unregistered.byte = (char*)malloc(total_byte * sizeof(char));
    if (!seiUser_data_unregistered.byte) {
        total_byte = 0;
        return;
    }

    seiUser_data_unregistered.total_byte = total_byte;
    seiUser_data_unregistered.payloadSize = total_byte;

    seiUser_data_unregistered.data = (Bitstream*)malloc(sizeof(Bitstream));
    if (seiUser_data_unregistered.data) {
        Bitstream* bs = seiUser_data_unregistered.data;
        bs->byte_pos = 0;
        bs->bits_to_go = 8;
        bs->byte_buf = 0;
        bs->stored_byte_pos = 0;
        bs->stored_bits_to_go = 8;
        bs->stored_byte_buf = 0;
        bs->byte_buf_skip = 0;
        bs->byte_pos_skip = 0;
        bs->bits_to_go_skip = 8;
        bs->streamBuffer = (byte*)malloc(1024);
        if (bs->streamBuffer) {
            memset(bs->streamBuffer, 0, 1024);
        }
        bs->write_flag = 1;
    }
}