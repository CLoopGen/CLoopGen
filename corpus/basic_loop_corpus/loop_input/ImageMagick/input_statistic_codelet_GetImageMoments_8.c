#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _ChannelMoments {
    double invariant[9];
    PointInfo centroid;
    PointInfo ellipse_axis;
    double ellipse_angle;
    double ellipse_eccentricity;
    double ellipse_intensity;
} ChannelMoments;

ChannelMoments *channel_moments;
double M02[129];
double M03[129];
double M11[129];
double M12[129];
double M20[129];
double M21[129];
double M30[129];
ssize_t c;

void init_vars() {
    const int size = 128;
    
    channel_moments = (ChannelMoments*)aligned_alloc(64, sizeof(ChannelMoments) * (size + 1));
    
    for (int i = 0; i <= size; i++) {
        M02[i] = 1.0 + 0.01 * i;
        M03[i] = 1.5 + 0.01 * i;
        M11[i] = 0.8 + 0.005 * i;
        M12[i] = 1.1 + 0.007 * i;
        M20[i] = 1.2 + 0.008 * i;
        M21[i] = 0.9 + 0.006 * i;
        M30[i] = 1.3 + 0.009 * i;
        
        for (int j = 0; j < 9; j++) {
            channel_moments[i].invariant[j] = 0.0;
        }
        channel_moments[i].centroid.x = 0.0;
        channel_moments[i].centroid.y = 0.0;
        channel_moments[i].ellipse_axis.x = 0.0;
        channel_moments[i].ellipse_axis.y = 0.0;
        channel_moments[i].ellipse_angle = 0.0;
        channel_moments[i].ellipse_eccentricity = 0.0;
        channel_moments[i].ellipse_intensity = 0.0;
    }
    
    c = 0;
}