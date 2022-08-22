#include QMK_KEYBOARD_H

#define DEFAULT        0
#define ONE_SHOT_LAYER 1
#define NUM_CTRL       2
#define NAVIGATION     3
#define MISC           4
#define EXTRA          5

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS,
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

enum tap_dance_codes {
  DANCE_A,
  DANCE_B,
  DANCE_C,
  DANCE_D,
  DANCE_E,
  DANCE_F,
  DANCE_G,
  DANCE_H,
  DANCE_I,
  DANCE_J,
  DANCE_K,
  DANCE_L,
  DANCE_M,
  DANCE_N,
  DANCE_O,
  DANCE_P,
  DANCE_Q,
  DANCE_R,
  DANCE_S,
  DANCE_T,
  DANCE_U,
  DANCE_V,
  DANCE_W,
  DANCE_X,
  DANCE_Y,
  DANCE_Z,
  DANCE_COMMA,
  DANCE_DOT,
  DANCE_SLASH,
  DANCE_BSPACE,
  DANCE_SPACE,
  DANCE_DOLLAR,
  DANCE_BSLASH,
  DANCE_LCBR,
  DANCE_LBRC,
  DANCE_RCBR,
  DANCE_RBRC,
  DANCE_PIPE,
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_EQUAL,
  DANCE_MINUS,
  DANCE_PLUS,
  DANCE_UNDS,
  DANCE_ESCAPE,
  DANCE_TAB,
  DANCE_SPACE_OPEN,
  DANCE_LEFT,
  DANCE_RIGHT,
  DANCE_UP,
  DANCE_DOWN,
};

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DEFAULT] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,KC_NO   ,KC_NO ,KC_NO   ,
           KC_NO  , KC_NO          , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,
           KC_NO  , KC_Q           , KC_W          , TD(DANCE_E)   , TD(DANCE_R)   , TD(DANCE_T)   ,
           KC_NO  , TD(DANCE_A)    , TD(DANCE_S)   , TD(DANCE_D)   , TD(DANCE_F)   , TD(DANCE_G)   ,
           KC_NO  , TD(DANCE_Z)    , TD(DANCE_X)   , TD(DANCE_C)   , TD(DANCE_V)   , TD(DANCE_B)   ,
                    KC_NO          , KC_NO         , KC_NO         , KC_NO  ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           OSM(MOD_RCTL), OSM(MOD_LSFT),  OSM(MOD_MEH) ,

           KC_NO         , KC_NO          , KC_NO           , KC_NO         , KC_NO            , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO         , KC_NO          , KC_NO           , KC_NO         , KC_NO            , KC_NO  ,
           TD(DANCE_Y)   , TD(DANCE_U)    , TD(DANCE_I)     , TD(DANCE_O)   , TD(DANCE_P)      , KC_NO  ,
           TD(DANCE_H)   , TD(DANCE_J)    , TD(DANCE_K)     , TD(DANCE_L)   , TD(DANCE_BSPACE) , KC_NO  ,
           TD(DANCE_N)   , TD(DANCE_M)    , TD(DANCE_COMMA) , TD(DANCE_DOT) , TD(DANCE_SLASH)  , KC_NO  ,
                           KC_NO          , KC_NO  , KC_NO  , KC_NO         ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           OSL(ONE_SHOT_LAYER), OSM(MOD_LALT), TD(DANCE_SPACE)
    ),

[ONE_SHOT_LAYER] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO            , KC_NO     , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO            , KC_NO     ,
           KC_NO  , KC_ESCAPE      , KC_AT          , KC_HASH        , TD(DANCE_DOLLAR) , KC_PERC   ,
           KC_NO  , KC_TAB         , KC_UNDS        , KC_EXLM        , KC_MINUS         , KC_QUOTE  ,
           KC_NO  , KC_TILD        , KC_TRANSPARENT , KC_TRANSPARENT , KC_PLUS          , KC_DQUO   ,
                    KC_NO          , KC_NO          , KC_NO          , KC_NO            ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  KC_TRANSPARENT ,

           KC_NO            , KC_NO             , KC_NO          , KC_NO          , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO            , KC_NO             , KC_NO          , KC_NO          , KC_NO          , KC_NO  ,
           KC_CIRC          , KC_AMPR           , KC_ASTR        , KC_SCOLON      , KC_COLON       , KC_NO  ,
           TD(DANCE_BSLASH) , TD(DANCE_LCBR)    , TD(DANCE_RCBR) , TD(DANCE_PIPE) , KC_ENTER       , KC_NO  ,
           TD(DANCE_LBRC)   , KC_LPRN           , KC_RPRN        , TD(DANCE_RBRC) , TO(NAVIGATION) , KC_NO  ,
                              KC_NO             , KC_NO          , KC_NO          , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           TO(NUM_CTRL)    , KC_TRANSPARENT, KC_TRANSPARENT
    ),

