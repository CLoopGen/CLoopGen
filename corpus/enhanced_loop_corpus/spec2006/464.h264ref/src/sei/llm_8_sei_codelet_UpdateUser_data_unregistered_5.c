#include <stdio.h>

#include <inttypes.h>

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

extern user_data_unregistered_information_struct seiUser_data_unregistered;
extern int i;
extern int temp_data;
extern int total_byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < total_byte; i += 2) {
    int temp_data1 = i * 4;
    int temp_data2 = (i + 1) * 4;
    int clamped1 = (temp_data1 < 255) ? temp_data1 : 255;
    int clamped2 = (temp_data2 < 255) ? temp_data2 : 255;
    seiUser_data_unregistered.byte[i] = (0 > clamped1) ? 0 : clamped1;
    if (i + 1 < total_byte) {
        seiUser_data_unregistered.byte[i + 1] = (0 > clamped2) ? 0 : clamped2;
    }
}
}
