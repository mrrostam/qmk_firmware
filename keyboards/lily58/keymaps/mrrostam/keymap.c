#include QMK_KEYBOARD_H

#include "transactions.h"

#include "./util/mrrostam.h"
#include "layers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
      KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                                      KC_6,             KC_7,    KC_8,    KC_9,     KC_0,     KC_ESC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,                                      KC_Y,             KC_U,    KC_I,    KC_O,     KC_P,     KC_MINS,
      KC_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                                      KC_H,             KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,              KC_LBRC,      KC_RBRC,  KC_N,             KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,
                                    KC_LALT, KC_LGUI, LT(_NAV, KC_BSPC), KC_SPC,       KC_ENT,   LT(_SYM, KC_DEL), KC_BSPC, KC_DEL
      ),

    [_COLEMAK] = LAYOUT(
      KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                                      KC_6,             KC_7,    KC_8,    KC_9,     KC_0,     KC_ESC,
      KC_TAB,   KC_Q,     KC_W,     KC_F,    KC_P,    KC_B,                                      KC_J,             KC_L,    KC_U,    KC_Y,     KC_SCLN,  KC_MINS,
      KC_LCTL,  KC_A,     KC_R,     KC_S,    KC_T,    KC_G,                                      KC_M,             KC_N,    KC_E,    KC_I,     KC_O,     KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_D,    KC_V,              KC_LBRC,      KC_RBRC,  KC_K,             KC_H,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,
                                    KC_LALT, KC_LGUI, LT(_NAV, KC_BSPC), KC_SPC,       KC_ENT,   LT(_SYM, KC_DEL), KC_BSPC, KC_DEL
      ),

    [_GAMING] = LAYOUT(
      KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                                      KC_6,    KC_7,    KC_8,             KC_9,     KC_0,     KC_ESC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,    KC_I,             KC_O,     KC_P,     KC_MINS,
      KC_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                                      KC_H,    KC_J,    KC_K,             KC_L,     KC_SCLN,  KC_TAB,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,              KC_LBRC,      KC_RBRC,  KC_N,    KC_M,    KC_COMM,          KC_DOT,   KC_SLSH,  KC_RSFT,
                                    KC_LALT, KC_LGUI, LT(_NAV, KC_BSPC), KC_ENT,       KC_SPC,   KC_LALT, KC_LCTL, LT(_SYM, KC_DEL)
      ),

    [_SYM] = LAYOUT(
    _______,  _______,  _______,  _______, _______, _______,                         DF(_QWERTY), DF(_COLEMAK), DF(_GAMING), XXXXXXX,  XXXXXXX,  QK_BOOT,
      KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,                           KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
      KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,  KC_TILD,
      _______,  _______,  _______,  _______, _______, _______, _______,      _______,  XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR,  KC_RCBR,  KC_PIPE,
                                    _______, _______, _______, _______,      _______,  _______, _______, _______
      ),

    [_NAV] = LAYOUT(
      _______,  _______,  _______,  _______, _______, _______,                         _______, _______, _______, _______,  _______,  _______,
      KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                            KC_6,        KC_7,         KC_8,        KC_9,     KC_0,     _______,
      KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,                           KC_LEFT,     KC_DOWN,      KC_UP,       KC_RGHT,  XXXXXXX,  XXXXXXX,
      KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______,      _______,  KC_PLUS,     KC_MINS,      KC_EQL,      KC_LBRC,  KC_RBRC,  KC_BSLS,
                                    _______, _______, _______, _______,      _______,  _______,     _______,      _______
      ),

    [_ADJUST] = LAYOUT(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  KC_OPER,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
                                    _______, _______, _______, _______,      _______,  _______, _______, _______
      ),
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    mr_keylog_set(keycode, record);
    if (keycode == KC_OPER) {
        transaction_rpc_send(TOGGLE_POMODORO, 0, NULL);
    }
  }
  return true;
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(TOGGLE_POMODORO, mr_pomodoro_toggle);
}

void housekeeping_task_user(void) {
    if (!is_keyboard_master()) {
        mr_pomodoro_timer_set(timer_read32());
    }
}