[NUM_CTRL] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO               , KC_NO               , KC_NO               , KC_NO           , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO          , KC_NO               , KC_NO               , KC_NO               , KC_NO           ,
           KC_NO  , KC_ESCAPE      , KC_MEDIA_PLAY_PAUSE , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , TD(DANCE_UNDS)  ,
           KC_NO  , KC_TAB         , KC_AUDIO_MUTE       , KC_AUDIO_VOL_DOWN   , KC_AUDIO_VOL_UP     , TD(DANCE_PLUS)  ,
           KC_NO  , TO(MISC)       , KC_KP_ASTERISK      , KC_BRIGHTNESS_DOWN  , KC_BRIGHTNESS_UP    , KC_KP_DOT       ,
                    KC_NO          , KC_NO               , KC_NO               , KC_NO               ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  TO(DEFAULT) ,

           KC_NO            , KC_NO          , KC_NO           , KC_NO           , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO            , KC_NO          , KC_NO           , KC_NO           , KC_NO          , KC_NO  ,
           TD(DANCE_MINUS) , TD(DANCE_7)     , TD(DANCE_8)     , TD(DANCE_9)     , KC_TRANSPARENT , KC_NO  ,
           TD(DANCE_EQUAL) , TD(DANCE_4)     , TD(DANCE_5)     , TD(DANCE_6)     , KC_ENTER       , KC_NO  ,
           TD(DANCE_0)     , TD(DANCE_1)     , TD(DANCE_2)     , TD(DANCE_3)     , KC_TRANSPARENT , KC_NO  ,
                            KC_NO            , KC_NO           , KC_NO           , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_RGUI)
    ),

[NAVIGATION] = LAYOUT(
           KC_NO  , KC_NO            , KC_NO          , KC_NO       , KC_NO          , KC_NO           , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO            , KC_NO          , KC_NO       , KC_NO          , KC_NO           ,
           KC_NO  , TD(DANCE_ESCAPE) , KC_MS_WH_LEFT  , KC_MS_UP    , KC_MS_WH_RIGHT , KC_TRANSPARENT  ,
           KC_NO  , TD(DANCE_TAB)    , KC_MS_LEFT     , KC_MS_DOWN  , KC_MS_RIGHT    , KC_TRANSPARENT  ,
           KC_NO  , KC_MS_BTN1       , KC_MS_BTN2     , KC_MS_WH_UP , KC_MS_WH_DOWN  , KC_TRANSPARENT  ,
                    KC_NO            , KC_NO          , KC_NO       , KC_NO          ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  TO(DEFAULT) ,

           KC_NO             , KC_NO             , KC_NO        , KC_NO            , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO             , KC_NO             , KC_NO        , KC_NO            , KC_NO          , KC_NO  ,
           LGUI(KC_LBRACKET) , LCTL(LSFT(KC_TAB)), RCTL(KC_TAB) , LGUI(KC_RBRACKET), KC_TRANSPARENT , KC_NO  ,
           TD(DANCE_LEFT)    , TD(DANCE_DOWN)    , TD(DANCE_UP) , TD(DANCE_RIGHT)  , KC_ENTER       , KC_NO  ,
           KC_MS_ACCEL0      , KC_MS_ACCEL1      , KC_MS_ACCEL2 , KC_TRANSPARENT   , KC_TRANSPARENT , KC_NO  ,
                               KC_NO             , KC_NO        , KC_NO            , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_SPACE_OPEN)
    ),

[MISC] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO           , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO           ,
           KC_NO  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  ,
           KC_NO  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  ,
           KC_NO  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  ,
                    KC_NO          , KC_NO          , KC_NO          , KC_NO          ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  KC_TRANSPARENT ,

           KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO  ,
           KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_NO  ,
           KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_NO  ,
           KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_NO  ,
                            KC_NO          , KC_NO          , KC_NO          , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

[EXTRA] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO           , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO           ,
           KC_NO  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  ,
           KC_NO  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  ,
           KC_NO  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT  ,
                    KC_NO          , KC_NO          , KC_NO          , KC_NO          ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  KC_TRANSPARENT ,

           KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO          , KC_NO  ,
           KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_NO  ,
           KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_NO  ,
           KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_NO  ,
                            KC_NO          , KC_NO          , KC_NO          , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    )
};

// Dance definitions for letters

void on_dance_A(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_A_dance_step(qk_tap_dance_state_t *state);
void dance_A_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_A_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_A(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if(state->count > 3) {
        tap_code16(KC_A);
    }
}

uint8_t dance_A_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_A_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_A_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_A); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_A)); break;
        case DOUBLE_TAP: register_code16(KC_A); register_code16(KC_A); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
    }
}

void dance_A_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_A); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_A)); break;
        case DOUBLE_TAP: unregister_code16(KC_A); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
    }
    dance_state.step = 0;
}

void on_dance_B(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_B_dance_step(qk_tap_dance_state_t *state);
void dance_B_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_B_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_B(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if(state->count > 3) {
        tap_code16(KC_B);
    }
}

uint8_t dance_B_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_B_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_B_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_B); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_B)); break;
        case DOUBLE_TAP: register_code16(KC_B); register_code16(KC_B); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_B); register_code16(KC_B);
    }
}

