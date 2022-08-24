#include QMK_KEYBOARD_H

#define DEFAULT        0
#define ONE_SHOT_LAYER 1
#define NUM_CTRL       2
#define NAVIGATION     3
#define MISC           4
#define EXTRA          5

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum tap_dance_codes {
  TD_Q_ESC = 0,
  TD_SPACE_SPOTLIGHT,
  TD_BLASH_CTRL_L,
  TD_LCBR_CTRL_D,
  TD_RCBR_CTRL_U,
  TD_PIPE_CTRL_R
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

void space_spotlight_finished(qk_tap_dance_state_t *state, void *user_data);
void space_spotlight_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DEFAULT] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,KC_NO   ,KC_NO ,KC_NO   ,
           KC_NO  , KC_NO          , KC_NO         , KC_NO         , KC_NO         , KC_NO         ,
           KC_NO  , TD(TD_Q_ESC)   , KC_W          , KC_E          , KC_R          , KC_T   ,
           KC_NO  , KC_A           , KC_S          , KC_D          , KC_F          , KC_G   ,
           KC_NO  , KC_Z           , KC_X          , KC_C          , KC_V          , KC_B   ,
                    KC_NO          , KC_NO         , KC_NO         , KC_NO  ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           OSM(MOD_RCTL), OSM(MOD_LSFT),  OSM(MOD_MEH) ,

           KC_NO         , KC_NO          , KC_NO           , KC_NO         , KC_NO            , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO         , KC_NO          , KC_NO           , KC_NO         , KC_NO            , KC_NO  ,
           KC_Y          , KC_U           , KC_I            , KC_O          , KC_P             , KC_NO  ,
           KC_H          , KC_J           , KC_K            , KC_L          , KC_BSPACE        , KC_NO  ,
           KC_N          , KC_M           , KC_COMMA        , KC_DOT        , KC_SLASH         , KC_NO  ,
                           KC_NO          , KC_NO  , KC_NO  , KC_NO         ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           OSL(ONE_SHOT_LAYER), OSM(MOD_LGUI), TD(TD_SPACE_SPOTLIGHT)
    ),

[ONE_SHOT_LAYER] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO            , KC_NO     , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO          , KC_NO          , KC_NO          , KC_NO            , KC_NO     ,
           KC_NO  , KC_ESCAPE      , KC_AT          , KC_HASH        , KC_DOLLAR        , KC_PERC   ,
           KC_NO  , KC_TAB         , KC_UNDS        , KC_EXLM        , KC_MINUS         , KC_QUOTE  ,
           KC_NO  , TO(NAVIGATION) , KC_GRAVE       , KC_EQUAL       , KC_PLUS          , KC_DQUO   ,
                    KC_NO          , KC_NO          , KC_NO          , KC_NO            ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  KC_TRANSPARENT ,

           KC_NO               , KC_NO              , KC_NO              , KC_NO              , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO               , KC_NO              , KC_NO              , KC_NO              , KC_NO          , KC_NO  ,
           KC_CIRC             , KC_AMPR            , KC_ASTR            , KC_SCOLON          , KC_COLON       , KC_NO  ,
           TD(TD_BLASH_CTRL_L) , TD(TD_LCBR_CTRL_D) , TD(TD_RCBR_CTRL_U) , TD(TD_PIPE_CTRL_R) , KC_TRANSPARENT , KC_NO  ,
           KC_LBRC             , KC_LPRN            , KC_RPRN            , KC_RBRC            , KC_ENTER       , KC_NO  ,
                                KC_NO              , KC_NO              , KC_NO              , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           TO(NUM_CTRL)    , KC_TRANSPARENT,  OSM(MOD_LALT)
    ),

