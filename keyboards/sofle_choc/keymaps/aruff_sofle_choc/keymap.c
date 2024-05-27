// config.h
#include QMK_KEYBOARD_H

// Layer Names
enum sofle_layers {
    _QWERTY = 0,
    _SYMBL,
    _NAV,
};

// Custom Keycodes for Layer Switching
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_SMB,
    KC_NAV,
};

// Define aliases for Mod-Tap keys
#define NAV_ESC    LT(KC_NAV, KC_ESC)
#define CTL_Z      MT(MOD_LCTL, KC_Z)
#define ALT_X      MT(MOD_LALT, KC_X)
#define GUI_C      MT(MOD_LGUI, KC_C)
#define SFT_V      MT(MOD_LSFT, KC_V)
#define SFT_M      MT(MOD_RSFT, KC_M)
#define GUI_COMM   MT(MOD_RGUI, KC_COMM)
#define ALT_DOT    MT(MOD_RALT, KC_DOT)
#define CTL_SLSH   MT(MOD_RCTL, KC_SLSH)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BKSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------'    '-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * |      | LCTRL| LALT | LGUI |LSHFT |      |                    |      |RSHFT | RGUI | RALT | RCTRL|      |
 * `-----------------------------------------|-------.    .-------|-----------------------------------------'
 *               |      |      | SYMB |SPACE | NAV   |    |  NAV  | ENTER| SYMB |      |BKSPC |
 *               `-----------------------------------'    '-----------------------------------
 */

[_QWERTY]=LAYOUT(
     KC_GRV,  KC_1,   KC_2,    KC_3,   KC_4,   KC_5,                        KC_6,  KC_7,      KC_8,    KC_9,     KC_0, KC_MINUS,
     KC_TAB,  KC_Q,   KC_W,    KC_E,   KC_R,   KC_T,                        KC_Y,  KC_U,      KC_I,    KC_O,     KC_P,  KC_BSPC,
    NAV_ESC,  KC_A,   KC_S,    KC_D,   KC_F,   KC_G,                        KC_H,  KC_J,      KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
    KC_LSFT, CTL_Z,  ALT_X,   GUI_C,  SFT_V,   KC_B, XXXXXXX,      XXXXXXX, KC_N, SFT_M,  GUI_COMM, ALT_DOT, CTL_SLSH,  KC_RSFT,
            XXXXXXX, XXXXXXX, KC_SMB, KC_SPC, KC_NAV,                        KC_NAV, KC_ENT, KC_SMB, XXXXXXX,  KC_BSPC
),

/* SYMBL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      | F10  | F11  | F12  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |      |                    |      |   {  |   }  |   |  |   \  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  F4  |  F5  |  F6  |      |-------.    ,-------|      |   [  |   ]  |   +  |   -  |BKSPC |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  F1  |  F2  |  F3  |      |-------.    .-------|      |   (  |   )  |   ,  |   /  |RShift|
 * `-----------------------------------------|-------.    .-------|-----------------------------------------'
 *               |      | NUM  | SYMB |SPACE | NAV   |    |  NAV  | ENTER| SYMB |      |BKSPC |
 *               `-----------------------------------'    '-----------------------------------
*/
[_SYMBL] = LAYOUT(
  XXXXXXX, XXXXXXX,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                         XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, KC_EQL,
  XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                         XXXXXXX, KC_LBRC, KC_RBRC, KC_PLUS, KC_MINUS, KC_BSPC,
  _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, SC_LSPO, SC_RSPC, KC_COMM, KC_SLSH, _______,
           _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______
),
/* NAV
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Paste| Copy | Cut  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      |-------.    ,-------| Left | Down | Up   |Right |  Del | Bspc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------.    .-------| Undo | Again|      |      |      |      |
 * `-----------------------------------------|-------.    .-------|-----------------------------------------'
 *               |      | NUM  | SYMB |SPACE | NAV   |    |  NAV  | ENTER| SYMB |      |BKSPC |
 *               `-----------------------------------'    '-----------------------------------
 */
[_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          C(KC_V), C(KC_C), C(KC_X), XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, XXXXXXX,       XXXXXXX,  KC_UNDO, KC_AGIN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
static const char PROGMEM windows_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe,
    0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
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
			switch (get_highest_layer(layer_state)) {
				case _QWERTY:
                case _NAV:
                case _SYMBL:
                        if (clockwise) {
                            tap_code(KC_DOWN);
                        } else {
                            tap_code(KC_UP);
                        }
                    break;
                default:
                        if (clockwise) {
                            tap_code(KC_WH_D);
                        } else {
                            tap_code(KC_WH_U);
                        }
                    break;
            }
        }
    return true;
}
#endif
