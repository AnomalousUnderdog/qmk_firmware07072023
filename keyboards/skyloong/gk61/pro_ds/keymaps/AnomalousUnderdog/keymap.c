// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "config.h"

// ---------------------------------------------------------------------------------

#define BASE_LAYER 0
#define GAMING_LAYER 1
#define FN1_LAYER 2
#define FN2_LAYER 3
#define FN3_LAYER 4
#define CAPS_LOCK_LAYER 5
#define RIGHT_SPACE_LAYER 6

// ---------------------------------------------------------------------------------

// IDE

// Navigate to (Ctrl + Shift + G)
#define IDE_NAV_TO LCS(KC_G)

// Find all usages (Ctrl + Shift + Equals)
#define IDE_USAGES C(S(KC_EQUAL))

// Go to declaration or usages (Ctrl + B)
#define IDE_TO_DECL C(KC_B)

// Go to implementation (Ctrl + Alt + Shift + B)
#define IDE_TO_IMPL MEH(KC_B)

// Navigate file member (Ctrl + F12)
#define IDE_NAV_MEMBR C(KC_F12)

// Rename (F2)
#define IDE_RENAME KC_F2

// Hold for Caps Lock layer. Tap once for Navigate file member.
#define CAPS_MEMBR LT(CAPS_LOCK_LAYER,IDE_NAV_MEMBR)

// Hold for Caps Lock layer. Double-tap to send Navigate file member.
#define CAPS_DBL_MEMBR LT(0,KC_1)

// --------------------------------------

// OBS

// Start screen recording (Ctrl + Shift + Alt + Left Bracket)
#define OBS_REC_STA MEH(KC_LEFT_BRACKET)

// Stop screen recording (Ctrl + Shift + Alt + Right Bracket)
#define OBS_REC_STP MEH(KC_RIGHT_BRACKET)

// --------------------------------------

// Browser

// Reopen closed tab (Ctrl + Shift + T)
#define REOPEN_TAB LCS(KC_T)

// Previous tab (Ctrl + Shift + Tab)
#define PREV_TAB LCS(KC_TAB)

// Next tab (Ctrl + Tab)
#define NEXT_TAB C(KC_TAB)

// Close tab (Ctrl + W)
#define CLOSE_TAB C(KC_W)

// --------------------------------------

// Desktop

// Previous virtual desktop (Ctrl + Win + Left)
#define PREV_DESKTOP LCG(KC_LEFT)

// Next virtual desktop (Ctrl + Win + Right)
#define NEXT_DESKTOP LCG(KC_RGHT)

// Task Manager (Ctrl + Shift + Esc)
#define TASK_MGR LCS(KC_ESC)

// ---------------------------------------------------------------------------------
// Tap Dance declarations

enum {
    // Tap once for Home, twice for Ctrl + Home
    TD_HOME_CTRL_HOME,

    // Tap once for End, twice for Ctrl + End
    TD_END_CTRL_END,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_HOME_CTRL_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, C(KC_HOME)),
    [TD_END_CTRL_END] = ACTION_TAP_DANCE_DOUBLE(KC_END, C(KC_END)),
};

// --------------------------------------

// Tap once for Home, twice for Ctrl + Home
#define TD_HOME TD(TD_HOME_CTRL_HOME)

// Tap once for End, twice for Ctrl + End
#define TD_END TD(TD_END_CTRL_END)

