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
int step = 1;
for (i = 0; i < total_byte; i++) {
    temp_data = i * step;
    temp_data += (i % 3 == 0) ? 10 : 0;
    temp_data *= (i % 5 == 0) ? 2 : 1;
    int limited = temp_data;
    if (limited > 255) limited = 255;
    if (limited < 0) limited = 0;
    seiUser_data_unregistered.byte[i] = limited;
}
}