/*
qmk-keyboard-format:json:begin
{
    "name": "lily58",
    "numkeys": 58,
    "svg": "lily58.svg",
    "rows": [
                [-3, 0  , 1  , 2  , 3  , 4  , 5  , -1 ,  -2,  -1 , 6  , 7  , 8  , 9  , 10 , 11],
                [-3, 12 , 13 , 14 , 15 , 16 , 17 , -1 ,  -2,  -1 , 18 , 19 , 20 , 21 , 22 , 23],
                [-3, 24 , 25 , 26 , 27 , 28 , 29 , -1 ,  -2,  -1 , 30 , 31 , 32 , 33 , 34 , 35],
                [-3, 36 , 37 , 38 , 39 , 40 , 41 , 42 ,  -2,  43 , 44 , 45 , 46 , 47 , 48 , 49],
                [-3, -1 ,-1 ,  -1 , 50 , 51 , 52 , 53 ,  -2,  54 , 55 , 56 , 57 , -1 , -1 ,-1 ]
            ],
    "spacing": [
        0,
        8,
        2,
        4
    ],
    "vizcellwidth": 5,
    "vizemits": [
        { "line": "[_COLEMAK] = LAYOUT(", "layer": "_COLEMAK" },
        { "line": "[_SIGNS] = LAYOUT(", "layer": "_SIGNS" },
        { "line": "[_NUMBERS] = LAYOUT(", "layer": "_NUMBERS" }
    ],
    "vizline": "//#",
    "vizboard": [
        "    //# .-----------------------------------------------.                                             .-----------------------------------------------.",
        "    //# | _000_ | _001_ | _002_ | _003_ | _004_ | _005_ |                                             | _006_ | _007_ | _008_ | _009_ | _010_ | _011_ |",
        "    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|",
        "    //# | _012_ | _013_ | _014_ | _015_ | _016_ | _017_ |                                             | _018_ | _019_ | _020_ | _021_ | _022_ | _023_ |",
        "    //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|",
        "    //# | _024_ | _025_ | _026_ | _027_ | _028_ | _029_ |-------.                             .-------| _030_ | _031_ | _032_ | _033_ | _034_ | _035_ |",
        "    //# |-------+-------+-------+-------+-------+-------| _042_ |                             | _043_ |-------+-------+-------+-------+-------+-------|",
        "    //# | _036_ | _037_ | _038_ | _039_ | _040_ | _041_ |-------|                             |-------| _044_ | _045_ | _046_ | _047_ | _048_ | _049_ |",
        "    //# .-------+-------+-------+-------+-------+-------/       /                             \\       \\-------+-------+-------+-------+-------+-------.",
        "    //#                      | _050_ | _051_ | _052_ | / _053_ /                               \\ _054_ \\  | _055_ | _056_ | _057_ |                  ",
        "    //#                      |       |       |       |/       /                                 \\       \\ |       |       |       |                  ",
        "    //#                      .-------+-------+-------+-------.                                    .------++-------+-------+-------.                    "

    ],
    "vizsymbols": {
        "_______": "     ",
        "KC_NO": "  ⍉  ",
        "KC_TRANS": "     ",
        "KC_TRANSPARENT": "     ",
        "KC_0": "  0  " ,
        "KC_1": "  1  " ,
        "KC_2": "  2  " ,
        "KC_3": "  3  " ,
        "KC_4": "  4  " ,
        "KC_5": "  5  " ,
        "KC_6": "  6  " ,
        "KC_7": "  7  " ,
        "KC_8": "  8  " ,
        "KC_9": "  9  " ,
        "KC_A": "  A  " ,
        "KC_B": "  B  " ,
        "KC_C": "  C  " ,
        "KC_D": "  D  " ,
        "KC_E": "  E  " ,
        "KC_F": "  F  " ,
        "KC_G": "  G  " ,
        "KC_H": "  H  " ,
        "KC_I": "  I  " ,
        "KC_J": "  J  " ,
        "KC_K": "  K  " ,
        "KC_L": "  L  " ,
        "KC_M": "  M  " ,
        "KC_N": "  N  " ,
        "KC_O": "  O  " ,
        "KC_P": "  P  " ,
        "KC_Q": "  Q  " ,
        "KC_R": "  R  " ,
        "KC_S": "  S  " ,
        "KC_T": "  T  " ,
        "KC_U": "  U  " ,
        "KC_V": "  V  " ,
        "KC_W": "  W  " ,
        "KC_X": "  X  " ,
        "KC_Y": "  Y  " ,
        "KC_Z": "  Z  " ,
        "KC_COMMA": "  ,  ",
        "KC_COMM": "  ,  ",
        "KC_DOT": "  .  ",
        "KC_SCOLON": "  ;  ",
        "KC_SCLN": "  :  ",
        "KC_SLASH": "  \/  ",
        "KC_SLSH": "  \/  ",
        "KC_BSLS": "  \\  ",
        "KC_EXLM": "  !  ",
        "KC_PIPE": "  |  ",
        "KC_QUOT": "  '  ",
        "KC_HASH": "  #  ",
        "KC_AMPR": "  &  ",
        "KC_PERC": "  %  ",
        "KC_AT": "  @  ",
        "KC_DLR": "  $  ",
        "KC_CIRC": "  ^  ",
        "KC_EQL": "  =  ",
        "KC_EQUAL": "  =  ",
        "KC_ASTR": "  *  ",
        "KC_KP_ASTERISK": "  *  ",
        "KC_LABK": "  <  ",
        "KC_RABK": "  >  ",
        "KC_BSLASH": "  \\  ",
        "KC_MINS": "  -  ",
        "KC_MINUS": "  -  ",
        "KC_UNDS": "  _  ",
        "KC_PLUS": "  +  ",
        "KC_LCBR": "  {  ",
        "KC_RCBR": "  }  ",
        "KC_LPRN": "  (  ",
        "KC_RPRN": "  )  ",
        "KC_GRV": "  `  ",
        "KC_GRAVE": "  `  ",
        "KC_LBRC": "  [  ",
        "KC_LBRACKET": "  [  ",
        "KC_RBRC": "  ]  ",
        "KC_RBRACKET": "  ]  ",
        "KC_TILD": "  ~  ",
        "KC_ESC": "  ⎋  " ,
        "KC_ESCAPE": "  ⎋  " ,
        "RESET_LAYER_AND_ESCAPE": "MCR ⎋" ,
        "KC_CUT": " CUT " ,
        "KC_UNDO": " UNDO" ,
        "KC_REDO": " REDO" ,
        "KC_VOLU": " VOLU" ,
        "KC_VOLD": " VOLD" ,
        "KC_MUTE":   " MUTE" ,
        "KC_TAB": " TAB " ,
        "KC_MENU": "  𝌆  " ,
        "KC_LEFT": "  ←  " ,
        "KC_UP": "  ↑  " ,
        "KC_RIGHT": "  →  " ,
        "KC_DOWN": "  ↓  " ,
        "KC_CAPSLOCK": "  ⇪  " ,
        "KC_NUMLK": "  ⇭  " ,
        "KC_SCRLK": "  ⇳  " ,
        "KC_PRSCR": "  ⎙  " ,
        "KC_PAUSE": "  ⎉  " ,
        "KC_BREAK": "  ⎊  " ,
        "KC_ENTER": "  ⏎  " ,
        "KC_BSPACE": "  ⌫  " ,
        "KC_DELETE": "  ⌦  " ,
        "KC_INSERT": "  ⎀  " ,
        "KC_HOME": "  ⇤  " ,
        "KC_END": "  ⇥  " ,
        "KC_PGUP": "  ⇞  " ,
        "KC_PGDOWN": "  ⇟  " ,
        "KC_LSFT": "  ⇧  " ,
        "KC_RSFT": "  ⇧  " ,
        "KC_LCTL": "  ^  " ,
        "KC_RCTL": "  ^  " ,
        "KC_LALT": "  ⎇  " ,
        "KC_RALT": "  ⎇  " ,
        "KC_HYPER": "  ✧  " ,
        "KC_LGUI": "  ⌘  " ,
        "KC_RGUI": "  ⌘  ",
        "OPT_T(KC_S)": "S(⎇) ",
        "OPT_T(KC_E)": "E(⎇) ",
        "CMD_T(KC_T)": "T(⌘) ",
        "CMD_T(KC_N)": "N(⌘) ",
        "OSM(KC_LSHIFT)": "SHIFT"
    }
}
qmk-keyboard-format:json:end
*/