// ---------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │   |Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   |Sft|   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │Spc│Mut│   │   |Spc|Alt│App│Ctl│   │Mo1|
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [BASE_LAYER] = LAYOUT_all(
         KC_ESC,     KC_1,     KC_2,   KC_3,   KC_4,    KC_5,   KC_6,  KC_7,     KC_8,     KC_9,           KC_0,     KC_MINS,        KC_EQL,                KC_BSPC,
         KC_TAB,     KC_Q,     KC_W,   KC_E,   KC_R,    KC_T,   KC_Y,  KC_U,     KC_I,     KC_O,           KC_P,     KC_LBRC,       KC_RBRC,                KC_BSLS,
        CAPS_DBL_MEMBR,     KC_A,     KC_S,   KC_D,   KC_F,    KC_G,   KC_H,  KC_J,     KC_K,     KC_L,        KC_SCLN,     KC_QUOT,                  KC_ENT,
        KC_LSFT,     KC_Z,     KC_X,   KC_C,   KC_V,    KC_B,   KC_N,  KC_M,  KC_COMM,   KC_DOT,        KC_SLSH,                   MT(MOD_RSFT,KC_UP),
        KC_LCTL,  KC_LGUI,  KC_LALT,   KC_SPC,  KC_SPC,   LT(RIGHT_SPACE_LAYER,KC_SPC),  KC_RALT, LT(FN1_LAYER,KC_LEFT),  LT(FN2_LAYER,KC_DOWN), MT(MOD_RCTL,KC_RGHT)
    ),

    [GAMING_LAYER] = LAYOUT_all(
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_KP_ASTERISK,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,            _______,
        _______,  KC_KP_PLUS,  _______,                _______,  _______,                              KC_KP_MINUS,  _______,  _______,  _______,  _______
    ),

    [FN1_LAYER] = LAYOUT_all(
        _______,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,     KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,   KC_F23,   KC_F24,   KC_DEL,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  KC_PSCR,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  KC_CALC,  _______,  _______,     _______,  _______,  MS_WHLU,  MS_WHLD,  _______,            KC_APP,
        _______,  TG(GAMING_LAYER),  _______,                _______,  _______,                                 _______,  _______,  _______,  MO(FN3_LAYER),  _______
    ),

    [FN2_LAYER] = LAYOUT_all(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BRID,  KC_BRIU,  KC_VOLD,  KC_VOLU,  KC_MUTE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  KC_MEDIA_STOP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            OBS_REC_STA,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_VALD,  RM_VALU,  TASK_MGR,            OBS_REC_STP,
        _______,  _______,  _______,                _______,  _______,                              _______,  _______,  MO(FN3_LAYER),  _______,  RM_TOGG
    ),

    [FN3_LAYER] = LAYOUT_all(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_MAKE,  QK_BOOTLOADER,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______ , _______,  _______,                _______,  _______,                              _______,  _______,  _______,  _______,  _______
    ),

    [CAPS_LOCK_LAYER] = LAYOUT_all(
        _______,      _______,    _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,      KC_CAPS,
        TD_HOME,  IDE_NAV_TO,    IDE_TO_DECL,  _______,  IDE_RENAME,  _______,     KC_P7,    KC_P8,    KC_P9,  _______,  _______,  _______,  _______,  KC_NUM_LOCK,
        _______,  IDE_USAGES,  IDE_TO_IMPL,  _______,  _______,  _______,     KC_P4,    KC_P5,    KC_P6,  _______,  _______,  _______,                KC_PENT,
        TD_END,  _______,  _______,  _______,  _______,  _______,     KC_P1,    KC_P2,    KC_P3,  _______,  _______,            _______,
        REOPEN_TAB, PREV_TAB,  NEXT_TAB,                CLOSE_TAB,  _______,                                 KC_P0,  KC_PDOT, _______,  _______,  _______
    ),

    [RIGHT_SPACE_LAYER] = LAYOUT_all(
         KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,    KC_UP,  KC_PGDN,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,   KC_ENT,  KC_RSFT,  KC_PENT,  _______,  _______,            _______,
        _______,  _______,  _______,                _______,  _______,                              _______,  PREV_DESKTOP,  NEXT_DESKTOP,  _______,  _______
    ),
};

