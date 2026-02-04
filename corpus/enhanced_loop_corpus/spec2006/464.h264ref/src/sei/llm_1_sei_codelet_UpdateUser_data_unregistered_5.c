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
    if (total_byte > 0) {
        for (int level1 = 0; level1 < (total_byte + 3) / 4; level1++) {
            for (int level2 = 0; level2 < 4; level2++) {
                int i = level1 * 4 + level2;
                if (i >= total_byte) continue;
                temp_data = i * 4;
                seiUser_data_unregistered.byte[i] = (((0) > ((((temp_data) < (255)) ? (temp_data) : (255)))) ? (0) : ((((temp_data) < (255)) ? (temp_data) : (255))));
            }
        }
    }
}
