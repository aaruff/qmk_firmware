/**
 * config.h
 * Configuration Settings for the Sofle Keyboard
 */
#pragma once

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
#define SPLIT_USB_DETECT
#define SPLIT_TRANSPORT_MIRROR

//----------------------------------------------------------------------
// RGB Settings
//----------------------------------------------------------------------
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120

#undef RGB_MATRIX_HUE_STEP
#define RGB_MATRIX_HUE_STEP 10
#undef RGB_MATRIX_SAT_STEP
#define RGB_MATRIX_SAT_STEP 17
#undef RGB_MATRIX_VAL_STEP
#define RGB_MATRIX_VAL_STEP 17

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR

//----------------------------------------------------------------------
// Keymap Settings
//----------------------------------------------------------------------
#define INDICATOR_BRIGHTNESS 10 // brightness of the keyboard indicator LED
#define QUICK_TAP_TERM 0 // prevents quick taps from being interpreted as a hold
// Tapping term is the time (in ms) before a tap becomes a hold
#ifdef TAPPING_TERM
    #undef TAPPING_TERM // undefine TAPPING_TERM if it is already defined
    #define TAPPING_TERM 200 
#endif
#define PERMISSIVE_HOLD
//----------------------------------------------------------------------
// Encoder Settings
//----------------------------------------------------------------------
#define ENCODER_DIRECTION_FLIP


//----------------------------------------------------------------------
// OLED Settings
//----------------------------------------------------------------------
#define OLED_TIMEOUT 120000
#define OLED_BRIGHTNESS 120
