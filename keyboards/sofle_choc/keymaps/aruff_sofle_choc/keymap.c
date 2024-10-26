// config.h
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY = 0,
    _SYMBL,
    _NAV,
    _FKEY,
};

// Custom Keycodes for Layer Switching
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_SMB,
    KC_NAV,
    KC_FKEY,
    ALT_GUI_LEFT,
    ALT_GUI_RIGHT,
};

// Define aliases for Mod-Tap keys
#define NAV_F      LT(KC_NAV, KC_F)
#define FKEY_SCLN      LT(KC_FKEY, KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BKSP |
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |      |      |      |      | NAV  |      |-------.    ,-------|      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------'    '-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------|-------.    .-------|-----------------------------------------'
 *               | CTRL | ALT  | LOPT | SPC  | SYMB  |    |KC_FKEY| ENT  | RGUI | ROPT | CTRL  |
 *               `-----------------------------------'    '------------------------------------'
 */

[_QWERTY]=LAYOUT(
     KC_GRV,  KC_1,   KC_2,    KC_3,   KC_4,   KC_5,                        KC_6,   KC_7,       KC_8,    KC_9,      KC_0, KC_MINS,
     KC_TAB,  KC_Q,   KC_W,    KC_E,   KC_R,   KC_T,                        KC_Y,   KC_U,       KC_I,    KC_O,      KC_P,  KC_EQL,
    KC_ESC,  KC_A,   KC_S,    KC_D,   NAV_F,   KC_G,                        KC_H,   KC_J,       KC_K,    KC_L, KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,  KC_X,   KC_C,  KC_V,   KC_B, XXXXXXX,          XXXXXXX, KC_N,   KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,
            KC_LCTL, KC_LOPT, KC_LGUI, KC_SPC, KC_SMB,                    KC_FKEY, KC_ENT,    KC_RGUI, KC_ROPT,   KC_RCTL
),

/* SYMBL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   "  |   {  |   }  |   |  |   \  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |ALTGL |      |      |ALTGR |      |                    |   -  |   [  |   ]  |      |      |   "  |
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------'    '-------|   _  |   (  |   )  |      |      |      |
 * `-----------------------------------------|-------.    .-------|-----------------------------------------'
 *               | CTRL | ALT  | LOPT | SPC  | SYMB  |    |KC_FKEY| ENT  | RGUI | ROPT | CTRL  |
 *               `-----------------------------------'    '------------------------------------'
*/
[_SYMBL] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                         KC_QUOT, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, KC_RBRC,
  _______, ALT_GUI_LEFT, _______, _______, ALT_GUI_RIGHT, _______,                         KC_MINUS, KC_LBRC, KC_RBRC, XXXXXXX, KC_BSPC, _______,
  _______, _______, _______, _______, _______, _______,XXXXXXX        ,XXXXXXX, KC_UNDS, KC_LPRN, KC_RPRN, _______, _______, _______,
           _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______
),
/* FKEY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |-------'    '-------|      |      |      |      |      |      |
 * `-----------------------------------------|-------.    .-------|-----------------------------------------'
 *               | CTRL | ALT  | LOPT | SPC  | SYMB  |    |KC_FKEY| ENT  | RGUI | ROPT | CTRL  |
 *               `-----------------------------------'    '------------------------------------'
*/
[_FKEY] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_F9, KC_F10, KC_F11, KC_F12, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_F5, KC_F6, KC_F7, KC_F8, _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_F1, KC_F2, KC_F3, KC_F4, _______,XXXXXXX,XXXXXXX, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______
),

/* NAV
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | Copy | Cut  |      | Paste|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down | Up   |Right |  Del | Bspc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    .-------| Undo | Again|      |      |      |      |
 * `-----------------------------------------|-------.    .-------|-----------------------------------------'
 *               | CTRL | ALT  | LOPT | SPC  | SYMB  |    |KC_FKEY| ENT  | RGUI | ROPT | CTRL  |
 *               `-----------------------------------'    '------------------------------------'
 */
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,
  _______, _______, _______, _______, _______, _______,                          XXXXXXX, KC_COPY, C(KC_X), XXXXXXX, KC_PASTE, XXXXXXX,
  _______, _______, _______, _______, _______, _______,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX,       XXXXXXX,  KC_UNDO, KC_AGIN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______
)
};

//--------------------------------------------------------------------------------------------------
// RGB Undrekey lighting
//--------------------------------------------------------------------------------------------------
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(0, 0, 120);  // Hue 0, Saturation 0 (white), Brightness 120
}


//--------------------------------------------------------------------------------------------------
// OLED Display (128x32)
//--------------------------------------------------------------------------------------------------
#ifdef OLED_ENABLE

// 32x32 ([32x32/8] is 128 bytes) pixel logo
static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x00, 0x00, 0x80, 0xc0, 0xe0, 0x30, 0x18, 0x1c, 0x8c, 0x86, 0x86, 0x06, 0x03, 0xff, 0xff, 0x03,
        0x03, 0x03, 0x03, 0x83, 0xc6, 0xfe, 0xce, 0x8c, 0x1c, 0x18, 0x30, 0xe0, 0xc0, 0x80, 0x00, 0x00,
        0xf0, 0xfe, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x09, 0x0d, 0x0f, 0x06, 0x47, 0xf7, 0xb0,
        0xb0, 0xf0, 0x40, 0x03, 0x07, 0x04, 0x07, 0x07, 0xf0, 0xf0, 0x98, 0xf0, 0xe1, 0x07, 0xfe, 0xf0,
        0x0f, 0x7f, 0xf0, 0x80, 0x0e, 0x1f, 0x13, 0x1b, 0x3e, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x01, 0xff,
        0xff, 0x01, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x03, 0x01, 0x01, 0x01, 0x01, 0x80, 0xf0, 0x7f, 0x0f,
        0x00, 0x00, 0x01, 0x03, 0x07, 0x0c, 0x18, 0x38, 0x30, 0x7f, 0x7f, 0x60, 0xc0, 0xc0, 0xc0, 0xff,
        0xff, 0xc0, 0xc0, 0xc0, 0x60, 0x7f, 0x7f, 0x30, 0x38, 0x18, 0x0c, 0x07, 0x03, 0x01, 0x00, 0x00
        };

    oled_write_raw_P(logo, sizeof(logo));
}

// 32 * 14 OS logos
static const char PROGMEM mac_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0,
    0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f,
    0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static void print_logo_narrow(void) {
    render_logo();
}

static void print_status_narrow(void) {
    oled_set_cursor(0, 0);
    oled_write_raw_P(mac_logo, sizeof(mac_logo));
    oled_set_cursor(0, 5);

    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwrty\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _SYMBL:
            oled_write_P(PSTR("Symbl\n"), false);
            break;
        case _FKEY:
            oled_write_P(PSTR("Fkey\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}
#endif

//--------------------------------------------------------------------------------------------------
// Button event listener
//--------------------------------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Default behavior for all other keys
    switch (keycode) {
        case KC_SMB:
            if (record->event.pressed) {
                layer_on(_SYMBL);
            } else {
                layer_off(_SYMBL);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_FKEY:
            if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;
        case KC_COPY:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_C);
                unregister_code(KC_C);
                unregister_code(KC_LGUI);
            }
            break;
        case KC_PASTE:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_V);
                unregister_code(KC_V);
                unregister_code(KC_LGUI);
            }
            break;
        case ALT_GUI_LEFT:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LEFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
            }
            break;
        case ALT_GUI_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                register_code(KC_RIGHT);
            } else {
                unregister_code(KC_RIGHT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
            }
            break;
    }
    return true;
}

//--------------------------------------------------------------------------------------------------
// Encoder: Volume and Navigation
//--------------------------------------------------------------------------------------------------
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_BRIU);
        }
        else {
            tap_code(KC_BRID);
        }
    }
    return true;
}
#endif
