#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum keymap_layer {
  KL_QWERTY,
  KL_LOWER,
  KL_RAISE,
  KL_ADJUST,
  KL_SCROLL,
};

typedef uint32_t layer_state_t;
#define LAYER_STATE_BIT(layer)  (1UL<<layer)
static const layer_state_t LOWER_LAYER_MASK = LAYER_STATE_BIT(KL_LOWER)
                                            | LAYER_STATE_BIT(KL_SCROLL);
static const layer_state_t RAISE_LAYER_MASK = LAYER_STATE_BIT(KL_RAISE);

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  DELETE_FORWARD_WORD,
  DELETE_BACKWARD_WORD,
  UNDO,
  CUT,
  COPY,
  PASTE,
  REDO,
};

enum tap_dance_code {
  TC_SELECT,
};

#define M_DFW     DELETE_FORWARD_WORD
#define M_DBW     DELETE_BACKWARD_WORD

#define MO_LOWER  MO(KL_LOWER)
#define MO_RAISE  MO(KL_RAISE)
#define TG_SCRL   TG(KL_SCROLL)

#define MT_SAS    MT(MOD_LSFT, KC_SPACE)
#define C_TOP     C(KC_HOME)    // move to top
#define C_BTTM    C(KC_END)     // move to bottom
#define C_MBW     C(KC_LEFT)    // move to backward-word
#define C_MFW     C(KC_RGHT)    // move to forward-word
#define PREV      A(KC_LEFT)    // previous location
#define NEXT      A(KC_RIGHT)   // next location
#define SCRL_UP   C(KC_UP)      // scroll line up
#define SCRL_DN   C(KC_DOWN)    // scroll line down
#define SCRL_PU   A(KC_PGUP)    // scroll page up
#define SCRL_PD   A(KC_PGDOWN)  // scroll page down
#define S_QUOT    S(KC_QUOT)
#ifdef TAP_DANCE_ENABLE
  #define TD_SLCT   TD(TC_SELECT)
#else
  #define TD_SLCT   XXXXXXX
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [KL_QWERTY] = LAYOUT(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_GRV,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LCTL,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT,   LOWER,  MT_SAS,  KC_SPC,  KC_SPC,  MT_SAS,   RAISE, KC_RALT, KC_RGUI
  ),

  [KL_LOWER] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    KC_CAPS,  KC_ESC,   C_TOP,  C_BTTM, TG_SCRL, XXXXXXX,                      REDO, TD_SLCT, KC_HOME,  KC_END, XXXXXXX, _______,
    _______, KC_PGUP,   KC_UP, KC_DOWN, KC_PGDN,  KC_DEL,                   KC_BSPC,   C_MBW, KC_LEFT, KC_RGHT,   C_MFW, _______,
    _______,    UNDO,     CUT,    COPY,   PASTE, XXXXXXX, KC_QUOT, KC_QUOT, XXXXXXX,  KC_ENT,   M_DBW,   M_DFW, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [KL_RAISE] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,    KC_F, XXXXXXX,                   XXXXXXX,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  S_QUOT,  S_QUOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [KL_ADJUST] =  LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______,   RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, KC_BSPC,
    _______, XXXXXXX, XXXXXXX,   AU_ON,  AU_OFF, AG_NORM,                   AG_SWAP, XXXXXXX, BL_TOGG, BL_STEP, XXXXXXX, _______,
    _______, QWERTY,  COLEMAK,  DVORAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [KL_SCROLL] =  LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______,    PREV,    NEXT, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, SCRL_PU, SCRL_UP, SCRL_DN, SCRL_PD, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

// Process Record events is listed below.
//  void process_record(keyrecord_t *record)
//    bool process_record_quantum(keyrecord_t *record)
//      Map this record to a keycode
//      void preprocess_tap_dance(uint16_t keycode, keyrecord_t *record)
//      bool process_record_kb(uint16_t keycode, keyrecord_t *record)
//        bool process_record_user(uint16_t keycode, keyrecord_t *record)
//      bool process_tap_dance(uint16_t keycode, keyrecord_t *record)
//      bool process_combo(uint16_t keycode, keyrecord_t *record)