void dance_B_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_B); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_B)); break;
        case DOUBLE_TAP: unregister_code16(KC_B); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_B); break;
    }
    dance_state.step = 0;
}

void on_dance_C(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_C_dance_step(qk_tap_dance_state_t *state);
void dance_C_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_C_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_C(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

uint8_t dance_C_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_C_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_C_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_C)); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_C_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state.step = 0;
}

void on_dance_D(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_D_dance_step(qk_tap_dance_state_t *state);
void dance_D_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_D_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_D(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_D);
        tap_code16(KC_D);
        tap_code16(KC_D);
    }
    if(state->count > 3) {
        tap_code16(KC_D);
    }
}

uint8_t dance_D_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_D_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_D_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_D); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_D)); break;
        case DOUBLE_TAP: register_code16(KC_D); register_code16(KC_D); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_D); register_code16(KC_D);
    }
}

void dance_D_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_D); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_D)); break;
        case DOUBLE_TAP: unregister_code16(KC_D); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_D); break;
    }
    dance_state.step = 0;
}

void on_dance_E(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_E_dance_step(qk_tap_dance_state_t *state);
void dance_E_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_E_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_E(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_E);
        tap_code16(KC_E);
        tap_code16(KC_E);
    }
    if(state->count > 3) {
        tap_code16(KC_E);
    }
}

uint8_t dance_E_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_E_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_E_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_E); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_E)); break;
        case DOUBLE_TAP: register_code16(KC_E); register_code16(KC_E); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_E); register_code16(KC_E);
    }
}

void dance_E_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_E); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_E)); break;
        case DOUBLE_TAP: unregister_code16(KC_E); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_E); break;
    }
    dance_state.step = 0;
}

void on_dance_F(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_F_dance_step(qk_tap_dance_state_t *state);
void dance_F_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_F_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_F(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if(state->count > 3) {
        tap_code16(KC_F);
    }
}

uint8_t dance_F_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_F_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_F_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_F); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_F)); break;
        case DOUBLE_TAP: register_code16(KC_F); register_code16(KC_F); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F); register_code16(KC_F);
    }
}

void dance_F_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_F); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_F)); break;
        case DOUBLE_TAP: unregister_code16(KC_F); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F); break;
    }
    dance_state.step = 0;
}

void on_dance_G(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_G_dance_step(qk_tap_dance_state_t *state);
void dance_G_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_G_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_G(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_G);
        tap_code16(KC_G);
        tap_code16(KC_G);
    }
    if(state->count > 3) {
        tap_code16(KC_G);
    }
}

uint8_t dance_G_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_G_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_G_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_G); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_G)); break;
        case DOUBLE_TAP: register_code16(KC_G); register_code16(KC_G); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_G); register_code16(KC_G);
    }
}

void dance_G_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_G); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_G)); break;
        case DOUBLE_TAP: unregister_code16(KC_G); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_G); break;
    }
    dance_state.step = 0;
}

void on_dance_H(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_H_dance_step(qk_tap_dance_state_t *state);
void dance_H_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_H_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_H(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if(state->count > 3) {
        tap_code16(KC_H);
    }
}

uint8_t dance_H_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_H_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_H_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_H); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_H)); break;
        case DOUBLE_TAP: register_code16(KC_H); register_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_H); register_code16(KC_H);
    }
}

void dance_H_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_H); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_H)); break;
        case DOUBLE_TAP: unregister_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break;
    }
    dance_state.step = 0;
}

void on_dance_I(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_I_dance_step(qk_tap_dance_state_t *state);
void dance_I_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_I_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_I(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

uint8_t dance_I_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_I_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_I_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_I)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void dance_I_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_I)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state.step = 0;
}

void on_dance_J(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_J_dance_step(qk_tap_dance_state_t *state);
void dance_J_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_J_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_J(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

uint8_t dance_J_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_J_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_J_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_J)); break;
        case DOUBLE_TAP: register_code16(KC_J); register_code16(KC_J); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void dance_J_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_J); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_J)); break;
        case DOUBLE_TAP: unregister_code16(KC_J); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
    }
    dance_state.step = 0;
}

void on_dance_K(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_K_dance_step(qk_tap_dance_state_t *state);
void dance_K_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_K_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_K(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

uint8_t dance_K_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_K_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_K_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_K)); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_K_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state.step = 0;
}

void on_dance_L(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_L_dance_step(qk_tap_dance_state_t *state);
void dance_L_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_L_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_L(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if(state->count > 3) {
        tap_code16(KC_L);
    }
}

uint8_t dance_L_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_L_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_L_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_L); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_L)); break;
        case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
    }
}

void dance_L_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_L); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_L)); break;
        case DOUBLE_TAP: unregister_code16(KC_L); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
    }
    dance_state.step = 0;
}

void on_dance_M(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_M_dance_step(qk_tap_dance_state_t *state);
void dance_M_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_M_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_M(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if(state->count > 3) {
        tap_code16(KC_M);
    }
}

uint8_t dance_M_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_M_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_M_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_M); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_M)); break;
        case DOUBLE_TAP: register_code16(KC_M); register_code16(KC_M); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_M); register_code16(KC_M);
    }
}

