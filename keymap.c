#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum keymap_layer {
  KL_QWERTY,
  KL_LOWER,
  KL_RAISE,
  KL_ADJUST,
  KL_SCROLL,
};

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

// Fillers to make layering more clear
#define MO_LOWER  MO(KL_LOWER)
#define MO_RAISE  MO(KL_RAISE)
#define M_SAS     MT(MOD_LSFT, KC_SPACE)
#define C_TOP     C(KC_HOME)   // move to top
#define C_BTTM    C(KC_END)    // move to bottom
#define C_MBW     C(KC_LEFT)   // move to backward-word
#define C_MFW     C(KC_RGHT)   // move to forward-word
#define M_DFW     DELETE_FORWARD_WORD
#define M_DBW     DELETE_BACKWARD_WORD
#define PREV      A(KC_LEFT)    // previous location
#define NEXT      A(KC_RIGHT)   // next location
#define SCRL_UP   C(KC_UP)      // scroll line up
#define SCRL_DN   C(KC_DOWN)    // scroll line down
#define SCRL_PU   A(KC_PGUP)    // scroll page up
#define SCRL_PD   A(KC_PGDOWN)  // scroll page down
#define HYPR_F    HYPR(KC_F)
#ifdef TAP_DANCE_ENABLE
  #define TD_SLCT   TD(TC_SELECT)
#else
  #define TD_SLCT   XXXXXXX
#endif
#define SR(n)     (SAFE_RANGE+n)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [KL_QWERTY] = LAYOUT(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_GRV,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, MO_LOWER,  M_SAS,  KC_SPC,  KC_SPC,   M_SAS,MO_RAISE, KC_RALT, KC_RGUI
  ),

  [KL_LOWER] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    KC_CAPS,  KC_ESC,   C_TOP,  C_BTTM, XXXXXXX, XXXXXXX,                      REDO, TD_SLCT, KC_HOME,  KC_END, XXXXXXX, _______,
    _______, KC_PGUP,   KC_UP, KC_DOWN, KC_PGDN,  KC_DEL,                   KC_BSPC,   C_MBW, KC_LEFT, KC_RGHT,   C_MFW, _______,
    _______,    UNDO,     CUT,    COPY,   PASTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT,   M_DBW,   M_DFW, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [KL_RAISE] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,    KC_F, XXXXXXX,                   XXXXXXX,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [KL_ADJUST] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    _______,   RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC,
    _______, _______, _______,   AU_ON,  AU_OFF, AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______,
    QWERTY,  COLEMAK,  DVORAK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [KL_SCROLL] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    _______,   RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC,
    _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______,
    _______, COLEMAK,  DVORAK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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
static void process_delete_forward_word(void);
static void process_delete_backward_word(void);
static void process_undo(void);
static void process_cut(void);
static void process_copy(void);
static void process_paste(void);
static void process_redo(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  process_caps_lock(keycode, record);

  dprintf("process_record_user: %d\n", keycode);
  switch (keycode) {

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
#define KC_F0                 KC_F10
#define COMB_KEYS_Fn(n_, _n)  comb_keys_F##n_##_n = { KC_F##n_, KC_F##_n, COMBO_END }
#define COMBO_Fn(n_, _n)      COMBO(comb_keys_F##n_##_n, KC_F##n_##_n)
typedef const uint16_t comb_keys_t[];
static PROGMEM comb_keys_t
  COMB_KEYS_Fn(1, 1), COMB_KEYS_Fn(1, 2), COMB_KEYS_Fn(1, 3), COMB_KEYS_Fn(1, 4),
  COMB_KEYS_Fn(1, 5), COMB_KEYS_Fn(1, 6), COMB_KEYS_Fn(1, 7), COMB_KEYS_Fn(1, 8),
  COMB_KEYS_Fn(1, 9), COMB_KEYS_Fn(2, 0), COMB_KEYS_Fn(2, 1), COMB_KEYS_Fn(2, 2),
  COMB_KEYS_Fn(2, 3), COMB_KEYS_Fn(2, 4);
combo_t key_combos[COMBO_COUNT] = {
  COMBO_Fn(1, 1), COMBO_Fn(1, 2), COMBO_Fn(1, 3), COMBO_Fn(1, 4),
  COMBO_Fn(1, 5), COMBO_Fn(1, 6), COMBO_Fn(1, 7), COMBO_Fn(1, 8),
  COMBO_Fn(1, 9), COMBO_Fn(2, 0), COMBO_Fn(2, 1), COMBO_Fn(2, 2),
  COMBO_Fn(2, 3), COMBO_Fn(2, 4),
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
    case M_SAS:
      dprintf("caps lock off\n");
      //register_mods(MOD_MASK_SHIFT);
      tap_code(KC_CAPS);
      //unregister_mods(MOD_MASK_SHIFT);
      break;
  }
}

static void
process_delete_forward_word(void)
{
  uint8_t mods = get_mods();
  clear_mods();

  register_code(KC_LCTL);
  register_code(KC_LSFT);
  tap_code(KC_RGHT);
  unregister_code(KC_LSFT);
  unregister_code(KC_LCTL);
  tap_code(KC_DEL);

  set_mods(mods);
}

static void
process_delete_backward_word(void)
{
  uint8_t mods = get_mods();
  clear_mods();

  register_code(KC_LCTL);
  register_code(KC_LSFT);
  tap_code(KC_LEFT);
  unregister_code(KC_LSFT);
  unregister_code(KC_LCTL);
  tap_code(KC_DEL);

  set_mods(mods);
}

static void
process_undo(void)
{
  uint8_t mods = get_mods();
  clear_mods();

  register_code(KC_LCTL);
  tap_code(KC_Z);
  unregister_code(KC_LCTL);

  set_mods(mods);
}

static void
process_cut(void)
{
  uint8_t mods = get_mods();
  clear_mods();

  register_code(KC_LCTL);
  tap_code(KC_X);
  unregister_code(KC_LCTL);

  set_mods(mods);
}

static void
process_copy(void)
{
  uint8_t mods = get_mods();
  clear_mods();

  register_code(KC_LCTL);
  tap_code(KC_C);
  unregister_code(KC_LCTL);

  set_mods(mods);
}

static void
process_paste(void)
{
  uint8_t mods = get_mods();
  clear_mods();

  register_code(KC_LCTL);
  tap_code(KC_V);
  unregister_code(KC_LCTL);

  set_mods(mods);
}

static void
process_redo(void)
{
  uint8_t mods = get_mods();
  clear_mods();

  register_code(KC_LCTL);
  tap_code(KC_Y);
  unregister_code(KC_LCTL);

  set_mods(mods);
}