[NUM_CTRL] = LAYOUT(
           KC_NO  , KC_NO          , KC_NO               , KC_NO               , KC_NO               , KC_NO           , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO          , KC_NO               , KC_NO               , KC_NO               , KC_NO           ,
           KC_NO  , KC_ESCAPE      , KC_MEDIA_PLAY_PAUSE , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , KC_UNDS         ,
           KC_NO  , KC_TAB         , KC_AUDIO_MUTE       , KC_AUDIO_VOL_DOWN   , KC_AUDIO_VOL_UP     , KC_PLUS         ,
           KC_NO  , TO(MISC)       , KC_BRIGHTNESS_DOWN  , KC_BRIGHTNESS_UP    , KC_KP_ASTERISK      , KC_KP_DOT       ,
                    KC_NO          , KC_NO               , KC_NO               , KC_NO               ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  TO(DEFAULT) ,

           KC_NO            , KC_NO          , KC_NO           , KC_NO            , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO            , KC_NO          , KC_NO           , KC_NO            , KC_NO          , KC_NO  ,
           KC_MINUS         , KC_7           , KC_8            , KC_9             , KC_TRANSPARENT , KC_NO  ,
           KC_EQUAL         , KC_4           , KC_5            , KC_6             , KC_BSPACE      , KC_NO  ,
           KC_0             , KC_1           , KC_2            , KC_3             , KC_ENTER       , KC_NO  ,
                              KC_NO          , KC_NO           , KC_NO            , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_RGUI)
    ),

[NAVIGATION] = LAYOUT(
           KC_NO  , KC_NO            , KC_NO          , KC_NO       , KC_NO          , KC_NO           , KC_NO   , KC_NO , KC_NO   ,
           KC_NO  , KC_NO            , KC_NO          , KC_NO       , KC_NO          , KC_NO           ,
           KC_NO  , KC_ESCAPE        , KC_MS_WH_LEFT  , KC_MS_UP    , KC_MS_WH_RIGHT , KC_TRANSPARENT  ,
           KC_NO  , KC_TAB           , KC_MS_LEFT     , KC_MS_DOWN  , KC_MS_RIGHT    , KC_TRANSPARENT  ,
           KC_NO  , KC_MS_BTN1       , KC_MS_BTN2     , KC_MS_WH_UP , KC_MS_WH_DOWN  , KC_TRANSPARENT  ,
                    KC_NO            , KC_NO          , KC_NO       , KC_NO          ,

                   KC_NO    , KC_NO  ,
                              KC_NO  ,
           KC_TRANSPARENT  , KC_TRANSPARENT,  TO(DEFAULT) ,

           KC_NO             , KC_NO              , KC_NO        , KC_NO             , KC_NO          , KC_NO  , KC_NO , KC_NO, KC_NO ,
           KC_NO             , KC_NO              , KC_NO        , KC_NO             , KC_NO          , KC_NO  ,
           LGUI(KC_LBRACKET) , LCTL(LSFT(KC_TAB)) , RCTL(KC_TAB) , LGUI(KC_RBRACKET) , KC_TRANSPARENT , KC_NO  ,
           KC_LEFT           , KC_DOWN            , KC_UP        , KC_RIGHT          , KC_BSPACE      , KC_NO  ,
           KC_MS_ACCEL0      , KC_MS_ACCEL1       , KC_MS_ACCEL2 , KC_TRANSPARENT    , KC_ENTER       , KC_NO  ,
                               KC_NO              , KC_NO        , KC_NO             , KC_NO          ,

           KC_NO  , KC_NO   ,
           KC_NO  ,
           KC_TRANSPARENT, KC_TRANSPARENT, TD(TD_SPACE_SPOTLIGHT)
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

////////////////////////////////////////////////////////////////////////////////

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you
        // want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and
        // actually wanting a double tap action when hitting 'pp'. Suggested use
        // case for this return value is when you want to send two keystrokes of
        // the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least
    // not quickly).  If your tap dance key is 'KC_W', and you want to type
    // "www." quickly - then you will need to add an exception here to return a
    // 'TD_TRIPLE_SINGLE_TAP', and define that enum just like
    // 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

////////////////////////////////////////////////////////////////////////////////

static td_tap_t space_spotlight_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void space_spotlight_finished(qk_tap_dance_state_t *state, void *user_data) {
    space_spotlight_state.state = cur_dance(state);
    switch (space_spotlight_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_SPACE); break;
        case TD_SINGLE_HOLD: register_code16(KC_SPACE); break;
        case TD_DOUBLE_TAP: register_code16(KC_SPACE); break;
        case TD_DOUBLE_HOLD: register_code16(LCMD(KC_O)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE); break;
        default: break;
    }
}