void dance_M_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_M); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_M)); break;
        case DOUBLE_TAP: unregister_code16(KC_M); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_M); break;
    }
    dance_state.step = 0;
}

void on_dance_N(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_N_dance_step(qk_tap_dance_state_t *state);
void dance_N_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_N_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_N(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

uint8_t dance_N_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_N_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_N_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_N)); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void dance_N_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state.step = 0;
}

void on_dance_O(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_O_dance_step(qk_tap_dance_state_t *state);
void dance_O_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_O_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_O(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

uint8_t dance_O_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_O_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_O_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void dance_O_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_O)); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state.step = 0;
}

void on_dance_P(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_P_dance_step(qk_tap_dance_state_t *state);
void dance_P_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_P_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_P(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

uint8_t dance_P_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_P_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_P_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_P)); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void dance_P_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_P); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_P)); break;
        case DOUBLE_TAP: unregister_code16(KC_P); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_P); break;
    }
    dance_state.step = 0;
}

void on_dance_Q(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_Q_dance_step(qk_tap_dance_state_t *state);
void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Q(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if(state->count > 3) {
        tap_code16(KC_Q);
    }
}

uint8_t dance_Q_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_Q_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_Q)); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state.step = 0;
}

void on_dance_R(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_R_dance_step(qk_tap_dance_state_t *state);
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_R_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_R(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_R);
        tap_code16(KC_R);
        tap_code16(KC_R);
    }
    if(state->count > 3) {
        tap_code16(KC_R);
    }
}

uint8_t dance_R_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_R_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_R); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_R)); break;
        case DOUBLE_TAP: register_code16(KC_R); register_code16(KC_R); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_R); register_code16(KC_R);
    }
}

void dance_R_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_R); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_R)); break;
        case DOUBLE_TAP: unregister_code16(KC_R); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_R); break;
    }
    dance_state.step = 0;
}

void on_dance_S(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_S_dance_step(qk_tap_dance_state_t *state);
void dance_S_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_S_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_S(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if(state->count > 3) {
        tap_code16(KC_S);
    }
}

uint8_t dance_S_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_S_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_S_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_S); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_S)); break;
        case DOUBLE_TAP: register_code16(KC_S); register_code16(KC_S); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_S); register_code16(KC_S);
    }
}

void dance_S_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_S); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_S)); break;
        case DOUBLE_TAP: unregister_code16(KC_S); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_S); break;
    }
    dance_state.step = 0;
}

void on_dance_T(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_T_dance_step(qk_tap_dance_state_t *state);
void dance_T_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_T_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_T(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_T);
        tap_code16(KC_T);
        tap_code16(KC_T);
    }
    if(state->count > 3) {
        tap_code16(KC_T);
    }
}

uint8_t dance_T_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_T_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_T_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_T); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_T)); break;
        case DOUBLE_TAP: register_code16(KC_T); register_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_T); register_code16(KC_T);
    }
}

void dance_T_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_T); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_T)); break;
        case DOUBLE_TAP: unregister_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_T); break;
    }
    dance_state.step = 0;
}

void on_dance_U(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_U_dance_step(qk_tap_dance_state_t *state);
void dance_U_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_U_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_U(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

uint8_t dance_U_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_U_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_U_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_U)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void dance_U_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_U)); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state.step = 0;
}

void on_dance_V(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_V_dance_step(qk_tap_dance_state_t *state);
void dance_V_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_V_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_V(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

uint8_t dance_V_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_V_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_V_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_V)); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_V_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state.step = 0;
}

void on_dance_W(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_W_dance_step(qk_tap_dance_state_t *state);
void dance_W_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_W_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_W(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_W);
        tap_code16(KC_W);
        tap_code16(KC_W);
    }
    if(state->count > 3) {
        tap_code16(KC_W);
    }
}

uint8_t dance_W_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_W_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_W_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_W); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_W)); break;
        case DOUBLE_TAP: register_code16(KC_W); register_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_W); register_code16(KC_W);
    }
}

void dance_W_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_W); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_W); break;
    }
    dance_state.step = 0;
}

void on_dance_X(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_X_dance_step(qk_tap_dance_state_t *state);
void dance_X_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_X_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_X(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

uint8_t dance_X_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_X_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_X_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_X)); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_X_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_X)); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state.step = 0;
}

void on_dance_Y(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_Y_dance_step(qk_tap_dance_state_t *state);
void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Y(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Y);
        tap_code16(KC_Y);
        tap_code16(KC_Y);
    }
    if(state->count > 3) {
        tap_code16(KC_Y);
    }
}

uint8_t dance_Y_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_Y_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_Y); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_Y)); break;
        case DOUBLE_TAP: register_code16(KC_Y); register_code16(KC_Y); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Y); register_code16(KC_Y);
    }
}

void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_Y); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_Y)); break;
        case DOUBLE_TAP: unregister_code16(KC_Y); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Y); break;
    }
    dance_state.step = 0;
}

void on_dance_Z(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_Z_dance_step(qk_tap_dance_state_t *state);
void dance_Z_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Z(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_Z);
    }
}

