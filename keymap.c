#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCT 3
#define _ARROW 4
#define _ADJUST 5
#define _ADMINI 6

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define WINUNDO ACTION_MODS_KEY(MOD_LCTL, KC_Z)
#define WINCUT ACTION_MODS_KEY(MOD_LCTL, KC_X)
#define WINCOPY ACTION_MODS_KEY(MOD_LCTL, KC_C)
#define WINPASTE ACTION_MODS_KEY(MOD_LCTL, KC_V)
#define WINFIND ACTION_MODS_KEY(MOD_LCTL, KC_F)
#define MACUNDO ACTION_MODS_KEY(MOD_LGUI, KC_Z)
#define MACCUT ACTION_MODS_KEY(MOD_LGUI, KC_X)
#define MACCOPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define MACPASTE ACTION_MODS_KEY(MOD_LGUI, KC_V)
#define MACFIND ACTION_MODS_KEY(MOD_LGUI, KC_F)
#define ROFI ACTION_MODS_KEY(MOD_LGUI, KC_D)

// macros
#define SEND_KEYMAP_URI 0
#define MAC_COPY_PASTE 1
#define WIN_COPY_PASTE 2

// TAP DANCE
enum {
    TD_CTL_ROFI = 0
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCT,
  ARROW,
  ADJUST,
  ADMINI,
  BACKLIT,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |TD_ROF|      |      |      |      |      ||      |      |      |      |   ;  |  '   |
 * | Ctrl |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  | Arrow| Ctrl |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  [   |   Z  |      |      |      |      ||      |      |      |      |   /  |   ]  |
 * | Shift| Raise|   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  | Lower| Shift|
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Left | Right|      |      |      |      ||      |      |      |      | Down |  Up  |
 * |Adjust| Func | Alt  |DMPLY1|DMPLY2| W C/P|| Lclk | Rclk |   (  |   )  | Func | Arrow|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      | BS   || Esc  |      |      |
 *                      | GUI  |Space | Lower|| Raise| Enter| GUI  |
 *                      `--------------------'`--------------------'
 *
 *  left foot: ESC (CTL)
 *  right foot: NONE
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
  TD(TD_CTL_ROFI), KC_A, KC_S, KC_D, KC_F, KC_G,
  KC_H, KC_J, KC_K, KC_L, LT(_ARROW, KC_SCLN), CTL_T(KC_QUOT), \
  SFT_T(KC_LBRC), LT(_RAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, \
  KC_N, KC_M, KC_COMM, KC_DOT, LT(_LOWER, KC_SLSH), SFT_T(KC_RBRC), \
  LT(_ADJUST, KC_LEFT), LT(_FUNCT, KC_RGHT), KC_LALT, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, M(WIN_COPY_PASTE), \
  CTL_T(KC_ESC), KC_TRNS, \
  KC_BTN1, KC_BTN2, KC_LPRN, KC_RPRN, LT(_FUNCT, KC_DOWN), LT(_ARROW, KC_UP), \
  KC_LGUI, KC_SPC, LT(_LOWER, KC_BSPC), LT(_RAISE, KC_ESC), KC_ENT, KC_RGUI \
),

/* Lower
 * ,-----------------------------------------.,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  ||   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |      |      |      |      |W FIND|      ||      |   _  |   +  |   {  |   }  | Del  |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |W UNDO|W CUT |W COPY|WPASTE|      ||      |      |      |      |XXXXXX|      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |XXXXXX||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, WINFIND, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL, \
  _______, WINUNDO, WINCUT,  WINCOPY, WINPASTE, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------.,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |      |      |      |      |W FIND|      ||      |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |XXXXXX|W CUT |W COPY|WPASTE|      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||XXXXXX|      |      |
 *                      `--------------------'`--------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, _______, _______, _______, WINFIND, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL, \
  _______, _______, WINCUT,  WINCOPY, WINPASTE, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),


/* Function
 * ,-----------------------------------------.,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  ||  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |      |      |      |W COPY|WPASTE| ROFI ||      |DMPLY1|DMREC1|DMSTOP|      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |M COPY|MPASTE|      ||      |DMPLY2|DMREC2|KEYMAP|      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |XXXXXX|      |DMREC1|DMREC2|      ||      |      |      |      |XXXXXX|      |
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_FUNCT] = LAYOUT( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
  _______, _______, _______, WINCOPY, WINPASTE, ROFI, \
  _______, DYN_MACRO_PLAY1, DYN_REC_START1, DYN_REC_STOP, _______, _______, \
  _______, _______, _______, MACCOPY, MACPASTE, _______, \
  _______, DYN_MACRO_PLAY2, DYN_REC_START2, M(SEND_KEYMAP_URI), _______, _______, \
  _______, _______, DYN_REC_START1, DYN_REC_START2, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),

/* Arrow
 * ,-----------------------------------------.,-----------------------------------------.
 * |      |      |      |  Up  |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |      |      | Left | Down | Right|      || Left | Down |  Up  | Right|XXXXXX|      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |ADMINI|      |      |      |      |      ||      |      |      |      |      |XXXXXX|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_ARROW] = LAYOUT( \
  _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  ADMINI,  _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),

/* Adjust
 * ,-----------------------------------------.,-----------------------------------------.
 * |BL_TOG|BACKLI|      | MsUp |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      ||MsLeft|MsDown| MsUp |MsRght|      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |XXXXXX|      |      |      | Lclk | Rclk ||      |      |      |      |      |ADMINI|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_ADJUST] = LAYOUT( \
  BL_TOGG, BACKLIT, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_BTN1, KC_BTN2, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, ADMINI, \
  _______, _______, _______, _______, _______, _______ \
),

/* Admini
 * ,-----------------------------------------.,-----------------------------------------.
 * |RESET |      |      |      |      |      ||      |      |      |      |      |POWER |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |XXXXXX|      |      |      |      |      ||      |      |      |      |      |XXXXXX|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_ADMINI] = LAYOUT( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_POWER, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
)

};

static uint16_t start;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case SEND_KEYMAP_URI:
            if (record->event.pressed) {
                SEND_STRING("https://github.com/rinx/qmk_firmware_iris_rinx/blob/master/keymap.c");
            }
            break;
        case MAC_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= TAPPING_TERM)
                    return MACRO(D(LGUI), T(C), U(LGUI), END);
                else
                    return MACRO(D(LGUI), T(V), U(LGUI), END);
            }
            break;
        case WIN_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= TAPPING_TERM)
                    return MACRO(D(LCTL), T(C), U(LCTL), END);
                else
                    return MACRO(D(LCTL), T(V), U(LCTL), END);
            }
            break;
    }
    return MACRO_NONE;
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTL_ROFI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, ROFI)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case FUNCT:
      if (record->event.pressed) {
        layer_on(_FUNCT);
      } else {
        layer_off(_FUNCT);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        layer_on(_ARROW);
      } else {
        layer_off(_ARROW);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ADMINI:
      if (record->event.pressed) {
        layer_on(_ADMINI);
      } else {
        layer_off(_ADMINI);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      }
      return false;
      break;
  }
  return true;
}
