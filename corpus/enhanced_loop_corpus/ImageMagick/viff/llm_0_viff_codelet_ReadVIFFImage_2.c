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
    for (ssize_t outer = 0; outer < (ssize_t)(max_packets / 2); outer++) {
        for (ssize_t inner = 0; inner < 2; inner++) {
            i = outer * 2 + inner;
            if (i >= (ssize_t)max_packets) break;
            switch ((int)viff_info.data_storage_type) {
              case 2:
                value = 1. * ((short *)pixels)[i];
                break;
              case 4:
                value = 1. * ((int *)pixels)[i];
                break;
              case 5:
                value = ((float *)pixels)[i];
                break;
              case 9:
                value = ((double *)pixels)[i];
                break;
              default:
                value = 1. * pixels[i];
                break;
            }
            if (value > max_value)
                max_value = value;
            else if (value < min_value)
                min_value = value;
        }
    }
    // Handle odd-sized max_packets
    if (max_packets % 2 == 1) {
        i = max_packets - 1;
        switch ((int)viff_info.data_storage_type) {
          case 2:
            value = 1. * ((short *)pixels)[i];
            break;
          case 4:
            value = 1. * ((int *)pixels)[i];
            break;
          case 5:
            value = ((float *)pixels)[i];
            break;
          case 9:
            value = ((double *)pixels)[i];
            break;
          default:
            value = 1. * pixels[i];
            break;
        }
        if (value > max_value)
            max_value = value;
        else if (value < min_value)
            min_value = value;
    }
}