uint8_t dance_Z_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_Z_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_Z_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_Z); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_Z)); break;
        case DOUBLE_TAP: register_code16(KC_Z); register_code16(KC_Z); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
    }
}

void dance_Z_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_Z); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_Z)); break;
        case DOUBLE_TAP: unregister_code16(KC_Z); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
    }
    dance_state.step = 0;
}

void on_dance_COMMA(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_COMMA_dance_step(qk_tap_dance_state_t *state);
void dance_COMMA_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_COMMA_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_COMMA(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

uint8_t dance_COMMA_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_COMMA_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_COMMA_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_COMMA)); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_COMMA_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_COMMA)); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state.step = 0;
}

void on_dance_DOT(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_DOT_dance_step(qk_tap_dance_state_t *state);
void dance_DOT_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_DOT_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_DOT(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

uint8_t dance_DOT_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_DOT_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_DOT_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_DOT)); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_DOT_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_DOT)); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state.step = 0;
}

void on_dance_SLASH(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_SLASH_dance_step(qk_tap_dance_state_t *state);
void dance_SLASH_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_SLASH_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_SLASH(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

uint8_t dance_SLASH_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_SLASH_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_SLASH_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_SLASH)); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_SLASH_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_SLASH)); break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state.step = 0;
}

void on_dance_BSPACE(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_BSPACE_dance_step(qk_tap_dance_state_t *state);
void dance_BSPACE_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_BSPACE_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_BSPACE(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPACE);
        tap_code16(KC_BSPACE);
        tap_code16(KC_BSPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPACE);
    }
}

uint8_t dance_BSPACE_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_BSPACE_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_BSPACE_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_BSPACE); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_BSPACE)); break;
        case DOUBLE_TAP: register_code16(KC_BSPACE); register_code16(KC_BSPACE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPACE); register_code16(KC_BSPACE);
    }
}

void dance_BSPACE_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_BSPACE); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_BSPACE)); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPACE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPACE); break;
    }
    dance_state.step = 0;
}

void on_dance_SPACE(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_SPACE_dance_step(qk_tap_dance_state_t *state);
void dance_SPACE_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_SPACE_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_SPACE(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

uint8_t dance_SPACE_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_SPACE_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_SPACE_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_SPACE)); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_SPACE_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_SPACE)); break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state.step = 0;
}

void on_dance_DOLLAR(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_DOLLAR_dance_step(qk_tap_dance_state_t *state);
void dance_DOLLAR_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_DOLLAR_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_DOLLAR(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOLLAR);
        tap_code16(KC_DOLLAR);
        tap_code16(KC_DOLLAR);
    }
    if(state->count > 3) {
        tap_code16(KC_DOLLAR);
    }
}

uint8_t dance_DOLLAR_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_DOLLAR_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_DOLLAR_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_DOLLAR); break;
        case SINGLE_HOLD: register_code16(LCTL(LGUI(LSFT(KC_4)))); break;
        case DOUBLE_TAP: register_code16(KC_DOLLAR); register_code16(KC_DOLLAR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOLLAR); register_code16(KC_DOLLAR);
    }
}

void dance_DOLLAR_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_DOLLAR); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LGUI(LSFT(KC_4)))); break;
        case DOUBLE_TAP: unregister_code16(KC_DOLLAR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOLLAR); break;
    }
    dance_state.step = 0;
}

void on_dance_BSLASH(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_BSLASH_dance_step(qk_tap_dance_state_t *state);
void dance_BSLASH_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_BSLASH_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_BSLASH(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_BSLASH);
    }
}

uint8_t dance_BSLASH_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_BSLASH_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_BSLASH_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_BSLASH); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_BSLASH); register_code16(KC_BSLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSLASH); register_code16(KC_BSLASH);
    }
}

void dance_BSLASH_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_BSLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLASH); break;
    }
    dance_state.step = 0;
}

void on_dance_LCBR(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_LCBR_dance_step(qk_tap_dance_state_t *state);
void dance_LCBR_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_LCBR_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_LCBR(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

uint8_t dance_LCBR_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_LCBR_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_LCBR_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_LBRACKET))); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_LCBR_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_LBRACKET))); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state.step = 0;
}

void on_dance_LBRC(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_LBRC_dance_step(qk_tap_dance_state_t *state);
void dance_LBRC_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_LBRC_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_LBRC(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LBRACKET);
        tap_code16(KC_LBRACKET);
        tap_code16(KC_LBRACKET);
    }
    if(state->count > 3) {
        tap_code16(KC_LBRACKET);
    }
}

uint8_t dance_LBRC_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_LBRC_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_LBRC_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_LBRACKET); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_LBRACKET)); break;
        case DOUBLE_TAP: register_code16(KC_LBRACKET); register_code16(KC_LBRACKET); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LBRACKET); register_code16(KC_LBRACKET);
    }
}

void dance_LBRC_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_LBRACKET); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_LBRACKET)); break;
        case DOUBLE_TAP: unregister_code16(KC_LBRACKET); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LBRACKET); break;
    }
    dance_state.step = 0;
}

