#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

//Layer Declarations
	#define BASE 0 // Default Layer
	#define SYMB 1 // NumPad & Symbols
	#define FUNN 2 // F-Key Layer
	#define MOUS 3 // Mouse Control
	#define WHEL 4 // Scroll Wheel Control
	#define ARWC 5 // Arrow Keys
	#define ARWX 6 // Enhanced Arrow Keys
	//...etc
	
// Macro Declarations
	enum custom_keycodes {
	  PLACEHOLDER = SAFE_RANGE, // can always be here
	  EPRM,
	  VRSN,
	  RGB_SLD
	  //...etc
};

//Layer Definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer v1.1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Grav Esc|   !  |   @  |   $  |   %  | Tab- | Close|           | Next | Tab+ |      |      |  -_  |  =+  | Backsp |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Hyper|           | Ctrl |   Y  |   U  |   I  |   O  |   P  |  \|    |		/Key/ = One shot
 * |--------+------+------+------+------+------|      |           | +Alt |------+------+------+------+------+--------|
 * |  Caps  |   A  |S/Shft| D/Alt| F/Win|   G  |------|           |------|   H  |J/Win | K/Alt|L/Shft|  ;:	|  '"    |
 * |--------+------+------+------+------+------| Hyper|           | Ctrl |------+------+------+------+------+--------|
 * |LShft/( |Z/Ctrl|   X  |   C  |   V  |   B  |      |           | +Alt |   N  |   M  |  ,<  |  .>  |//Ctrl|RShft/) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |VolDwn| VolUp|Pl/Alt| Prev |Nx/Num|                                       |  Num |      |   [  |   ]  |/Func/|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |Ctl/Ap| LGui |       | RGui |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |Arrow/|ArrwX/|      |       | Shift| Wheel/ |Mouse/|
 *                                 | Space|Backsp|------|       |------|  Del   |Enter |
 *                                 |      |ace   | Tab  |       | Alt  |        |      |
 *                                 `--------------------'       `----------------------' 
 *
 */
 
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GESC,        KC_EXLM,      KC_AT,  KC_DLR, KC_PERC,LCTL(LSFT(KC_TAB)),LALT(KC_F4),
        KC_TAB,			KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   ALL_T(KC_NO),
        KC_CAPS,        KC_A,  		  SFT_T(KC_S),   ALT_T(KC_D),   GUI_T(KC_F),   KC_G,
        KC_LSPO,		CTL_T(KC_Z),  KC_X,	  KC_C,	  KC_V,	  KC_B,	ALL_T(KC_NO),
        KC_VOLD,		KC_VOLU,      ALT_T(KC_MPLY),KC_MPRV,LT(SYMB,KC_MNXT),
											    CTL_T(KC_APP),KC_LGUI,
                                                              KC_NO,
                                               LT(ARWC,KC_SPC),LT(ARWX,KC_BSPC),KC_TAB,
        // right hand
		 KC_F6,LCTL(KC_TAB),		KC_NO,  KC_NO,  KC_MINS,KC_EQL, KC_BSPC,
		 RCTL(RALT(KC_NO)),		  KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
					KC_H,  		  KC_J,   ALT_T(KC_K),	  SFT_T(KC_L),	  GUI_T(KC_SCLN),KC_QUOT,
		 RCTL(RALT(KC_NO)),	    KC_N,		  KC_M,	  KC_COMM,KC_DOT, CTL_T(KC_SLSH), KC_RSPC,
					TT(SYMB),	  KC_NO,  KC_LBRC,KC_RBRC,OSL(FUNN),
		 KC_RGUI, CTL_T(KC_ESC),
		 KC_RSFT,
		 KC_LALT, LT(WHEL,KC_DEL), LT(MOUS,KC_ENT)
    ),
