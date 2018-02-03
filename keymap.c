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

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP

#define NEXTWKS ACTION_MODS_KEY(MOD_LCTL, KC_RGHT)
#define PREVWKS ACTION_MODS_KEY(MOD_LCTL, KC_LEFT)
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)
#define WINCOPY ACTION_MODS_KEY(MOD_LCTL, KC_C)
#define WINPASTE ACTION_MODS_KEY(MOD_LCTL, KC_V)
#define MACUNDO ACTION_MODS_KEY(MOD_LGUI, KC_Z)
#define MACCUT ACTION_MODS_KEY(MOD_LGUI, KC_X)
#define MACCOPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define MACPASTE ACTION_MODS_KEY(MOD_LGUI, KC_V)
#define MACFIND ACTION_MODS_KEY(MOD_LGUI, KC_F)
#define SPTLGHT ACTION_MODS_KEY(MOD_LGUI, KC_SPC)
#define MISSIONCTL ACTION_MODS_KEY(MOD_LCTL, KC_UP)
#define NEXTAPP ACTION_MODS_KEY(MOD_LGUI, KC_TAB)
#define PREVAPP ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_TAB)

#define SCR_BR_UP KC_PAUS
#define SCR_BR_DOWN KC_SLCK

// macros
#define SEND_KEYMAP_URI 0
#define MAC_COPY_PASTE 1
#define WIN_COPY_PASTE 2

// TAP DANCE
enum {
    TD_CTL_SPL = 0,
    TD_PRN_PREVWK,
    TD_PRN_NEXTWK
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCT,
  ARROW,
  ADJUST,
  ADMINI,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------||------O------+------+------+------+------|
 * |DMSTOP|      |      |      |      |      ||      |      |      |      |   ;  |  '   |
 * | Ctrl |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  | Arrow| Ctrl |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  [   |   Z  |      |      |      |      ||      |      |      |      |   /  |   ]  |
 * | Shift| Raise|   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  | Lower| Shift|
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      | Left |      |      |      |      ||      |      |TD_PWK|TD_NWK| Right|      |
 * |Adjust| Func | Alt  |DMPLY1|DMPLY2|SPTLGT|| Lclk | Rclk |   (  |   )  | Func | Arrow|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      | BS   || Esc  |      |      |
 *                      | GUI  |Space | Lower|| Raise| Enter|MSNCTL|
 *                      `--------------------'`--------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
  CTL_T(DYN_REC_STOP), KC_A, KC_S, KC_D, KC_F, KC_G,
  KC_H, KC_J, KC_K, KC_L, LT(_ARROW, KC_SCLN), CTL_T(KC_QUOT), \
  SFT_T(KC_LBRC), LT(_RAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, \
  KC_N, KC_M, KC_COMM, KC_DOT, LT(_LOWER, KC_SLSH), SFT_T(KC_RBRC), \
  TT(_ADJUST), LT(_FUNCT, KC_LEFT), KC_LALT, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, SPTLGHT, \
  KC_TRNS, KC_TRNS, \
  KC_BTN1, KC_BTN2, TD(TD_PRN_PREVWK), TD(TD_PRN_NEXTWK), LT(_FUNCT, KC_RGHT), TT(_ARROW), \
  KC_LGUI, KC_SPC, LT(_LOWER, KC_BSPC), LT(_RAISE, KC_ESC), KC_ENT, MISSIONCTL \
),

/* Lower
 * ,-----------------------------------------.,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  ||   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |   _  |   +  |   {  |   }  | Del  |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |XXXXXX|      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |XXXXXX||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------.,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |XXXXXX|      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||XXXXXX|      |      |
 *                      `--------------------'`--------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),


/* Function
 * ,-----------------------------------------.,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  ||  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |SCBRI+|      |M COPY|MPASTE|SPTLGT||MSNCTL|DMPLY1|DMREC1|DMSTOP|Vol + |Vol mt|
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |SCBRI-|      |W COPY|WPASTE|PREVWK||NEXTWK|DMPLY2|DMREC2|KEYMAP|Vol - |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |XXXXXX|      |DMREC1|DMREC2|      ||      |      |      |      |XXXXXX|      |
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_FUNCT] = KEYMAP( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
  _______, SCR_BR_UP, _______, MACCOPY, MACPASTE, SPTLGHT, \
  MISSIONCTL, DYN_MACRO_PLAY1, DYN_REC_START1, DYN_REC_STOP, KC_VOLU, KC_MUTE, \
  _______, SCR_BR_DOWN, _______, WINCOPY, WINPASTE, PREVWKS, \
  NEXTWKS, DYN_MACRO_PLAY2, DYN_REC_START2, M(SEND_KEYMAP_URI), KC_VOLD, _______, \
  _______, _______, DYN_REC_START1, DYN_REC_START2, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),

/* Arrow
 * ,-----------------------------------------.,-----------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      || Left | Down |  Up  | Right|XXXXXX|      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |ADMINI|      |      |      |      |      ||      |      |      |      |      |XXXXXX|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_ARROW] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  ADMINI,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),

/* Adjust
 * ,-----------------------------------------.,-----------------------------------------.
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |XXXXXX|      |      |      |      |      ||      |      |      |      |      |ADMINI|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_ADJUST] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ADMINI, \
  _______, _______, _______, _______, _______, _______, \
  KC_TRNS, KC_TRNS, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______ \
),

/* Admini
 * ,-----------------------------------------.,-----------------------------------------.
 * |RESET |      |      |      |      |      ||      |      |      |      |      |POWER |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |XXXXXX|      |      |      |      |      ||      |      |      |      |      |XXXXXX|
 * `------+------+------+------+------+------||------+------+------+------+------+------'
 *                      |      |      |      ||      |      |      |
 *                      `--------------------'`--------------------'
 */
[_ADMINI] = KEYMAP( \
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
  [TD_CTL_SPL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, SPTLGHT),
  [TD_PRN_PREVWK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, PREVWKS),
  [TD_PRN_NEXTWK] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, NEXTWKS)
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
  }
  return true;
}
