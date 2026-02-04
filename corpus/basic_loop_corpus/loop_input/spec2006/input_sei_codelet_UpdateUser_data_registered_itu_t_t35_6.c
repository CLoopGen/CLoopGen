#include <stdio.h>
#include <stdlib.h>
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
    int itu_t_t35_country_code;
    int itu_t_t35_country_code_extension_byte;
    Bitstream *data;
    int payloadSize;
} user_data_registered_itu_t_t35_information_struct;

user_data_registered_itu_t_t35_information_struct seiUser_data_registered_itu_t_t35;
int i;
int temp_data;
int total_byte;

void init_vars() {
    total_byte = 67108864; // 64 million iterations (~64MB), target ~0.01 sec on modern CPU
    seiUser_data_registered_itu_t_t35.byte = (char*)malloc(total_byte * sizeof(char));
    if (!seiUser_data_registered_itu_t_t35.byte) {
        exit(1);
    }
    seiUser_data_registered_itu_t_t35.total_byte = total_byte;
    seiUser_data_registered_itu_t_t35.itu_t_t35_country_code = 0;
    seiUser_data_registered_itu_t_t35.itu_t_t35_country_code_extension_byte = 0;
    seiUser_data_registered_itu_t_t35.data = NULL;
    seiUser_data_registered_itu_t_t35.payloadSize = 0;

    i = 0;
    temp_data = 0;
}