// ---------------------------------------------------------------------------------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAPS_DBL_MEMBR:
            // Double-tap to send Navigate file member, Hold to activate CAPS_LOCK_LAYER
            if (record->tap.count >= 2 && record->event.pressed) {
                tap_code16(IDE_NAV_MEMBR);
            } else if (record->event.pressed) {
                layer_on(CAPS_LOCK_LAYER);
            } else {
                layer_off(CAPS_LOCK_LAYER);
            }
            return false;
    }
    return true;
}

// ---------------------------------------------------------------------------------

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_RSFT,KC_UP):
            return TAPPING_TERM + 1250;
        default:
            return TAPPING_TERM;
    }
}

// ---------------------------------------------------------------------------------

#define INDEX_ESC 0
#define INDEX_KEY_1 1
#define INDEX_KEY_2 2
#define INDEX_KEY_3 3
#define INDEX_KEY_4 4
#define INDEX_KEY_5 5
#define INDEX_KEY_6 6
#define INDEX_KEY_7 7
#define INDEX_KEY_8 8
#define INDEX_KEY_9 9
#define INDEX_KEY_0 10
#define INDEX_DASH 11
#define INDEX_EQUALS 12
#define INDEX_BACKSPACE 13
#define INDEX_TAB 14
#define INDEX_KEY_Q 15
#define INDEX_KEY_W 16
#define INDEX_KEY_E 17
#define INDEX_KEY_R 18
#define INDEX_KEY_T 19
#define INDEX_KEY_Y 20
#define INDEX_KEY_U 21
#define INDEX_KEY_I 22
#define INDEX_KEY_O 23
#define INDEX_KEY_P 24
#define INDEX_LEFT_BRACKET 25
#define INDEX_RIGHT_BRACKET 26
#define INDEX_BACKSLASH 27
#define INDEX_CAPS_LOCK 28
#define INDEX_KEY_A 29
#define INDEX_KEY_S 30
#define INDEX_KEY_D 31
#define INDEX_KEY_F 32
#define INDEX_KEY_G 33
#define INDEX_KEY_H 34
#define INDEX_KEY_J 35
#define INDEX_KEY_K 36
#define INDEX_KEY_L 37
#define INDEX_SEMI_COLON 38
#define INDEX_SINGLE_QUOTE 39
#define INDEX_ENTER 40
#define INDEX_LEFT_SHIFT 41
#define INDEX_KEY_Z 42
#define INDEX_KEY_X 43
#define INDEX_KEY_C 44
#define INDEX_KEY_V 45
#define INDEX_KEY_B 46
#define INDEX_KEY_N 47
#define INDEX_KEY_M 48
#define INDEX_COMMA 49
#define INDEX_DOT 50
#define INDEX_SLASH 51
#define INDEX_RIGHT_SHIFT 52
#define INDEX_LEFT_CTRL 53
#define INDEX_LEFT_WIN 54
#define INDEX_LEFT_ALT 55
#define INDEX_LEFT_SPACEBAR 56
#define INDEX_RIGHT_SPACEBAR 57
#define INDEX_RIGHT_ALT 59
#define INDEX_FN_1 60
#define INDEX_FN_2 61
#define INDEX_RIGHT_CTRL 62

// ---------------------------------------------------------------------------------

#define SCREEN_RIGHTNESS_KEYS_COLOUR RGB_WHITE
#define KB_BRIGHTNESS_KEYS_HSV_COLOUR HSV_WHITE
#define VOLUME_KEYS_COLOUR RGB_ORANGE

#define MEDIA_KEYS_COLOUR 0x00, 0xD8, 0xFF
#define OBS_KEYS_COLOUR RGB_RED

#define NAV_KEYS_COLOUR RGB_PURPLE
#define IDE_KEYS_COLOUR RGB_ORANGE
#define TAB_KEYS_COLOUR 0x00, 0xD8, 0xFF

#define NUMPAD_ROW_1_COLOUR 0x00, 0xD8, 0xFF
#define NUMPAD_ROW_2_COLOUR 0x00, 0x82, 0xFF
#define NUMPAD_ROW_3_COLOUR 0x00, 0x50, 0xFF
#define NUMPAD_ROW_4_COLOUR 0x00, 0x25, 0xFF

