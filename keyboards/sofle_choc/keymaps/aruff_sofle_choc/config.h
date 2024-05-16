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
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define WS2812_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_LED_COUNT

    #define RGBLIGHT_LED_COUNT 70
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

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