void on_dance_RCBR(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_RCBR_dance_step(qk_tap_dance_state_t *state);
void dance_RCBR_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_RCBR_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_RCBR(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_RCBR);
    }
}

uint8_t dance_RCBR_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_RCBR_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_RCBR_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_RCBR); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_RBRACKET))); break;
        case DOUBLE_TAP: register_code16(KC_RCBR); register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RCBR); register_code16(KC_RCBR);
    }
}

void dance_RCBR_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_RBRACKET))); break;
        case DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
    }
    dance_state.step = 0;
}

void on_dance_RBRC(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_RBRC_dance_step(qk_tap_dance_state_t *state);
void dance_RBRC_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_RBRC_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_RBRC(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RBRACKET);
        tap_code16(KC_RBRACKET);
        tap_code16(KC_RBRACKET);
    }
    if(state->count > 3) {
        tap_code16(KC_RBRACKET);
    }
}

uint8_t dance_RBRC_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_RBRC_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_RBRC_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_RBRACKET); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_RBRACKET)); break;
        case DOUBLE_TAP: register_code16(KC_RBRACKET); register_code16(KC_RBRACKET); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RBRACKET); register_code16(KC_RBRACKET);
    }
}

void dance_RBRC_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_RBRACKET); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_RBRACKET)); break;
        case DOUBLE_TAP: unregister_code16(KC_RBRACKET); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RBRACKET); break;
    }
    dance_state.step = 0;
}

void on_dance_PIPE(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_PIPE_dance_step(qk_tap_dance_state_t *state);
void dance_PIPE_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_PIPE_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_PIPE(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
    }
    if(state->count > 3) {
        tap_code16(KC_PIPE);
    }
}

uint8_t dance_PIPE_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_PIPE_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_PIPE_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_PIPE); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE);
    }
}

void dance_PIPE_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_PIPE); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
    }
    dance_state.step = 0;
}

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_0_dance_step(qk_tap_dance_state_t *state);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if(state->count > 3) {
        tap_code16(KC_0);
    }
}

uint8_t dance_0_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_0_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_0); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_0)); break;
        case DOUBLE_TAP: register_code16(KC_0); register_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_0); register_code16(KC_0);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_0); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_0)); break;
        case DOUBLE_TAP: unregister_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
    }
    dance_state.step = 0;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_1);
        tap_code16(KC_1);
        tap_code16(KC_1);
    }
    if(state->count > 3) {
        tap_code16(KC_1);
    }
}

uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_1_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_1); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_1)); break;
        case DOUBLE_TAP: register_code16(KC_1); register_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_1); register_code16(KC_1);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_1); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_1)); break;
        case DOUBLE_TAP: unregister_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_1); break;
    }
    dance_state.step = 0;
}

void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(qk_tap_dance_state_t *state);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_2);
        tap_code16(KC_2);
        tap_code16(KC_2);
    }
    if(state->count > 3) {
        tap_code16(KC_2);
    }
}

uint8_t dance_2_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_2_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_2); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_2)); break;
        case DOUBLE_TAP: register_code16(KC_2); register_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_2); register_code16(KC_2);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_2); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_2)); break;
        case DOUBLE_TAP: unregister_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_2); break;
    }
    dance_state.step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_3_dance_step(qk_tap_dance_state_t *state);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_3);
        tap_code16(KC_3);
        tap_code16(KC_3);
    }
    if(state->count > 3) {
        tap_code16(KC_3);
    }
}

uint8_t dance_3_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_3_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_3); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_3)); break;
        case DOUBLE_TAP: register_code16(KC_3); register_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_3); register_code16(KC_3);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_3); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_3)); break;
        case DOUBLE_TAP: unregister_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_3); break;
    }
    dance_state.step = 0;
}

void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_4_dance_step(qk_tap_dance_state_t *state);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if(state->count > 3) {
        tap_code16(KC_4);
    }
}

uint8_t dance_4_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_4_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_4); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_4)); break;
        case DOUBLE_TAP: register_code16(KC_4); register_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_4); register_code16(KC_4);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_4); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_4)); break;
        case DOUBLE_TAP: unregister_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_4); break;
    }
    dance_state.step = 0;
}

void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_5_dance_step(qk_tap_dance_state_t *state);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

uint8_t dance_5_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_5_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_5); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_5)); break;
        case DOUBLE_TAP: register_code16(KC_5); register_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_5); register_code16(KC_5);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_5); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_5)); break;
        case DOUBLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_5); break;
    }
    dance_state.step = 0;
}

void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_6_dance_step(qk_tap_dance_state_t *state);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

uint8_t dance_6_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_6_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_6); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_6)); break;
        case DOUBLE_TAP: register_code16(KC_6); register_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_6); register_code16(KC_6);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_6); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_6)); break;
        case DOUBLE_TAP: unregister_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_6); break;
    }
    dance_state.step = 0;
}

void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_7_dance_step(qk_tap_dance_state_t *state);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_7);
        tap_code16(KC_7);
        tap_code16(KC_7);
    }
    if(state->count > 3) {
        tap_code16(KC_7);
    }
}

