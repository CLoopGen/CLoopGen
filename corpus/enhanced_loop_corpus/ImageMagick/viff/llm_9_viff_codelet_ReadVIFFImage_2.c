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
    size_t unroll_factor = 4;
    size_t remainder = max_packets % unroll_factor;
    size_t limit = max_packets - remainder;

    for (i = 0; i < (ssize_t)limit; i += unroll_factor) {
        double temp_values[4];
        for (size_t u = 0; u < unroll_factor; u++) {
            switch ((int)viff_info.data_storage_type) {
              case 2:
                temp_values[u] = 1. * ((short *)pixels)[i + u];
                break;
              case 4:
                temp_values[u] = 1. * ((int *)pixels)[i + u];
                break;
              case 5:
                temp_values[u] = ((float *)pixels)[i + u];
                break;
              case 9:
                temp_values[u] = ((double *)pixels)[i + u];
                break;
              default:
                temp_values[u] = 1. * pixels[i + u];
                break;
            }
        }
        for (size_t u = 0; u < unroll_factor; u++) {
            if (temp_values[u] > max_value)
                max_value = temp_values[u];
            else if (temp_values[u] < min_value)
                min_value = temp_values[u];
        }
    }

    for (; i < (ssize_t)max_packets; i++) {
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