void space_spotlight_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (space_spotlight_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_SPACE); break;
        case TD_DOUBLE_TAP: unregister_code16(LCMD(KC_O)); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_SPACE); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
        default: break;
    }
    space_spotlight_state.state = TD_NONE;
}

////////////////////////////////////////////////////////////////////////////////

static td_tap_t blash_ctrl_l_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void blash_ctrl_l_finished(qk_tap_dance_state_t *state, void *user_data) {
    blash_ctrl_l_state.state = cur_dance(state);
    switch (blash_ctrl_l_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_BSLASH); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_LEFT)); break;
        case TD_DOUBLE_TAP: register_code16(KC_BSLASH); break;
        case TD_DOUBLE_HOLD: register_code16(KC_BSLASH); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_BSLASH); register_code16(KC_BSLASH); break;
        default: break;
    }
}

void blash_ctrl_l_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (blash_ctrl_l_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_BSLASH); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_LEFT)); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_BSLASH); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_BSLASH); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLASH); break;
        default: break;
    }
    blash_ctrl_l_state.state = TD_NONE;
}

////////////////////////////////////////////////////////////////////////////////

static td_tap_t lcbr_ctrl_d_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void lcbr_ctrl_d_finished(qk_tap_dance_state_t *state, void *user_data) {
    lcbr_ctrl_d_state.state = cur_dance(state);
    switch (lcbr_ctrl_d_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_LCBR); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_DOWN)); break;
        case TD_DOUBLE_TAP: register_code16(KC_LCBR); break;
        case TD_DOUBLE_HOLD: register_code16(KC_LCBR); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR); break;
        default: break;
    }
}

void lcbr_ctrl_d_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lcbr_ctrl_d_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_DOWN)); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_LCBR); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
        default: break;
    }
    lcbr_ctrl_d_state.state = TD_NONE;
}

////////////////////////////////////////////////////////////////////////////////

static td_tap_t rcbr_ctrl_u_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void rcbr_ctrl_u_finished(qk_tap_dance_state_t *state, void *user_data) {
    rcbr_ctrl_u_state.state = cur_dance(state);
    switch (rcbr_ctrl_u_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_RCBR); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_UP)); break;
        case TD_DOUBLE_TAP: register_code16(KC_RCBR); break;
        case TD_DOUBLE_HOLD: register_code16(KC_RCBR); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_RCBR); register_code16(KC_RCBR); break;
        default: break;
    }
}

void rcbr_ctrl_u_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rcbr_ctrl_u_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_UP)); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_RCBR); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
        default: break;
    }
    rcbr_ctrl_u_state.state = TD_NONE;
}

////////////////////////////////////////////////////////////////////////////////

static td_tap_t pipe_ctrl_r_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void pipe_ctrl_r_finished(qk_tap_dance_state_t *state, void *user_data) {
    pipe_ctrl_r_state.state = cur_dance(state);
    switch (pipe_ctrl_r_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_PIPE); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_RIGHT)); break;
        case TD_DOUBLE_TAP: register_code16(KC_PIPE); break;
        case TD_DOUBLE_HOLD: register_code16(KC_PIPE); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE); break;
        default: break;
    }
}

void pipe_ctrl_r_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (pipe_ctrl_r_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_PIPE); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_RIGHT)); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_PIPE); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
        default: break;
    }
    pipe_ctrl_r_state.state = TD_NONE;
}

////////////////////////////////////////////////////////////////////////////////

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_BLASH_CTRL_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, blash_ctrl_l_finished, blash_ctrl_l_reset),
  [TD_LCBR_CTRL_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lcbr_ctrl_d_finished, lcbr_ctrl_d_reset),
  [TD_RCBR_CTRL_U] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rcbr_ctrl_u_finished, rcbr_ctrl_u_reset),
  [TD_PIPE_CTRL_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pipe_ctrl_r_finished, pipe_ctrl_r_reset),
  [TD_SPACE_SPOTLIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_spotlight_finished, space_spotlight_reset)
};