/* Keymap 1: Symbol + NumPad Layer v1.1
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |      |      |      |      |      |           |      |      | Calc |   ^  |   _  |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   *  |   7  |   8  |   9  |   -  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   &  |------|           |------|   /  |4/Win |5/Alt |6/Shft|   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   *  |	   |           | LEFT | RIGHT|   1  |   2  |   3  |En/Ctl|        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | FLSH  |      |      |      |Origin|                                       |Origin|   0  |   .  |  Ent | FLSH |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|Backsp|  Ent |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_AMPR,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_ASTR,KC_TRNS,
         RESET,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_CALC,KC_UNDS, KC_CIRC, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_PAST,   KC_7,   KC_8,    KC_9,    KC_PMNS, KC_TRNS,
                KC_PSLS, ALT_T(KC_4),   SFT_T(KC_5),    GUI_T(KC_6),    KC_PPLS, KC_TRNS,
       KC_LEFT, KC_RIGHT, KC_1,   KC_2,    KC_3,    CTL_T(KC_ENT),  KC_TRNS,
                         KC_TRNS,KC_0, 	  KC_DOT,  KC_ENT,  RESET,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BSPC, KC_ENT
),
/* Keymap 2: Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |  F7  |  F8  |  F9  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |  F4  |  F5  |  F6  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |  F1  |  F2  |  F3  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |  F10 |  F11 |  F12 |      |Origin|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[FUNN] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_F7,  KC_F8,   KC_F9,   KC_TRNS, KC_TRNS,
                KC_TRNS, KC_F4,  KC_F5,   KC_F6,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_F1,  KC_F2,   KC_F3,   KC_TRNS, KC_TRNS,
                         KC_F10, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
 /* Keymap 3: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | 	  | MsUp |	    |      |      |           |      |      |      |      |      |      |        | Other Ideas: BwBack|BwHome|BwRefr|BwFwd
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|		|MsAcl2| Alt  |Shift |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Btn4 |      |		 |      |      |      |           |      |      |MsAcl0|      |      | Ctrl |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |   	  |      | Btn5 |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|      |Origin|
 *                                 |      |      |WhClk |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 // MOUSE
[MOUS] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_BTN4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN5,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_BTN3,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_ACL2, ALT_T(KC_TRNS), SFT_T(KC_TRNS), KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_ACL0, KC_TRNS, KC_TRNS, CTL_T(KC_TRNS), KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
 /* Keymap 3: Mouse Wheel
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | WhUp |      |      |      |           |      |      |      |      |      |      |        | Other Ideas: BwBack|BwHome|BwRefr|BwFwd
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |WhLeft|WhDown|WhRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | WhClk|      |------|       |------|Origin|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 // WHEEL
[WHEL] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN3, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 5: TKL Cluster
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      | PrtSc| ScrLk| Pause|      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Shift| Alt  | Win  |      |------|           |------|      | Left | Down | Right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | Ctrl |      |      |      |      |      |           |      |      | Ins  | Home | PgUp |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       | Del  | End  | PgDn |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Origin|      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 // TKL Cluster. Mostly just arrow keys.
[ARWC] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, SFT_T(KC_TRNS), ALT_T(KC_TRNS), KC_LGUI, KC_TRNS,
       KC_TRNS, CTL_T(KC_TRNS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_INS , KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS,
                         KC_DEL , KC_END , KC_PGDN, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
 /* Keymap 6: TKL Cluster X
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      | PgUp |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Shift| Alt  | Win  |      |------|           |------|      | Home | PgDn | End  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | Ctrl |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |Origin|------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 // TKL Cluster Enhanced. Arrow keys should now go to beginning/end of current line.
[ARWX] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, SFT_T(KC_TRNS), ALT_T(KC_TRNS), GUI_T(KC_TRNS), KC_TRNS,
       KC_TRNS, CTL_T(KC_TRNS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_HOME, KC_PGDN, KC_END , KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FUNN)                // FN1 - Momentary Layer 1 (F-Keys)
};

//Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
