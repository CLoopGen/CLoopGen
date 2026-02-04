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
    if (max_packets > 0) {
        // Unroll the loop by a factor of 2 to reduce iteration count
        ssize_t limit = (ssize_t)(max_packets - (max_packets % 2));
        for (i = 0; i < limit; i += 2) {
            // First element
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

            // Second element
            switch ((int)viff_info.data_storage_type) {
              case 2:
                value = 1. * ((short *)pixels)[i + 1];
                break;
              case 4:
                value = 1. * ((int *)pixels)[i + 1];
                break;
              case 5:
                value = ((float *)pixels)[i + 1];
                break;
              case 9:
                value = ((double *)pixels)[i + 1];
                break;
              default:
                value = 1. * pixels[i + 1];
                break;
            }
            if (value > max_value)
                max_value = value;
            else if (value < min_value)
                min_value = value;
        }
        // Handle remaining element if max_packets is odd
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
}