#define PROCESS_OVERRIDE_BEHAVIOR   false
#define PROCESS_USUAL_BEHAVIOR      true
#define IF_PRESSED                  if (record->event.pressed)
static void process_caps_lock(uint16_t keycode, keyrecord_t *record);
static void process_LOWER(bool is_pressed, bool is_tapped);
static void process_RAISE(bool is_pressed, bool is_tapped);
static void process_delete_forward_word(void);
static void process_delete_backward_word(void);
static void process_undo(void);
static void process_cut(void);
static void process_copy(void);
static void process_paste(void);
static void process_redo(void);
static void store_mods(void);
static void restore_mods(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  static uint16_t mem_keycode;
  uint16_t prev_keycode = mem_keycode;
  bool is_tapped = ((!record->event.pressed) && (keycode == prev_keycode));
  mem_keycode = keycode;

  process_caps_lock(keycode, record);

  dprintf("process_record_user: %d\n", keycode);
  switch (keycode) {

    case LOWER: {
      process_LOWER((record->event.pressed), is_tapped);
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case RAISE: {
      process_RAISE((record->event.pressed), is_tapped);
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case QWERTY: IF_PRESSED {
      set_single_persistent_default_layer(KL_QWERTY);
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case DELETE_FORWARD_WORD: IF_PRESSED {
      process_delete_forward_word();
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case DELETE_BACKWARD_WORD: IF_PRESSED {
      process_delete_backward_word();
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case UNDO: IF_PRESSED {
      process_undo();
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case CUT: IF_PRESSED {
      process_cut();
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case COPY: IF_PRESSED {
      process_copy();
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case PASTE: IF_PRESSED {
      process_paste();
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

    case REDO: IF_PRESSED {
      process_redo();
      return PROCESS_OVERRIDE_BEHAVIOR;
    } break;

  }

  return PROCESS_USUAL_BEHAVIOR;
}

// rules.mk: TAP_DANCE_ENABLE = yes
#ifdef TAP_DANCE_ENABLE
void tap_dance_select(qk_tap_dance_state_t *state, void *user_data);
qk_tap_dance_action_t tap_dance_actions[] =  {
  [TC_SELECT] = ACTION_TAP_DANCE_FN(tap_dance_select),
};

void tap_dance_select(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 1) {
    // switch shift mod
    if (get_mods() & MOD_MASK_SHIFT) {
      set_mods(get_mods() & (~MOD_MASK_SHIFT));
    }
    else {
      set_mods(get_mods() | MOD_BIT(KC_LSFT));
    }
  }
  else if (state->count == 2) {
    // select word
    register_code(KC_LCTL);
    tap_code(KC_RIGHT);
    register_code(KC_LSFT);
    tap_code(KC_LEFT);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
  }
  else {
    // ignore
  }
}
#endif // TAP_DANCE_ENABLE

// rules.mk: COMBO_ENABLE = yes
#ifdef COMBO_ENABLE
typedef const uint16_t comb_keys_t[];
static PROGMEM comb_keys_t
  comb_keys_F11 = {KC_F10, KC_F1, COMBO_END}, comb_keys_F12 = {KC_F10, KC_F2, COMBO_END},
  comb_keys_F13 = {KC_F10, KC_F3, COMBO_END}, comb_keys_F14 = {KC_F10, KC_F4, COMBO_END},
  comb_keys_F15 = {KC_F10, KC_F5, COMBO_END}, comb_keys_F16 = {KC_F10, KC_F6, COMBO_END},
  comb_keys_F17 = {KC_F10, KC_F7, COMBO_END}, comb_keys_F18 = {KC_F10, KC_F8, COMBO_END},
  comb_keys_F19 = {KC_F10, KC_F9, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO( comb_keys_F11, KC_F11 ),  COMBO( comb_keys_F12, KC_F12 ),
  COMBO( comb_keys_F13, KC_F13 ),  COMBO( comb_keys_F14, KC_F14 ),
  COMBO( comb_keys_F15, KC_F15 ),  COMBO( comb_keys_F16, KC_F16 ),
  COMBO( comb_keys_F17, KC_F17 ),  COMBO( comb_keys_F18, KC_F18 ),
  COMBO( comb_keys_F19, KC_F19 ),
};
#endif // COMBO_ENABLE

uint32_t layer_state_set_user(uint32_t state)
{
  clear_mods();
  return update_tri_layer_state(state, KL_LOWER, KL_RAISE, KL_ADJUST);
}

static void
process_caps_lock(uint16_t keycode, keyrecord_t *record)
{
  bool caps_lock_off = !IS_HOST_LED_ON(USB_LED_CAPS_LOCK);
  bool shift_on = !!(get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));

  if (caps_lock_off || shift_on){
    return;
  }

  switch (keycode){
    case KC_ENTER:
    case KC_TAB:
    case KC_SPACE:
    case MT_SAS:
      dprintf("caps lock off\n");
      //register_mods(MOD_MASK_SHIFT);
      tap_code(KC_CAPS);
      //unregister_mods(MOD_MASK_SHIFT);
      break;
  }
}

static void
process_LOWER(bool is_pressed, bool is_tapped)
{
  if (is_pressed) {
    layer_on(KL_LOWER);
  }
  else {
    layer_and(~LOWER_LAYER_MASK);
    if (is_tapped) {
    }
  }
}

static void
process_RAISE(bool is_pressed, bool is_tapped)
{
  if (is_pressed) {
    layer_on(KL_RAISE);
  }
  else {
    layer_and(~RAISE_LAYER_MASK);
    if (is_tapped) {
    }
  }
}

static void
process_delete_forward_word(void)
{
  store_mods();

  register_code(KC_LCTL);
  register_code(KC_LSFT);
  tap_code(KC_RGHT);
  unregister_code(KC_LSFT);
  unregister_code(KC_LCTL);
  tap_code(KC_DEL);

  restore_mods();
}

static void
process_delete_backward_word(void)
{
  store_mods();

  register_code(KC_LCTL);
  register_code(KC_LSFT);
  tap_code(KC_LEFT);
  unregister_code(KC_LSFT);
  unregister_code(KC_LCTL);
  tap_code(KC_DEL);

  restore_mods();
}

static void
process_undo(void)
{
  store_mods();

  register_code(KC_LCTL);
  tap_code(KC_Z);
  unregister_code(KC_LCTL);

  restore_mods();
}

static void
process_cut(void)
{
  store_mods();

  register_code(KC_LCTL);
  tap_code(KC_X);
  unregister_code(KC_LCTL);

  restore_mods();
}

static void
process_copy(void)
{
  store_mods();

  register_code(KC_LCTL);
  tap_code(KC_C);
  unregister_code(KC_LCTL);

  restore_mods();
}

static void
process_paste(void)
{
  store_mods();

  register_code(KC_LCTL);
  tap_code(KC_V);
  unregister_code(KC_LCTL);

  restore_mods();
}

static void
process_redo(void)
{
  store_mods();

  register_code(KC_LCTL);
  tap_code(KC_Y);
  unregister_code(KC_LCTL);

  restore_mods();
}

static uint8_t stored_mods;
static void store_mods(void)
{
  stored_mods = get_mods();
  clear_mods();
}

static void restore_mods(void)
{
  set_mods(stored_mods);
}