#define LOCK_KEYS_COLOUR RGB_ORANGE

#define F_ROW_COLOUR RGB_PURPLE
#define ARROW_KEYS_COLOUR RGB_ORANGE
#define ARROW_COMPLEMENT_KEYS_COLOUR 0xFF, 0xD0, 0x43
#define DESKTOP_KEYS_COLOUR RGB_RED

// ---------------------------------------------------------------------------------

bool rgb_matrix_indicators_user() {

    if (IS_LAYER_ON(FN3_LAYER)) {
        rgb_matrix_set_color_all(RGB_OFF);

        rgb_matrix_set_color(INDEX_KEY_9, RGB_RED); // QK_MAKE
        rgb_matrix_set_color(INDEX_KEY_0, RGB_RED); // bootloader

    } else if (IS_LAYER_ON(FN1_LAYER)) {
        rgb_matrix_set_color_all(RGB_OFF);

        rgb_matrix_set_color(INDEX_KEY_1, F_ROW_COLOUR); // F13
        rgb_matrix_set_color(INDEX_KEY_2, F_ROW_COLOUR); // F14
        rgb_matrix_set_color(INDEX_KEY_3, F_ROW_COLOUR); // F15
        rgb_matrix_set_color(INDEX_KEY_4, F_ROW_COLOUR); // F16
        rgb_matrix_set_color(INDEX_KEY_5, F_ROW_COLOUR); // F17
        rgb_matrix_set_color(INDEX_KEY_6, F_ROW_COLOUR); // F18
        rgb_matrix_set_color(INDEX_KEY_7, F_ROW_COLOUR); // F19
        rgb_matrix_set_color(INDEX_KEY_8, F_ROW_COLOUR); // F20
        rgb_matrix_set_color(INDEX_KEY_9, F_ROW_COLOUR); // F21
        rgb_matrix_set_color(INDEX_KEY_0, F_ROW_COLOUR); // F22
        rgb_matrix_set_color(INDEX_DASH, F_ROW_COLOUR); // F23
        rgb_matrix_set_color(INDEX_EQUALS, F_ROW_COLOUR); // F24
        rgb_matrix_set_color(INDEX_BACKSPACE, RGB_RED); // delete

        rgb_matrix_set_color(INDEX_KEY_C, RGB_BLUE); // calculator
        rgb_matrix_set_color(INDEX_KEY_P, RGB_GREEN); // print-screen (screenshot)
        rgb_matrix_set_color(INDEX_RIGHT_SHIFT, RGB_YELLOW); // menu key

        rgb_matrix_set_color(INDEX_COMMA, NAV_KEYS_COLOUR); // mouse wheel up
        rgb_matrix_set_color(INDEX_DOT, NAV_KEYS_COLOUR); // mouse wheel down

    } else if (IS_LAYER_ON(FN2_LAYER)) {
        rgb_matrix_set_color_all(RGB_OFF);

        // media
        rgb_matrix_set_color(INDEX_KEY_P, MEDIA_KEYS_COLOUR); // play/pause
        rgb_matrix_set_color(INDEX_LEFT_BRACKET, MEDIA_KEYS_COLOUR); // prev
        rgb_matrix_set_color(INDEX_RIGHT_BRACKET, MEDIA_KEYS_COLOUR); // next
        rgb_matrix_set_color(INDEX_BACKSLASH, MEDIA_KEYS_COLOUR); // stop

        // volume keys
        rgb_matrix_set_color(INDEX_DASH, VOLUME_KEYS_COLOUR); // down
        rgb_matrix_set_color(INDEX_EQUALS, VOLUME_KEYS_COLOUR); // up
        rgb_matrix_set_color(INDEX_BACKSPACE, VOLUME_KEYS_COLOUR); // toggle mute

        // OBS
        rgb_matrix_set_color(INDEX_ENTER, OBS_KEYS_COLOUR); // start recording
        rgb_matrix_set_color(INDEX_RIGHT_SHIFT, OBS_KEYS_COLOUR); // stop recording

        // keyboard brightness
        hsv_t kb_brightness_hsv = {KB_BRIGHTNESS_KEYS_HSV_COLOUR};
        kb_brightness_hsv.v = rgb_matrix_get_val();
        rgb_t kb_brightness_rgb = hsv_to_rgb(kb_brightness_hsv);

        rgb_matrix_set_color(INDEX_RIGHT_CTRL, kb_brightness_rgb.r, kb_brightness_rgb.g, kb_brightness_rgb.b); // toggle off/on
        rgb_matrix_set_color(INDEX_COMMA, kb_brightness_rgb.r, kb_brightness_rgb.g, kb_brightness_rgb.b); // down
        rgb_matrix_set_color(INDEX_DOT, kb_brightness_rgb.r, kb_brightness_rgb.g, kb_brightness_rgb.b); // up

        rgb_matrix_set_color(INDEX_SLASH, RGB_BLUE); // Task Manager

        // screen brightness
        rgb_matrix_set_color(INDEX_KEY_9, SCREEN_RIGHTNESS_KEYS_COLOUR); // down
        rgb_matrix_set_color(INDEX_KEY_0, SCREEN_RIGHTNESS_KEYS_COLOUR); // up
    }

    if (IS_LAYER_ON(GAMING_LAYER)) {
        rgb_matrix_set_color(INDEX_LEFT_WIN, RGB_RED);

    } else if (IS_LAYER_ON(CAPS_LOCK_LAYER)) {
        rgb_matrix_set_color_all(RGB_OFF);

        rgb_matrix_set_color(INDEX_TAB, NAV_KEYS_COLOUR); // home
        rgb_matrix_set_color(INDEX_LEFT_SHIFT, NAV_KEYS_COLOUR); // end

        // ide keys
        rgb_matrix_set_color(INDEX_KEY_Q, IDE_KEYS_COLOUR);
        rgb_matrix_set_color(INDEX_KEY_W, IDE_KEYS_COLOUR);
        rgb_matrix_set_color(INDEX_KEY_A, IDE_KEYS_COLOUR);
        rgb_matrix_set_color(INDEX_KEY_S, IDE_KEYS_COLOUR);
        rgb_matrix_set_color(INDEX_KEY_R, IDE_KEYS_COLOUR);

        // tab keys
        rgb_matrix_set_color(INDEX_LEFT_CTRL, TAB_KEYS_COLOUR); // reopen closed tab
        rgb_matrix_set_color(INDEX_LEFT_WIN, TAB_KEYS_COLOUR); // prev tab
        rgb_matrix_set_color(INDEX_LEFT_ALT, TAB_KEYS_COLOUR); // next tab
        rgb_matrix_set_color(INDEX_LEFT_SPACEBAR, TAB_KEYS_COLOUR); // close tab

        // numpad
        rgb_matrix_set_color(INDEX_KEY_Y, NUMPAD_ROW_1_COLOUR); // 7
        rgb_matrix_set_color(INDEX_KEY_U, NUMPAD_ROW_1_COLOUR); // 8
        rgb_matrix_set_color(INDEX_KEY_I, NUMPAD_ROW_1_COLOUR); // 9

        rgb_matrix_set_color(INDEX_KEY_H, NUMPAD_ROW_2_COLOUR); // 4
        rgb_matrix_set_color(INDEX_KEY_J, NUMPAD_ROW_2_COLOUR); // 5
        rgb_matrix_set_color(INDEX_KEY_K, NUMPAD_ROW_2_COLOUR); // 6

        rgb_matrix_set_color(INDEX_KEY_N, NUMPAD_ROW_3_COLOUR); // 1
        rgb_matrix_set_color(INDEX_KEY_M, NUMPAD_ROW_3_COLOUR); // 2
        rgb_matrix_set_color(INDEX_COMMA, NUMPAD_ROW_3_COLOUR); // 3

        rgb_matrix_set_color(INDEX_RIGHT_SPACEBAR, NUMPAD_ROW_4_COLOUR); // 0
        rgb_matrix_set_color(INDEX_RIGHT_ALT, NUMPAD_ROW_4_COLOUR); // .
        rgb_matrix_set_color(INDEX_ENTER, NUMPAD_ROW_4_COLOUR); // Numpad Enter

        // other
        rgb_matrix_set_color(INDEX_BACKSPACE, LOCK_KEYS_COLOUR); // Caps Lock
        rgb_matrix_set_color(INDEX_BACKSLASH, LOCK_KEYS_COLOUR); // Num Lock

    } else if (IS_LAYER_ON(RIGHT_SPACE_LAYER)) {
        rgb_matrix_set_color_all(RGB_OFF);

        rgb_matrix_set_color(INDEX_ESC, F_ROW_COLOUR); // grave/tilde
        rgb_matrix_set_color(INDEX_KEY_1, F_ROW_COLOUR); // F1
        rgb_matrix_set_color(INDEX_KEY_2, F_ROW_COLOUR); // F2
        rgb_matrix_set_color(INDEX_KEY_3, F_ROW_COLOUR); // F3
        rgb_matrix_set_color(INDEX_KEY_4, F_ROW_COLOUR); // F4
        rgb_matrix_set_color(INDEX_KEY_5, F_ROW_COLOUR); // F5
        rgb_matrix_set_color(INDEX_KEY_6, F_ROW_COLOUR); // F6
        rgb_matrix_set_color(INDEX_KEY_7, F_ROW_COLOUR); // F7
        rgb_matrix_set_color(INDEX_KEY_8, F_ROW_COLOUR); // F8
        rgb_matrix_set_color(INDEX_KEY_9, F_ROW_COLOUR); // F9
        rgb_matrix_set_color(INDEX_KEY_0, F_ROW_COLOUR); // F10
        rgb_matrix_set_color(INDEX_DASH, F_ROW_COLOUR); // F11
        rgb_matrix_set_color(INDEX_EQUALS, F_ROW_COLOUR); // F12
        rgb_matrix_set_color(INDEX_BACKSPACE, RGB_RED); // delete

        // arrow keys
        rgb_matrix_set_color(INDEX_KEY_U, ARROW_KEYS_COLOUR); // up
        rgb_matrix_set_color(INDEX_KEY_H, ARROW_KEYS_COLOUR); // left
        rgb_matrix_set_color(INDEX_KEY_J, ARROW_KEYS_COLOUR); // down
        rgb_matrix_set_color(INDEX_KEY_K, ARROW_KEYS_COLOUR); // right

        rgb_matrix_set_color(INDEX_KEY_Y, ARROW_COMPLEMENT_KEYS_COLOUR); // page-up
        rgb_matrix_set_color(INDEX_KEY_I, ARROW_COMPLEMENT_KEYS_COLOUR); // page-down

        rgb_matrix_set_color(INDEX_KEY_N, ARROW_COMPLEMENT_KEYS_COLOUR); // enter
        rgb_matrix_set_color(INDEX_KEY_M, ARROW_COMPLEMENT_KEYS_COLOUR); // right shift
        rgb_matrix_set_color(INDEX_COMMA, ARROW_COMPLEMENT_KEYS_COLOUR); // numpad enter

        // virtual desktop
        rgb_matrix_set_color(INDEX_RIGHT_ALT, DESKTOP_KEYS_COLOUR); // prev
        rgb_matrix_set_color(INDEX_FN_1, DESKTOP_KEYS_COLOUR); // next
    }

    return false;
}

// ---------------------------------------------------------------------------------
