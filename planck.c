/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 
 /*
 Keyboard shortcuts
 Ctrl + 5 = apply strikethrough formatting
 Ctrl + Space: Select an entire column in a worksheet.
 Shift + Space: Select an entire row in a worksheet.
 */
 
//#define AUDIO_CLICKY //turn on clicky which is usually off by default to save memory
#include "planck.h"
#include "action_layer.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NUMPAD,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};


enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  SOUND1,
  SOUND2,
  SOUND3,
  SOUND4
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_TB1 LCTL(KC_1)
#define KC_TB2 LCTL(KC_2)
#define KC_TB3 LCTL(KC_3)
#define KC_TB4 LCTL(KC_4)
#define KC_TB5 LCTL(KC_5)
#define KC_TB6 LCTL(KC_6)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define KC_PVTB LCTL(KC_PGUP) //previous tab in chrome
#define KC_NXTB LCTL(KC_PGDN) //next tab in chrome

#define KC_TSKMGR LCTL(LSFT(KC_ESC)) //open task manager
#define KC_ALTF4 LALT(KC_F4) //alt f4


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |NUMPAD| GUI  | ALT  |Lower |    Space    |Raise | Left | Down |  Up  |Right 
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, TG(_NUMPAD), KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

),//KC_LALT somehow becomes KC_LGUI after flashing. Hence keyboard layout is correct 



/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * | Tab1 | Tab2 |Tab3  |      |   (  |   )  |   *  |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab4 | Tab5 | Tab6 |      |   {  |   }  |   /  |   4  |   5  |   6  |   +  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |PvTab |NxtTab|      |      |   [  |   ]  |   ^  |   1  |   2  |   3  |   =  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |   0  |   .  |Left  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    KC_TB1,  KC_TB2,    KC_TB3,    KC_TRNS,    KC_LPRN,    KC_RPRN,    KC_ASTR,    KC_7,    KC_8,    KC_9,     KC_MINS, KC_BSPC,
    KC_TB4,  KC_TB5,     KC_TB6,    KC_TRNS,    KC_LCBR,    KC_RCBR,    KC_SLSH,    KC_4,    KC_5,    KC_6,    KC_PLUS,    KC_DEL,
    KC_PVTB, KC_NXTB,    KC_TRNS,    KC_END,    KC_LBRC,    KC_RBRC,    KC_CIRC,    KC_1,    KC_2,    KC_3,   KC_EQL,     KC_ENT ,
    KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_SPC,     KC_SPC,   KC_TRNS,   KC_0,   KC_DOT,  KC_LEFT,   KC_RGHT
),


/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak	
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  | F10  |  F11 |  Up  |   -  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|

 * | Caps |Alt-F4|  F5  |  F6  | F12  | Left | Down |   _  |  =   |   [  |   ]  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F7  |  F8  |  F9  |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F10,   KC_F11,   KC_UP,   KC_MINS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    KC_CAPSLOCK, KC_ALTF4,   KC_F5,   KC_F6,   KC_F12, KC_LEFT ,  KC_DOWN,  KC_UNDS,  KC_EQL,    KC_LBRC, KC_RBRC,  KC_TRNS,
    KC_TRNS, KC_F7, KC_F8, KC_F9, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  M1  |  M2  |  M3  |  M7  |  M8  | Pg Up| PvTab|  Up  |NxtTab|   )  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  M4  |  M5  |  M6  |  M9  |  M11 | Pg Dn| Left | Down | Right| Home |Pg Up |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | LGUI | LALT |      |             |      |      |      | End  |Pg Dn |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  M(1),   M(2),   M(3),   M(7),   M(8),   KC_PGUP,   KC_PVTB, KC_UP,  KC_NXTB, KC_RPRN, KC_BSLS,
    KC_TRNS, M(4),   M(5),   M(6),   M(9), M(11), KC_PGDN,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_HOME, KC_PGUP,
    KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______, _______, KC_END, KC_PGDN
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |TSKMGR| Reset| DEBUG|Mus on|Musoff|MuMod |MuTog |TermOn|TermOf|      | CALC |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Voice-|Voice+|      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|  M10 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Sound1|Sound2|Sound3|Sound4|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_TSKMGR, RESET,   DEBUG,   MU_ON,   MU_OFF, MU_MOD   ,  MU_TOG, TERM_ON,TERM_OFF, KC_NO, KC_CALC, KC_DEL ,
    MUV_DE, MUV_IN, KC_NO,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP,  QWERTY, COLEMAK,  DVORAK,  PLOVER, M(10),
    _______   , _______   ,  _______  , _______   , _______   , _______   ,  _______  , _______, SOUND1,  SOUND2, SOUND3, SOUND4,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t keycode, uint8_t opt) {
  // These would trigger when you hit a key mapped as M(0)
  if (record->event.pressed) {
    switch(keycode) {
      case 1: // MACRO1
        SEND_STRING("MACRO1 TEXT");
        return false;
      case 2: // MACRO2
        SEND_STRING("MACRO2 TEXT");
        return false;
      case 3: // MACRO3
        SEND_STRING("MACRO3");
		return false;
      case 4: // MACRO4
        SEND_STRING("MACRO4");
        return false;
      case 5: // MACRO5
        SEND_STRING("MACRO5");
        return false;
      case 6: // MACRO6
        SEND_STRING("MACRO6");
        return false;
      case 7: // Word Select
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LCTRL));
        return false;
      case 8: // Line select
        SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_UP(X_LSHIFT));
        return false;
      case 9: // Prnt Screen of current App 
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_PSCREEN) SS_UP(X_LALT)) ;
        return false;
      case 10: // control alt delete
        SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_DELETE))));
        return false;
      case 11: // Left arrow
        SEND_STRING("<--");
        return false;
      case 12: // Right arrow
        SEND_STRING("-->");
        return false;
    }
  }
  return MACRO_NONE;
};




#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float tone_startup[][2]    = SONG(STARTUP_SOUND);
  float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
  float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
  float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          back light_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
    case PLOVER:
        #ifdef AUDIO_ENABLE
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case SOUND1:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_startup);
        #endif
      }
      return false;
      break;
    case SOUND2:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
      }
      return false;
      break;
    case SOUND3:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
      }
      return false;
      break;
    case SOUND4:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
      }
      return false;
      break;

  }
  return true;
}



bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
