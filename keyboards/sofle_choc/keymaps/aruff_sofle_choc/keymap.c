// config.h
#include QMK_KEYBOARD_H

// Layer Names
enum sofle_layers {
    _QWERTY = 0,
    _SYMBL, // Functions Keys, Numbers, and Symbols
    _NAV,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

// Custom Keycodes for Layer Switching
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_SYMBL,
    KC_NAV,
    KC_NUMPAD,
    KC_ADJUST,
    KC_D_MUTE
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BKSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |      | LCTRL| LALT | LGUI |LSHFT |      |-------.    ,-------|      |RSHFT | RGUI | RALT | RCTRL|      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | NUM  | SYMB |SPACE | / NAV   /       \ NAV  \  |ENTER | SYMB |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY]=LAYOUT(
    KC_GRV,      KC_1,       KC_2 ,     KC_3,     KC_4,   KC_5,                        KC_6,      KC_7,      KC_8,      KC_9,         KC_0, KC_MINUS,
    KC_TAB,      KC_Q,       KC_W ,     KC_E,     KC_R,   KC_T,                        KC_Y,      KC_U,      KC_I,      KC_O,         KC_P, KC_BSPC,
    MT(KC_NAV, KC_ESC), MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F),   KC_G,                        KC_H, MT(MOD_RSFT, KC_J), MT(MOD_RGUI, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RCTL, KC_SCLN), KC_QUOT,
    KC_LSFT,     KC_Z,      KC_X,      KC_C,      KC_V,   KC_B, XXXXXXX,      XXXXXXX, KC_N,      KC_M,   KC_COMM,    KC_DOT,      KC_SLSH, KC_RSFT,
              XXXXXXX, KC_NUMPAD,  KC_SYMBL,    KC_SPC, KC_NAV,                        KC_NAV,  KC_ENT,  KC_SYMBL,   XXXXXXX,      XXXXXXX
),

/* SYMBL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      | F10  | F11  | F12  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |      |                    |      |   {  |   }  |   |  |   \  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  F4  |  F5  |  F6  |      |-------.    ,-------|      |   [  |   ]  |   +  |   -  |BKSPC |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  F1  |  F2  |  F3  |      |-------|    |-------|      |   (  |   )  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | NUM  | SYMB |SPACE | / NAV   /       \ NAV  \  |ENTER | SYMB |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBL] = LAYOUT(
  XXXXXXX, XXXXXXX,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                         XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, XXXXXXX,
  XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                         XXXXXXX, KC_LBRC, KC_RBRC, KC_PLUS, KC_MINUS, KC_BSPC,
  XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, SC_LSPO, SC_RSPC, XXXXXXX, XXXXXXX, XXXXXXX,
           _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______
),
/* NAV
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      |-------.    ,-------| Left | Down | Up   |Right |  Del | Bspc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | LCMD |SPACE | / NAV   /       \ NAV  \  |ENTER |SYMBL |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,
  _______, _______, _______, _______, _______, _______,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|hue^ |sat ^ | bri ^|      |      |-------.    ,-------|desk <|      |      |desk >|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn|      |QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | LCMD |SPACE | / NAV   /       \ NAV  \  |ENTER |SYMBL |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, _______,_______,             C(G(KC_LEFT)),KC_NO,KC_NO,C(G(KC_RGHT)),XXXXXXX, XXXXXXX,
  RGB_MOD, RGB_HUD,RGB_SAD, RGB_VAD, XXXXXXX,KC_QWERTY,XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |  eq  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | NUM  | SYMB |SPACE | / NAV   /       \ NAV  \  |ENTER | SYMB |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______, KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
                    _______, _______, _______, _______, _______,  _______, _______,  KC_P0,   KC_PDOT, _______
),
/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | qwer |low   |raise |adj   |numpad|      |                    |      |      |      |      |      |QK_BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EE_CLR|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | NUM  | SYMB |SPACE | / NAV   /       \ NAV  \  |ENTER | SYMB |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  KC_NO,   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
  KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
	),
};

//--------------------------------------------------------------------------------------------------
// OLED Display
//--------------------------------------------------------------------------------------------------
#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false); // Write the QMK Logo
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("Anwar\nRuff\n"), false);
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _SYMBL:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Switch\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_270 : rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}
#endif
//--------------------------------------------------------------------------------------------------
// Button event listener
//--------------------------------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_SYMBL:
            if (record->event.pressed) {
                layer_on(_SYMBL);
                update_tri_layer(_SYMBL, _NAV, _ADJUST);
            } else {
                layer_off(_SYMBL);
                update_tri_layer(_SYMBL, _NAV, _ADJUST);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
                update_tri_layer(_SYMBL, _NAV, _ADJUST);
            } else {
                layer_off(_NAV);
                update_tri_layer(_SYMBL, _NAV, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
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
