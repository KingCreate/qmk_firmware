#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _NAV,
    _ADJUST,
    _TEST,
    _GAMING,
};

enum custom_keycodes {
    KC_COLEMAK = SAFE_RANGE,
    KC_LOWER,
    KC_NAV,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

enum {
    TD_idk,
};

enum Mode {
  ARROW,
  PG,

  // Useful for tracking the total nr of modes
  _NUM_MODES,
};

static enum Mode cur_mode = ARROW;

// Tap Dance definitions - minimal required array
tap_dance_action_t tap_dance_actions[] = {};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * COLEMAK
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |   [  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  =   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  ]   |A/GUI | R/Alt|S/Ctrl|T/shift|   G  |-------.   ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * |   \  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  | Menu |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | HOME | HOME | esc  |space | /tab    /       \Enter \  |Bspace| Del  | END  | QWRT |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_COLEMAK] = LAYOUT( \
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
        KC_LBRC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_EQL, \
        KC_RBRC,   MT(MOD_LGUI,KC_A), MT(MOD_LALT,KC_R), MT(MOD_LCTL,KC_S), MT(MOD_LSFT,KC_T), MT(MOD_MEH,KC_G), MT(MOD_HYPR,KC_M), MT(MOD_RSFT,KC_N), MT(MOD_RCTL,KC_E), MT(MOD_RALT, KC_I), MT(MOD_RGUI,KC_O),  KC_QUOT, \
        KC_BSLS,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,      XXXXXXX,KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_APP, \
                        KC_HOME,KC_HOME,KC_ESC,KC_SPC, LT(_LOWER,KC_TAB),      KC_ENT,  KC_BSPC, KC_DEL, KC_END, TG(_QWERTY)  \
    ),
    /*
    * Gaming
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_GAMING] = LAYOUT(\
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        KC_RBRC,  KC_A,     KC_R,   KC_S,    KC_T,  KC_G,   KC_M,                    KC_N, KC_E, KC_I, KC_O,  KC_QUOT, \
        _______, _______, _______, _______, _______, _______, _______,                  _______,      _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),
    /*
    * QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_QWERTY] = LAYOUT(\
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        KC_RBRC,  KC_A,     KC_R,   KC_S,    KC_T,  KC_G,   KC_M,                    KC_N, KC_E, KC_I, KC_O,  KC_QUOT, \
        _______, _______, _______, _______, _______, _______, _______,                  _______,      _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),
    /* LOWER
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_LOWER] = LAYOUT( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, \
                            _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______\
    ),
    /* RAISE
    * ,----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
    * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
    * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_NAV] = LAYOUT( \
        _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______, \
        _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC, \
        _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC, \
        _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______, \
                                _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
    ),
    /* TEST
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_TEST] = LAYOUT( \
        XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        QK_BOOT  , XXXXXXX,XXXXXXX,KC_COLEMAK,CG_TOGG,XXXXXXX,                     KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX, \
        XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, \
        XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _NAV, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _NAV, _ADJUST);
            }
            return false;
        case _NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
                update_tri_layer(_LOWER, _NAV, _ADJUST);
            } else {
                layer_off(_NAV);
                update_tri_layer(_LOWER, _NAV, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_MUTE:
            if (record->event.pressed) {
                cur_mode = (cur_mode + 1) % _NUM_MODES;
            }
            return false;
    }
    return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (cur_mode)
    {
    case PG:
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
        break;
    case ARROW:
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_LEFT);
            } else {
                tap_code(KC_RIGHT);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        }
        break;

    default:
        break;
    }

    return false;
}
