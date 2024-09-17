#include QMK_KEYBOARD_H
#include <stdio.h>

#define KC_COPY LCTL(KC_C) //copy
#define KC_CUT LCTL(KC_X) //cut
#define KC_PSTE LCTL(KC_V)  //paste
#define KC_UNDO LCTL(KC_Z) //undo
#define KC_REDO LCTL(S(KC_Z)) //redo
#define KC_SCRE LSG(KC_S) //screenshot  WIN+SHIFT+S
#define KC_CLIPHI LGUI(KC_V) // WIN+V clipboard history

enum layer_names {
    Base,
    Num,
    Nav,
    Comm,
    Games,
    GamesNum
};

//Tap Dance Declarations
enum {
  TD_GAMES = 0,
  TD_BASE  = 1 
};
//Tap Dance Definitions
tap_dance_action_t  tap_dance_actions[] = {
  [TD_GAMES] = ACTION_TAP_DANCE_LAYER_MOVE(KC_RBRC, Games),
  [TD_BASE]  = ACTION_TAP_DANCE_LAYER_MOVE(KC_RBRC, Base),
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Base] = LAYOUT_ortho_12x5(
                                               KC_ESC,         KC_9,            KC_0,      /**/   KC_MINS, KC_8,           KC_BSLS,               
        XXXXXXX,   KC_Q,         KC_W,         KC_E,           KC_R,            KC_T,      /**/   KC_Y,    KC_U,           KC_I,         KC_O,         KC_LBRC,         TD(TD_GAMES),
        XXXXXXX,   LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),   LSFT_T(KC_F),    KC_G,      /**/   KC_H,    LSFT_T(KC_J),   LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
        XXXXXXX,   KC_Z,         KC_X,         KC_C,           KC_V,            KC_B,      /**/   KC_N,    KC_M,           KC_P,         KC_COMM,      KC_DOT,          KC_SLSH,
                                               LT(Num,KC_GRV), LT(Comm,KC_TAB), KC_SPC,    /**/   KC_BSPC, LT(Nav,KC_DEL), KC_ENT),


    [Nav] = LAYOUT_ortho_12x5(
                                    KC_TRNS, XXXXXXX, XXXXXXX,   /**/    XXXXXXX,   XXXXXXX, XXXXXXX ,
        KC_TRNS, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   /**/    XXXXXXX,   XXXXXXX, KC_UP   , XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, XXXXXXX,   /**/    XXXXXXX,   KC_LEFT, KC_DOWN , KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   /**/    XXXXXXX,   KC_HOME, KC_PGDN , KC_PGUP,  KC_END, XXXXXXX,
                                    XXXXXXX, KC_TRNS, KC_TRNS,   /**/    KC_TRNS,   KC_TRNS, KC_TRNS),

    [Num] = LAYOUT_ortho_12x5(
                                   KC_TRNS, XXXXXXX, XXXXXXX,     /**/     KC_COMM, KC_DOT , KC_0,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     /**/     KC_EQL , KC_7   , KC_8, KC_9, XXXXXXX, XXXXXXX,
       XXXXXXX,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX,     /**/     KC_PPLS, KC_4   , KC_5, KC_6, KC_PAST, XXXXXXX,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     /**/     KC_PMNS, KC_1   , KC_2, KC_3, KC_PSLS, XXXXXXX,
                                   XXXXXXX, KC_TRNS, KC_TRNS,     /**/     KC_TRNS, KC_TRNS, KC_TRNS)  ,

    [Comm]=LAYOUT_ortho_12x5(
                                  KC_TRNS, XXXXXXX, XXXXXXX,      /**/    XXXXXXX,  KC_COMM, KC_DOT,
       QK_BOOT, XXXXXXX,  KC_CUT, KC_COPY, KC_PSTE, XXXXXXX,      /**/    XXXXXXX,  KC_F9,   KC_F10, KC_F11, KC_F12,  KC_CAPS,
       XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCRE,      /**/    XXXXXXX,  KC_F5,   KC_F6 ,  KC_F7,  KC_F8,  XXXXXXX,
       XXXXXXX, XXXXXXX, KC_UNDO, XXXXXXX, KC_REDO, KC_CLIPHI,    /**/    XXXXXXX,  KC_F1,   KC_F2 ,  KC_F3,  KC_F4,  XXXXXXX,
                                  XXXXXXX, KC_TRNS, KC_TRNS,      /**/    KC_TRNS,  KC_TRNS, KC_TRNS),
    [Games] = LAYOUT_ortho_12x5(
                             KC_ESC,       XXXXXXX, XXXXXXX,     /**/     XXXXXXX, XXXXXXX,        XXXXXXX,               
        KC_LALT, KC_Q, KC_W, KC_E,         KC_R,    KC_T,        /**/     KC_Y   ,    KC_U,        KC_I   ,    KC_O   , KC_LBRC, TD(TD_BASE),
        KC_LCTL, KC_A, KC_S, KC_D,         KC_F,    KC_G,        /**/     KC_H   ,    KC_J,        KC_K   ,    KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C,         KC_V,    KC_B,        /**/     KC_N   ,    KC_M,        KC_P   ,    KC_COMM, KC_DOT , KC_SLSH,
                             MO(GamesNum), KC_TAB,  KC_SPACE,    /**/     KC_BSPC, LT(Nav,KC_DEL), KC_ENT),

    [GamesNum] = LAYOUT_ortho_12x5(
                                       XXXXXXX, XXXXXXX,  XXXXXXX,    /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   
		XXXXXXX,  KC_1,      KC_2,     KC_3,    KC_4,     KC_5,       /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,  
        XXXXXXX,  KC_6,      KC_7,     KC_8,    KC_9,     KC_0,       /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
		XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,    /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
		                               XXXXXXX,  XXXXXXX, XXXXXXX,    /**/  XXXXXXX,   XXXXXXX,   XXXXXXX),};

bool caps = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS:
            if (record->event.pressed) 
            {
                caps = !caps;
            }
           break;
        default:
            return true; // Process all other keycodes normally
  }
  return true;
}


#ifdef OLED_ENABLE
    bool oled_task_user(void) 
    {

        oled_set_cursor(2, 1);

        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case Base:
                oled_write_P(PSTR("Base\n"), false);
                break;
            case Nav:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case Num:
                oled_write_P(PSTR("Num\n"), false);
                break;
            case Comm:
                oled_write_P(PSTR("Comm\n"), false);
                break; 
            case Games:
                oled_write_P(PSTR("Game\n"), false);
                break;
            case GamesNum:
                oled_write_P(PSTR("GameNum\n"), false);
                break;
        }

        oled_set_cursor(8, 2);
        if (process_detected_host_os_user(detected_host_os())) {
            switch (detected_host_os()) {
                case OS_MACOS:
                    oled_write_P(PSTR("MAC\n"), false);
                    break;
                case OS_WINDOWS:
                    oled_write_P(PSTR("WIN\n"), false);
                    break;
                case OS_UNSURE:
                    oled_write_P(PSTR("UNS\n"), false);
                    break;
                default:
                    oled_set_cursor(4, 2);
                    oled_write_P(PSTR("NOT SUP\n"), false);
                    break;
            }
            
             oled_set_cursor(8, 3);
            oled_write_P(PSTR(caps?"CAPS\n":""),false);

    }
        return false;
    }
#endif