uint8_t dance_7_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_7_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_7); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_7)); break;
        case DOUBLE_TAP: register_code16(KC_7); register_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_7); register_code16(KC_7);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_7); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_7)); break;
        case DOUBLE_TAP: unregister_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_7); break;
    }
    dance_state.step = 0;
}

void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_8_dance_step(qk_tap_dance_state_t *state);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if(state->count > 3) {
        tap_code16(KC_8);
    }
}

uint8_t dance_8_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_8_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_8); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_8)); break;
        case DOUBLE_TAP: register_code16(KC_8); register_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_8); register_code16(KC_8);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_8); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_8)); break;
        case DOUBLE_TAP: unregister_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_8); break;
    }
    dance_state.step = 0;
}

void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_9_dance_step(qk_tap_dance_state_t *state);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_9);
        tap_code16(KC_9);
        tap_code16(KC_9);
    }
    if(state->count > 3) {
        tap_code16(KC_9);
    }
}

uint8_t dance_9_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_9_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_9); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_9)); break;
        case DOUBLE_TAP: register_code16(KC_9); register_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_9); register_code16(KC_9);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_9); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_9)); break;
        case DOUBLE_TAP: unregister_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_9); break;
    }
    dance_state.step = 0;
}

void on_dance_EQUAL(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_EQUAL_dance_step(qk_tap_dance_state_t *state);
void dance_EQUAL_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_EQUAL_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_EQUAL(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

uint8_t dance_EQUAL_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_EQUAL_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_EQUAL_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_EQUAL)); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_EQUAL_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_EQUAL)); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state.step = 0;
}

void on_dance_MINUS(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_MINUS_dance_step(qk_tap_dance_state_t *state);
void dance_MINUS_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_MINUS_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_MINUS(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

uint8_t dance_MINUS_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_MINUS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_MINUS_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_MINUS)); break;
        case DOUBLE_TAP: register_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_MINUS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_MINUS)); break;
        case DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state.step = 0;
}

void on_dance_PLUS(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_PLUS_dance_step(qk_tap_dance_state_t *state);
void dance_PLUS_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_PLUS_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_PLUS(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PLUS);
        tap_code16(KC_PLUS);
        tap_code16(KC_PLUS);
    }
    if(state->count > 3) {
        tap_code16(KC_PLUS);
    }
}

uint8_t dance_PLUS_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_PLUS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_PLUS_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_PLUS); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_PLUS)); break;
        case DOUBLE_TAP: register_code16(KC_PLUS); register_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PLUS); register_code16(KC_PLUS);
    }
}

void dance_PLUS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_PLUS); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_EQUAL))); break;
        case DOUBLE_TAP: unregister_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PLUS); break;
    }
    dance_state.step = 0;
}

void on_dance_UNDS(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_UNDS_dance_step(qk_tap_dance_state_t *state);
void dance_UNDS_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_UNDS_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_UNDS(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
    }
    if(state->count > 3) {
        tap_code16(KC_UNDS);
    }
}

uint8_t dance_UNDS_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_UNDS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_UNDS_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_UNDS); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_MINUS))); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS);
    }
}

void dance_UNDS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_UNDS)); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break;
    }
    dance_state.step = 0;
}

void on_dance_ESCAPE(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_ESCAPE_dance_step(qk_tap_dance_state_t *state);
void dance_ESCAPE_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_ESCAPE_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_ESCAPE(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

uint8_t dance_ESCAPE_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_ESCAPE_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_ESCAPE_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_ESCAPE)); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_ESCAPE_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_ESCAPE)); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state.step = 0;
}

void on_dance_TAB(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_TAB_dance_step(qk_tap_dance_state_t *state);
void dance_TAB_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_TAB_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_TAB(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

uint8_t dance_TAB_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_TAB_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_TAB_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_TAB_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state.step = 0;
}

void on_dance_SPACE_OPEN(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_SPACE_OPEN_dance_step(qk_tap_dance_state_t *state);
void dance_SPACE_OPEN_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_SPACE_OPEN_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_SPACE_OPEN(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

uint8_t dance_SPACE_OPEN_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_SPACE_OPEN_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_SPACE_OPEN_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: register_code16(LCMD(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_SPACE_OPEN_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD: unregister_code16(LCMD(KC_SPACE)); break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state.step = 0;
}

void on_dance_LEFT(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_LEFT_dance_step(qk_tap_dance_state_t *state);
void dance_LEFT_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_LEFT_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_LEFT(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

uint8_t dance_LEFT_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_LEFT_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_LEFT_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_LEFT_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state.step = 0;
}

void on_dance_DOWN(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_DOWN_dance_step(qk_tap_dance_state_t *state);
void dance_DOWN_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_DOWN_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_DOWN(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
    }
    if(state->count > 3) {
        tap_code16(KC_DOWN);
    }
}

uint8_t dance_DOWN_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_DOWN_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_DOWN_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_DOWN); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(LGUI(LSFT(KC_N))))); break;
        case DOUBLE_TAP: register_code16(KC_DOWN); register_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOWN); register_code16(KC_DOWN);
    }
}

