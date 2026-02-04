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

extern double min_value;
extern double value;
extern size_t max_packets;
extern ssize_t i;
extern unsigned char *pixels;
extern ViffInfo viff_info;
extern double max_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < (ssize_t)max_packets; i += 2) {
        ssize_t idx = i; // Use strided index
        switch ((int)viff_info.data_storage_type) {
          case 2:
            value = 1. * ((short *)pixels)[idx];
            break;
          case 4:
            value = 1. * ((int *)pixels)[idx];
            break;
          case 5:
            value = ((float *)pixels)[idx];
            break;
          case 9:
            value = ((double *)pixels)[idx];
            break;
          default:
            value = 1. * pixels[idx];
            break;
        }
        if (value > max_value)
            max_value = value;
        else if (value < min_value)
            min_value = value;
    }
}
