#ifndef LIBFREENECT_H
#define LIBFREENECT_H

#include <stdint.h>

typedef void (*depthcb)(uint16_t *buf, int width, int height);
typedef void (*rgbcb)(uint8_t *buf, int width, int height);

enum LIBFREENECT_RETURN_CODE {
FREENECT_OK = 0x0,
FREENECT_ERROR_DEVICE_NOT_FOUND,
FREENECT_ERROR_DEVICE_OPEN_FAILED,
FREENECT_DEVICE_ALREADY_OPEN,
FREENECT_DEVICE_NOT_OPEN,
FREENECT_ERROR_DEVICE_CLOSE_FAILED,
FREENECT_ERROR_TRANSFER
};

enum KinectLEDStatus
    {
        Off = 0x0,
        Green = 0x1,
        Red = 0x2,
        Yellow = 0x3,
        BlinkingYellow = 0x4,
        BlinkingGreen = 0x5,
        AlternateRedYellow = 0x6,
        AlternateRedGreen = 0x7
    };


enum LIBFREENECT_RETURN_CODE init_camera_device();

void start_camera_device();
void update_isochronous_async();
void prep_iso_transfers(depthcb dcb, rgbcb rcb);

enum LIBFREENECT_RETURN_CODE init_motor_device();
enum LIBFREENECT_RETURN_CODE close_motor_device();

enum LIBFREENECT_RETURN_CODE set_led(enum KinectLEDStatus status);
enum LIBFREENECT_RETURN_CODE set_motor_tilt(uint8_t tiltValue);

#endif

