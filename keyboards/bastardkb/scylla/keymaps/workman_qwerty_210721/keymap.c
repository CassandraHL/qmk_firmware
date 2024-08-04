#include QMK_KEYBOARD_H

/* Changed handedness to left, swapped copy/paste order, corrected RGB brightness keys
 * Added macros for screenshot and euro
 * Fixed TT issue
 * Added file size reduction measures
 * Renamed layers, added base for lighting
 * Simplified macro implementation
 * Moved some _NUMPAD and _FARRW keys
 * Added lighting pattern for base layer
 * Customised lighting layers
 * Made reset layer accessible
 * Added layers for emojis and shortcuts
 * Updated RESET to QK_BOOT
 * Fixed base layer lighting
 * Added KC_NUBS for `¬
 */



// Macros

#define SSHOT LSFT(LCTL(LGUI(KC_4)))
#define EURO LALT(LSFT(KC_2))
#define MACLOCK LGUI(LCTL(KC_Q)) // Lock my MacBook


enum custom_keycodes {
 FPALM = SAFE_RANGE,
 HEARTS,
 KISS,
 MOON,
 POTATO,
 SCREAM,
 SHRUG,
 SLIGHT,
 SWEAT,
 THINK,
 TONGUE,
 SLACK,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FPALM:
            if (record->event.pressed) {
            // when keycode FPALM is pressed
            SEND_STRING(":woman_face");
            }
        break;

        case HEARTS:
            if (record->event.pressed) {
            // when keycode HEARTS is pressed
            SEND_STRING(":hearts");
            }
        break;

        case KISS:
            if (record->event.pressed) {
            SEND_STRING(":kissing_heart");
            }
        break;

        case MOON:
            if (record->event.pressed) {
            SEND_STRING(":new_moon_with_face");
            }
        break;

        case POTATO:
            if (record->event.pressed) {
            SEND_STRING(":potato");
            }
        break;

        case SCREAM:
            if (record->event.pressed) {
            SEND_STRING(":scream");
            }
        break;

        case SHRUG:
            if (record->event.pressed) {
            SEND_STRING(":woman_shrugging");
            }
        break;

        case SLIGHT:
            if (record->event.pressed) {
            SEND_STRING(":slight");
            }
        break;

        case SWEAT:
            if (record->event.pressed) {

            SEND_STRING(":sweat");
            }
        break;

        case THINK:
            if (record->event.pressed) {
            SEND_STRING(":think");
            }
        break;

        case TONGUE:
            if (record->event.pressed) {
            SEND_STRING(":tongue");
            }
        break;

        case SLACK:
            if (record->event.pressed) {
            // when keycode SLACK is pressed
            SEND_STRING(SS_LGUI(" ") "slack" SS_TAP(X_ENT));
            }
        break;
        }
    return true;
 };



// Keymap layers

enum layer_names {
    _BASE,
    _QWERTY,
    _NUMPAD,
    _FARRW,
    _EMOJI,
    _SCUTS,
    _RESET
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_split_4x6_5(

	    KC_ESC,     KC_1,    KC_2,   G(KC_C),   G(KC_V),    G(KC_X),                MACLOCK,    KC_MRWD,    KC_MPLY,    KC_MFFD,    KC_VOLD,    KC_VOLU,
	    KC_TAB,     KC_Q,    KC_D,   KC_R,      KC_W,       KC_B,                   KC_J,       KC_F,       KC_U,       KC_P,       KC_SCLN,    KC_NUBS,
	    KC_CAPS,    KC_A,    KC_S,   KC_H,      KC_T,       KC_G,                   KC_Y,       KC_N,       KC_E,       KC_O,       KC_I,       KC_QUOT,
	    KC_LSFT,    KC_Z,    KC_X,   KC_M,      KC_C,       KC_V,                   KC_K,       KC_L,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
	                                TT(_NUMPAD),   KC_BSPC,    TT(_EMOJI),       TT(_SCUTS),    KC_SPC,     TT(_FARRW),
	                                               KC_LGUI,    KC_DEL,           TT(_QWERTY),   KC_ENT),


	[_QWERTY] = LAYOUT_split_4x6_5(

	    KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
	    KC_TRNS, KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,                  KC_Y,        KC_U,       KC_I,       KC_O,       KC_P,       KC_SCLN,
	    KC_TRNS, KC_A,      KC_S,       KC_D,       KC_F,       KC_G,                  KC_H,        KC_J,       KC_K,       KC_L,       KC_L,       KC_TRNS,
	    KC_TRNS, KC_Z,      KC_X,       KC_C,       KC_V,       KC_B,                  KC_N,        KC_M,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
	                                        KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,     KC_TRNS,    KC_TRNS,
	                                                    KC_TRNS,    KC_TRNS,        KC_TRNS,     KC_TRNS),


