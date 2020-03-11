/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_DELETE, KC_ESC, KC_F11,
        TO(0), KC_UP, TO(1),
        KC_LEFT, KC_DOWN, KC_RIGHT	
    ),
	[1] = LAYOUT(
        KC_SELECT, KC_DELETE, KC_MPLY,
        TO(0), KC_MUTE, TO(1),
        KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD	
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
	if (biton32(layer_state) == 0) {
		if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDOWN);
        }
	}else if (biton32(layer_state) == 1) {	
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
	}
}
