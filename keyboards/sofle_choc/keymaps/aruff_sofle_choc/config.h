/**
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

//----------------------------------------------------------------------
// RGB Settings
//----------------------------------------------------------------------
#define RGB_MATRIX_SLEEP    // turn off RGB underglow when host goes to sleep
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash.
#define SPLIT_TRANSPORT_MIRROR // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
#define RGBLIGHT_LED_COUNT 35    // Number of LEDs

//----------------------------------------------------------------------
// Keymap Settings
//----------------------------------------------------------------------
#define INDICATOR_BRIGHTNESS 30 // brightness of the keyboard indicator LED

#define QUICK_TAP_TERM 0 // prevents quick taps from being interpreted as a hold
// Tapping term is the time (in ms) before a tap becomes a hold
#ifdef TAPPING_TERM
    #undef TAPPING_TERM // undefine TAPPING_TERM if it is already defined
    #define TAPPING_TERM 200 // set tapping term to 200ms
#endif

//----------------------------------------------------------------------
// Encoder Settings
//----------------------------------------------------------------------
#define ENCODER_DIRECTION_FLIP
