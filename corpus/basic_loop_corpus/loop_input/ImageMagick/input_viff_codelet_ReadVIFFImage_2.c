#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _ViffInfo {
    unsigned char identifier;
    unsigned char file_type;
    unsigned char release;
    unsigned char version;
    unsigned char machine_dependency;
    unsigned char reserve[3];
    char comment[512];
    unsigned int rows;
    unsigned int columns;
    unsigned int subrows;
    int x_offset;
    int y_offset;
    float x_bits_per_pixel;
    float y_bits_per_pixel;
    unsigned int location_type;
    unsigned int location_dimension;
    unsigned int number_of_images;
    unsigned int number_data_bands;
    unsigned int data_storage_type;
    unsigned int data_encode_scheme;
    unsigned int map_scheme;
    unsigned int map_storage_type;
    unsigned int map_rows;
    unsigned int map_columns;
    unsigned int map_subrows;
    unsigned int map_enable;
    unsigned int maps_per_cycle;
    unsigned int color_space_model;
} ViffInfo;

double min_value;
double value;
size_t max_packets;
ssize_t i;
unsigned char *pixels;
ViffInfo viff_info;
double max_value;

void init_vars() {
    min_value = 1e30;
    max_value = -1e30;
    value = 0.0;
    i = 0;

    viff_info.data_storage_type = 2;

    max_packets = 10000000; 

    pixels = (unsigned char *)aligned_alloc(64, max_packets * sizeof(short));
    if (!pixels) exit(1);

    for (size_t j = 0; j < max_packets; j++) {
        ((short *)pixels)[j] = (short)(j % 65536);
    }
}