	[_NUMPAD] = LAYOUT_split_4x6_5(

	    RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,               KC_HOME,    KC_END, RGB_VAD, RGB_VAI, KC_BRID, KC_BRIU,
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,               KC_GRV,     KC_7,   KC_8,   KC_9,   KC_MINS, KC_PSLS,
	    KC_TRNS, KC_TRNS, SSHOT,   KC_LPRN, KC_RPRN, KC_TRNS,               EURO,       KC_4,   KC_5,   KC_6,   KC_PLUS, KC_PAST,
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,               KC_PDOT,    KC_1,   KC_2,   KC_3,   KC_EQL,  KC_TRNS,
	                                    KC_TRNS, KC_TRNS, TT(_RESET),    TT(_RESET), KC_TRNS, KC_0,
	                                             KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS),


	[_FARRW] = LAYOUT_split_4x6_5(

	    KC_F12,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
	    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
	    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_UP,      KC_TRNS,    KC_TRNS,    KC_NONUS_HASH,
	    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS,    KC_TRNS,
	                                            KC_TRNS,    KC_TRNS,    TT(_RESET),      TT(_RESET),    KC_TRNS,    KC_TRNS,
	                                                        KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS),


	[_EMOJI] = LAYOUT_split_4x6_5(

	    KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,  KC_NO,                  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO,     SWEAT,  KC_NO,                  KC_NO,  FPALM,  KC_NO,  POTATO, KC_NO, KC_NO,
	    KC_NO, KC_NO, SHRUG, HEARTS,    TONGUE, KC_NO,                  KC_NO,  KC_NO,  KC_NO,  SCREAM, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, MOON,      KC_NO,  KC_NO,                  KISS,   SLIGHT, KC_NO,  KC_NO,  THINK, KC_NO,
	                               KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
	                               KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS),

    [_SCUTS] = LAYOUT_split_4x6_5(

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, SLACK, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS),



	[_RESET] = LAYOUT_split_4x6_5(

	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,             QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	                        KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
	                                 KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS)

};



// Lighting layers

#define MY_RED 0, 255, 255
#define MY_ORANGE 10, 255, 255
#define MY_YELLOW 20, 255, 255
#define MY_GREEN 90, 255, 255
#define MY_BLUE 128, 255, 255
#define MY_PURPLE 180, 255, 255
#define MY_PINK 205, 255, 255
#define MY_WHITE 30, 165, 255

#define rgblight_setmy_white() rgblight_sethsv(MY_WHITE)



const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,58,MY_WHITE}, // Set the base color
		{2,2,MY_BLUE}, // Starting at LED 2, light 2 LEDs
		{4,2,MY_BLUE}, // Starting at LED 4, light 2 LEDs
		{13,2,MY_GREEN}, // Starting at LED 13, light 2 LEDs
		{16,2,MY_GREEN},
		{25,4,MY_ORANGE},
		{47,1,MY_YELLOW},
		{42,2,MY_YELLOW},
		{39,1,MY_YELLOW},
		{33,1,MY_PINK},
		{30,3,MY_PINK},
		{53,4,MY_RED}
	);
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,58,MY_PURPLE}
    );
const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,58,MY_ORANGE}
	);
const rgblight_segment_t PROGMEM farrw_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,58,MY_GREEN}
	);
const rgblight_segment_t PROGMEM emoji_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,58,MY_YELLOW}
	);
const rgblight_segment_t PROGMEM scuts_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,58,MY_BLUE}
	);
const rgblight_segment_t PROGMEM reset_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0,58,MY_RED}
	);


enum rgb_layer_index {
    L_BASE,
    L_QWERTY,
    L_NUMPAD,
    L_FARRW,
    L_EMOJI,
    L_SCUTS,
    L_RESET,
};

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        [L_BASE] = base_layer,
        [L_QWERTY] = qwerty_layer, // overrides previous layer
        [L_NUMPAD] = numpad_layer, // overrides previous two layers
        [L_FARRW] = farrw_layer,
        [L_EMOJI] = emoji_layer,
        [L_SCUTS] = scuts_layer,
        [L_RESET] = reset_layer
);


//Set the appropriate layer color
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(L_BASE, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(L_QWERTY, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(L_NUMPAD, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(L_FARRW, layer_state_cmp(state, _FARRW));
    rgblight_set_layer_state(L_EMOJI, layer_state_cmp(state, _EMOJI));
    rgblight_set_layer_state(L_SCUTS, layer_state_cmp(state, _SCUTS));
    rgblight_set_layer_state(L_RESET, layer_state_cmp(state, _RESET));
    return state;
}

void keyboard_post_init_user(void) {
	//Enable the LED layers
	rgblight_layers = my_rgb_layers;
	layer_state_set_user(layer_state);
}


//EEPROM Reset Function
void eeconfig_init_user(void) {
  rgblight_enable(); // Enable RGB by default
  rgblight_setmy_white();  // Set it to white by default
}