void dance_DOWN_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_DOWN); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_N))))); break;
        case DOUBLE_TAP: unregister_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOWN); break;
    }
    dance_state.step = 0;
}
void on_dance_UP(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_UP_dance_step(qk_tap_dance_state_t *state);
void dance_UP_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_UP_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_UP(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UP);
        tap_code16(KC_UP);
        tap_code16(KC_UP);
    }
    if(state->count > 3) {
        tap_code16(KC_UP);
    }
}

uint8_t dance_UP_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_UP_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_UP_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_UP); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(LGUI(LSFT(KC_M))))); break;
        case DOUBLE_TAP: register_code16(KC_UP); register_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UP); register_code16(KC_UP);
    }
}

void dance_UP_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_UP); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_M))))); break;
        case DOUBLE_TAP: unregister_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UP); break;
    }
    dance_state.step = 0;
}

void on_dance_RIGHT(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_RIGHT_dance_step(qk_tap_dance_state_t *state);
void dance_RIGHT_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_RIGHT_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_RIGHT(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

uint8_t dance_RIGHT_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_RIGHT_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_RIGHT_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_RIGHT_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_A, dance_A_finished, dance_A_reset),
        [DANCE_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_B, dance_B_finished, dance_B_reset),
        [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset),
        [DANCE_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_D, dance_D_finished, dance_D_reset),
        [DANCE_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_E, dance_E_finished, dance_E_reset),
        [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset),
        [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset),
        [DANCE_H] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_H, dance_H_finished, dance_H_reset),
        [DANCE_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_I, dance_I_finished, dance_I_reset),
        [DANCE_J] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_J, dance_J_finished, dance_J_reset),
        [DANCE_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_K, dance_K_finished, dance_K_reset),
        [DANCE_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_L, dance_L_finished, dance_L_reset),
        [DANCE_M] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_M, dance_M_finished, dance_M_reset),
        [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_N, dance_N_finished, dance_N_reset),
        [DANCE_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_O, dance_O_finished, dance_O_reset),
        [DANCE_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_P, dance_P_finished, dance_P_reset),
        [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Q, dance_Q_finished, dance_Q_reset),
        [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_R, dance_R_finished, dance_R_reset),
        [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_S, dance_S_finished, dance_S_reset),
        [DANCE_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_T, dance_T_finished, dance_T_reset),
        [DANCE_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_U, dance_U_finished, dance_U_reset),
        [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_V, dance_V_finished, dance_V_reset),
        [DANCE_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_W, dance_W_finished, dance_W_reset),
        [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_X, dance_X_finished, dance_X_reset),
        [DANCE_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Y, dance_Y_finished, dance_Y_reset),
        [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Z, dance_Z_finished, dance_Z_reset),
        [DANCE_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_COMMA, dance_COMMA_finished, dance_COMMA_reset),
        [DANCE_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_DOT, dance_DOT_finished, dance_DOT_reset),
        [DANCE_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_SLASH, dance_SLASH_finished, dance_SLASH_reset),
        [DANCE_BSPACE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_BSPACE, dance_BSPACE_finished, dance_BSPACE_reset),
        [DANCE_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_SPACE, dance_SPACE_finished, dance_SPACE_reset),
        [DANCE_DOLLAR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_DOLLAR, dance_DOLLAR_finished, dance_DOLLAR_reset),
        [DANCE_BSLASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_BSLASH, dance_BSLASH_finished, dance_BSLASH_reset),
        [DANCE_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_LCBR, dance_LCBR_finished, dance_LCBR_reset),
        [DANCE_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_LBRC, dance_LBRC_finished, dance_LBRC_reset),
        [DANCE_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_RCBR, dance_RCBR_finished, dance_RCBR_reset),
        [DANCE_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_RBRC, dance_RBRC_finished, dance_RBRC_reset),
        [DANCE_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_PIPE, dance_PIPE_finished, dance_PIPE_reset),
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_EQUAL] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_EQUAL, dance_EQUAL_finished, dance_EQUAL_reset),
        [DANCE_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_MINUS, dance_MINUS_finished, dance_MINUS_reset),
        [DANCE_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_PLUS, dance_PLUS_finished, dance_PLUS_reset),
        [DANCE_UNDS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_UNDS, dance_UNDS_finished, dance_UNDS_reset),
        [DANCE_ESCAPE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ESCAPE, dance_ESCAPE_finished, dance_ESCAPE_reset),
        [DANCE_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_TAB, dance_TAB_finished, dance_TAB_reset),
        [DANCE_SPACE_OPEN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_SPACE_OPEN, dance_SPACE_OPEN_finished, dance_SPACE_OPEN_reset),
        [DANCE_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_LEFT, dance_LEFT_finished, dance_LEFT_reset),
        [DANCE_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_RIGHT, dance_RIGHT_finished, dance_RIGHT_reset),
        [DANCE_UP] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_UP, dance_UP_finished, dance_UP_reset),
        [DANCE_DOWN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_DOWN, dance_DOWN_finished, dance_DOWN_reset),
};
