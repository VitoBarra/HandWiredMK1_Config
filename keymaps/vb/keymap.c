#include QMK_KEYBOARD_H
#include <stdio.h>


#define KC_COPY LCTL(KC_C) 
#define KC_CUT LCTL(KC_X)
#define KC_PSTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_AGIN LCTL(KC_Y)
#define KC_SCRE XXXXXXX
enum layer_names {
    Base,
    Num,
    Nav,
    Sym,
    Mouse,
    Media,
    Fun
};

enum my_keycodes {
  Mod1,
  Mod2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [Base] = LAYOUT_ortho_12x5(
                      KC_ESC, KC_GRV, TG(Num),                KC_TRNS,  KC_9,   KC_0,
        KC_TAB ,  KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y,    KC_U,   KC_I, KC_O,    KC_LBRC,  KC_RBRC,
        KC_LALT,  KC_A, KC_S, KC_D, KC_F, KC_G,               KC_H,    KC_J,   KC_K, KC_L,    KC_SCLN,  KC_QUOT,
        KC_LCTL,  KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N,    KC_M,   KC_P, KC_COMM, KC_DOT,   KC_SLSH,
                    KC_RWIN, KC_LSFT, KC_SPACE,               KC_BSPC, MO(Nav), KC_ENT),


    [Nav] = LAYOUT_ortho_12x5(
                                   KC_TRNS, XXXXXXX, KC_TRNS,          KC_INSERT,   XXXXXXX, XXXXXXX ,
        KC_SCRE, XXXXXXX, KC_UNDO, KC_TAB , KC_PSTE, XXXXXXX,          XXXXXXX  ,   XXXXXXX, KC_UP   , XXXXXXX, XXXXXXX, XXXXXXX,
        KC_CAPS, XXXXXXX, KC_AGIN, KC_COPY, KC_ENT , XXXXXXX,          XXXXXXX  ,   KC_LEFT, KC_DOWN , KC_RGHT, XXXXXXX, XXXXXXX,
        KC_LCTL, XXXXXXX, XXXXXXX, KC_CUT , XXXXXXX, XXXXXXX,          XXXXXXX  ,   KC_HOME, KC_PGDN , KC_PGUP,  KC_END, XXXXXXX,
                                   KC_RWIN, KC_LSFT, KC_LALT,          XXXXXXX  ,   KC_TRNS, XXXXXXX),

    [Num] = LAYOUT_ortho_12x5(
                                  QK_BOOT, XXXXXXX, KC_TRNS,            XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            KC_EQL ,  KC_7, KC_8, KC_9, XXXXXXX,XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            KC_PPLS, KC_4, KC_5, KC_6, KC_PAST,XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            KC_PMNS, KC_1, KC_2, KC_3, KC_PSLS,XXXXXXX,
                                  XXXXXXX, XXXXXXX, XXXXXXX,            KC_COMM, KC_DOT, KC_0)





    // [Mouse] = LAYOUT_ortho_12x5(
    //                  KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,    KC_TRNS,    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS,       KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3),



    // [Sym] = LAYOUT_ortho_10x5(
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_AT,   KC_CIRC, KC_PMNS, KC_PPLS, KC_PAST,    KC_PSLS, KC_BSLS, KC_HASH, KC_PERC, KC_TILD,
    //     KC_COLN, KC_UNDS, KC_LABK, KC_RABK, KC_PIPE,    KC_AMPR, KC_EXLM, KC_EQL, KC_DLR,  KC_SCLN,
    //     KC_GRV,  KC_QUOT, KC_LCBR, KC_LBRC, KC_LPRN,    KC_RPRN, KC_RBRC, KC_RCBR, KC_DQUO, KC_QUES,
    //                       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS),

    // [Media] = LAYOUT_ortho_10x5(
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_TRNS,
    //     KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS,    KC_TRNS, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP , KC_MUTE, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_TRNS, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS),

    // [Fun] = LAYOUT_ortho_10x5(
    //     QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_F10, KC_F11, KC_F12, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_TRNS,
    //     KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS,    KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS)

    // [_TRANS] = LAYOUT_ortho_10x5(
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS)

};

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













