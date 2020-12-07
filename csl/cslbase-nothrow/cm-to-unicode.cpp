// cm-to-unicode.h                              Copyright (C) 2020 Codemist

// $Id: cm-to-unicode.cpp 5433 2020-10-15 21:09:02Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2020, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "uninames.h"

// This maps the 128 characters in the fint "cmr10" (and its immediate
// friends) to Unicode in a way that should suit use with STIXMath.ttf

int cmr_to_unicode[128] =
{   unicode_GREEK_CAPITAL_LETTER_GAMMA,
    unicode_GREEK_CAPITAL_LETTER_DELTA,
    unicode_GREEK_CAPITAL_LETTER_THETA,
    unicode_GREEK_CAPITAL_LETTER_LAMDA,
    unicode_GREEK_CAPITAL_LETTER_XI,
    unicode_GREEK_CAPITAL_LETTER_PI,
    unicode_GREEK_CAPITAL_LETTER_SIGMA,
    unicode_GREEK_CAPITAL_LETTER_UPSILON,
    unicode_GREEK_CAPITAL_LETTER_PHI,
    unicode_GREEK_CAPITAL_LETTER_PSI,
    unicode_GREEK_CAPITAL_LETTER_OMEGA,
    unicode_LATIN_SMALL_LIGATURE_FF,
    unicode_LATIN_SMALL_LIGATURE_FI,
    unicode_LATIN_SMALL_LIGATURE_FL,
    unicode_LATIN_SMALL_LIGATURE_FFI,
    unicode_LATIN_SMALL_LIGATURE_FFL,
    unicode_LATIN_SMALL_LETTER_DOTLESS_I,
    unicode_LATIN_SMALL_LETTER_DOTLESS_J,
    unicode_GRAVE_ACCENT,
    unicode_ACUTE_ACCENT,
    unicode_CARON,
    unicode_BREVE,
    unicode_MACRON,
    unicode_RING_ABOVE,
    unicode_CEDILLA,
    unicode_LATIN_SMALL_LETTER_SHARP_S,
    unicode_LATIN_SMALL_LETTER_AE,
    unicode_LATIN_SMALL_LIGATURE_OE,
    unicode_LATIN_SMALL_LETTER_O_WITH_STROKE,
    unicode_LATIN_CAPITAL_LETTER_AE,
    unicode_LATIN_CAPITAL_LIGATURE_OE,
    unicode_LATIN_CAPITAL_LETTER_O_WITH_STROKE,
    nonstandard_POLISHCROSS,   // or unicode_COMBINING_SHORT_SOLIDUS_OVERLAY?
    unicode_EXCLAMATION_MARK,
    unicode_RIGHT_DOUBLE_QUOTATION_MARK,
    unicode_NUMBER_SIGN,
    unicode_DOLLAR_SIGN,
    unicode_PERCENT_SIGN,
    unicode_AMPERSAND,
    unicode_RIGHT_SINGLE_QUOTATION_MARK,
    unicode_LEFT_PARENTHESIS,
    unicode_RIGHT_PARENTHESIS,
    unicode_ASTERISK,
    unicode_PLUS_SIGN,
    unicode_COMMA,
    unicode_HYPHEN_MINUS,
    unicode_FULL_STOP,
//  unicode_SOLIDUS,
    unicode_DIVISION_SLASH,
    unicode_DIGIT_ZERO,
    unicode_DIGIT_ONE,
    unicode_DIGIT_TWO,
    unicode_DIGIT_THREE,
    unicode_DIGIT_FOUR,
    unicode_DIGIT_FIVE,
    unicode_DIGIT_SIX,
    unicode_DIGIT_SEVEN,
    unicode_DIGIT_EIGHT,
    unicode_DIGIT_NINE,
    unicode_COLON,
    unicode_SEMICOLON,
    unicode_INVERTED_EXCLAMATION_MARK,
    unicode_EQUALS_SIGN,
    unicode_INVERTED_QUESTION_MARK,
    unicode_QUESTION_MARK,
    unicode_COMMERCIAL_AT,
    unicode_LATIN_CAPITAL_LETTER_A,
    unicode_LATIN_CAPITAL_LETTER_B,
    unicode_LATIN_CAPITAL_LETTER_C,
    unicode_LATIN_CAPITAL_LETTER_D,
    unicode_LATIN_CAPITAL_LETTER_E,
    unicode_LATIN_CAPITAL_LETTER_F,
    unicode_LATIN_CAPITAL_LETTER_G,
    unicode_LATIN_CAPITAL_LETTER_H,
    unicode_LATIN_CAPITAL_LETTER_I,
    unicode_LATIN_CAPITAL_LETTER_J,
    unicode_LATIN_CAPITAL_LETTER_K,
    unicode_LATIN_CAPITAL_LETTER_L,
    unicode_LATIN_CAPITAL_LETTER_M,
    unicode_LATIN_CAPITAL_LETTER_N,
    unicode_LATIN_CAPITAL_LETTER_O,
    unicode_LATIN_CAPITAL_LETTER_P,
    unicode_LATIN_CAPITAL_LETTER_Q,
    unicode_LATIN_CAPITAL_LETTER_R,
    unicode_LATIN_CAPITAL_LETTER_S,
    unicode_LATIN_CAPITAL_LETTER_T,
    unicode_LATIN_CAPITAL_LETTER_U,
    unicode_LATIN_CAPITAL_LETTER_V,
    unicode_LATIN_CAPITAL_LETTER_W,
    unicode_LATIN_CAPITAL_LETTER_X,
    unicode_LATIN_CAPITAL_LETTER_Y,
    unicode_LATIN_CAPITAL_LETTER_Z,
    unicode_LEFT_SQUARE_BRACKET,
    unicode_LEFT_DOUBLE_QUOTATION_MARK,
    unicode_RIGHT_SQUARE_BRACKET,
    unicode_CIRCUMFLEX_ACCENT,
    unicode_DOT_ABOVE,
    unicode_LEFT_SINGLE_QUOTATION_MARK,
    unicode_LATIN_SMALL_LETTER_A,
    unicode_LATIN_SMALL_LETTER_B,
    unicode_LATIN_SMALL_LETTER_C,
    unicode_LATIN_SMALL_LETTER_D,
    unicode_LATIN_SMALL_LETTER_E,
    unicode_LATIN_SMALL_LETTER_F,
    unicode_LATIN_SMALL_LETTER_G,
    unicode_LATIN_SMALL_LETTER_H,
    unicode_LATIN_SMALL_LETTER_I,
    unicode_LATIN_SMALL_LETTER_J,
    unicode_LATIN_SMALL_LETTER_K,
    unicode_LATIN_SMALL_LETTER_L,
    unicode_LATIN_SMALL_LETTER_M,
    unicode_LATIN_SMALL_LETTER_N,
    unicode_LATIN_SMALL_LETTER_O,
    unicode_LATIN_SMALL_LETTER_P,
    unicode_LATIN_SMALL_LETTER_Q,
    unicode_LATIN_SMALL_LETTER_R,
    unicode_LATIN_SMALL_LETTER_S,
    unicode_LATIN_SMALL_LETTER_T,
    unicode_LATIN_SMALL_LETTER_U,
    unicode_LATIN_SMALL_LETTER_V,
    unicode_LATIN_SMALL_LETTER_W,
    unicode_LATIN_SMALL_LETTER_X,
    unicode_LATIN_SMALL_LETTER_Y,
    unicode_LATIN_SMALL_LETTER_Z,
    unicode_EN_DASH,
    unicode_EM_DASH,
    unicode_DOUBLE_ACUTE_ACCENT,
    unicode_SMALL_TILDE,
    unicode_DIAERESIS
};

int cmmi_to_unicode[128] =
{   unicode_MATHEMATICAL_ITALIC_CAPITAL_GAMMA,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_DELTA,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_THETA,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_LAMDA,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_XI,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_PI,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_SIGMA,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_UPSILON,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_PHI,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_PSI,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_OMEGA,
    unicode_MATHEMATICAL_ITALIC_SMALL_ALPHA,
    unicode_MATHEMATICAL_ITALIC_SMALL_BETA,
    unicode_MATHEMATICAL_ITALIC_SMALL_GAMMA,
    unicode_MATHEMATICAL_ITALIC_SMALL_DELTA,
    unicode_MATHEMATICAL_ITALIC_EPSILON_SYMBOL,
    unicode_MATHEMATICAL_ITALIC_SMALL_ZETA,
    unicode_MATHEMATICAL_ITALIC_SMALL_ETA,
    unicode_MATHEMATICAL_ITALIC_SMALL_THETA,
    unicode_MATHEMATICAL_ITALIC_SMALL_IOTA,
    unicode_MATHEMATICAL_ITALIC_SMALL_KAPPA,
    unicode_MATHEMATICAL_ITALIC_SMALL_LAMDA,
    unicode_MATHEMATICAL_ITALIC_SMALL_MU,
    unicode_MATHEMATICAL_ITALIC_SMALL_NU,
    unicode_MATHEMATICAL_ITALIC_SMALL_XI,
    unicode_MATHEMATICAL_ITALIC_SMALL_PI,
    unicode_MATHEMATICAL_ITALIC_SMALL_RHO,
    unicode_MATHEMATICAL_ITALIC_SMALL_SIGMA,
    unicode_MATHEMATICAL_ITALIC_SMALL_TAU,
    unicode_MATHEMATICAL_ITALIC_SMALL_UPSILON,
    unicode_MATHEMATICAL_ITALIC_SMALL_PHI,
    unicode_MATHEMATICAL_ITALIC_SMALL_CHI,
    unicode_MATHEMATICAL_ITALIC_SMALL_PSI,
    unicode_MATHEMATICAL_ITALIC_SMALL_OMEGA,
    unicode_MATHEMATICAL_ITALIC_SMALL_EPSILON,
    unicode_MATHEMATICAL_ITALIC_THETA_SYMBOL,
    unicode_MATHEMATICAL_ITALIC_PI_SYMBOL,
    unicode_MATHEMATICAL_ITALIC_RHO_SYMBOL,
    unicode_MATHEMATICAL_ITALIC_SMALL_FINAL_SIGMA,
    unicode_MATHEMATICAL_ITALIC_PHI_SYMBOL,
    unicode_LEFTWARDS_HARPOON_WITH_BARB_UPWARDS,
    unicode_LEFTWARDS_HARPOON_WITH_BARB_DOWNWARDS,
    unicode_RIGHTWARDS_HARPOON_WITH_BARB_UPWARDS,
    unicode_RIGHTWARDS_HARPOON_WITH_BARB_DOWNWARDS,
    nonstandard_ARROW_HOOK_LEFT,
    nonstandard_ARROW_HOOK_RIGHT,
    unicode_CONTAINS_AS_NORMAL_SUBGROUP,
    unicode_NORMAL_SUBGROUP_OF,
    nonstandard_OLD_STYLE_DIGIT_ZERO,
    nonstandard_OLD_STYLE_DIGIT_ONE,
    nonstandard_OLD_STYLE_DIGIT_TWO,
    nonstandard_OLD_STYLE_DIGIT_THREE,
    nonstandard_OLD_STYLE_DIGIT_FOUR,
    nonstandard_OLD_STYLE_DIGIT_FIVE,
    nonstandard_OLD_STYLE_DIGIT_SIX,
    nonstandard_OLD_STYLE_DIGIT_SEVEN,
    nonstandard_OLD_STYLE_DIGIT_EIGHT,
    nonstandard_OLD_STYLE_DIGIT_NINE,
    unicode_FULL_STOP,
    unicode_COMMA,
    unicode_LESS_THAN_SIGN,
    unicode_SOLIDUS,
    unicode_GREATER_THAN_SIGN,
    unicode_STAR_OPERATOR,
    unicode_PARTIAL_DIFFERENTIAL,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_A,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_B,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_C,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_D,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_E,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_F,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_G,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_H,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_I,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_J,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_K,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_L,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_M,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_N,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_O,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_P,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_Q,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_R,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_S,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_T,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_U,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_V,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_W,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_X,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_Y,
    unicode_MATHEMATICAL_ITALIC_CAPITAL_Z,
    unicode_MUSIC_FLAT_SIGN,
    unicode_MUSIC_NATURAL_SIGN,
    unicode_MUSIC_SHARP_SIGN,
    unicode_SMILE,
    unicode_FROWN,
    unicode_SCRIPT_SMALL_L,
    unicode_MATHEMATICAL_ITALIC_SMALL_A,
    unicode_MATHEMATICAL_ITALIC_SMALL_B,
    unicode_MATHEMATICAL_ITALIC_SMALL_C,
    unicode_MATHEMATICAL_ITALIC_SMALL_D,
    unicode_MATHEMATICAL_ITALIC_SMALL_E,
    unicode_MATHEMATICAL_ITALIC_SMALL_F,
    unicode_MATHEMATICAL_ITALIC_SMALL_G,
    unicode_PLANCK_CONSTANT,
    unicode_MATHEMATICAL_ITALIC_SMALL_I,
    unicode_MATHEMATICAL_ITALIC_SMALL_J,
    unicode_MATHEMATICAL_ITALIC_SMALL_K,
    unicode_MATHEMATICAL_ITALIC_SMALL_L,
    unicode_MATHEMATICAL_ITALIC_SMALL_M,
    unicode_MATHEMATICAL_ITALIC_SMALL_N,
    unicode_MATHEMATICAL_ITALIC_SMALL_O,
    unicode_MATHEMATICAL_ITALIC_SMALL_P,
    unicode_MATHEMATICAL_ITALIC_SMALL_Q,
    unicode_MATHEMATICAL_ITALIC_SMALL_R,
    unicode_MATHEMATICAL_ITALIC_SMALL_S,
    unicode_MATHEMATICAL_ITALIC_SMALL_T,
    unicode_MATHEMATICAL_ITALIC_SMALL_U,
    unicode_MATHEMATICAL_ITALIC_SMALL_V,
    unicode_MATHEMATICAL_ITALIC_SMALL_W,
    unicode_MATHEMATICAL_ITALIC_SMALL_X,
    unicode_MATHEMATICAL_ITALIC_SMALL_Y,
    unicode_MATHEMATICAL_ITALIC_SMALL_Z,
    unicode_MATHEMATICAL_ITALIC_SMALL_DOTLESS_I,
    unicode_MATHEMATICAL_ITALIC_SMALL_DOTLESS_J,
    unicode_SCRIPT_CAPITAL_P,
    unicode_COMBINING_RIGHT_ARROW_ABOVE,
    unicode_CHARACTER_TIE
};

int cmsy_to_unicode[128] =
{   unicode_MINUS_SIGN,
    unicode_MIDDLE_DOT,
    unicode_MULTIPLICATION_SIGN,
    unicode_ASTERISK_OPERATOR,
    unicode_DIVISION_SIGN,
    unicode_DIAMOND_OPERATOR,
    unicode_PLUS_MINUS_SIGN,
    unicode_MINUS_OR_PLUS_SIGN,
    unicode_CIRCLED_PLUS,
    unicode_CIRCLED_MINUS,
    unicode_CIRCLED_TIMES,
    unicode_CIRCLED_DIVISION_SLASH,
    unicode_CIRCLED_DOT_OPERATOR,
    unicode_COMBINING_ENCLOSING_CIRCLE,
    unicode_RING_OPERATOR,
    unicode_BULLET_OPERATOR,
    unicode_EQUIVALENT_TO,
    unicode_IDENTICAL_TO,
    unicode_SUBSET_OF_OR_EQUAL_TO,
    unicode_SUPERSET_OF_OR_EQUAL_TO,
    unicode_LESS_THAN_OR_EQUAL_TO,
    unicode_GREATER_THAN_OR_EQUAL_TO,
    unicode_PRECEDES_OR_EQUAL_TO,
    unicode_SUCCEEDS_OR_EQUAL_TO,
    unicode_TILDE_OPERATOR,
    unicode_APPROXIMATELY_EQUAL_TO,
    unicode_SUBSET_OF,
    unicode_SUPERSET_OF,
    unicode_MUCH_LESS_THAN,
    unicode_MUCH_GREATER_THAN,
    unicode_PRECEDES,
    unicode_SUCCEEDS,
    unicode_LEFTWARDS_ARROW,
    unicode_RIGHTWARDS_ARROW,
    unicode_UPWARDS_ARROW,
    unicode_DOWNWARDS_ARROW,
    unicode_LEFT_RIGHT_ARROW,
    unicode_NORTH_EAST_ARROW,
    unicode_SOUTH_EAST_ARROW,
    unicode_ASYMPTOTICALLY_EQUAL_TO,
    unicode_LEFTWARDS_DOUBLE_ARROW,
    unicode_RIGHTWARDS_DOUBLE_ARROW,
    unicode_UPWARDS_DOUBLE_ARROW,
    unicode_DOWNWARDS_DOUBLE_ARROW,
    unicode_LEFT_RIGHT_DOUBLE_ARROW,
    unicode_NORTH_WEST_ARROW,
    unicode_SOUTH_WEST_ARROW,
    unicode_PROPORTIONAL_TO,
    unicode_MODIFIER_LETTER_PRIME,
    unicode_INFINITY,
    unicode_ELEMENT_OF,
    unicode_CONTAINS_AS_MEMBER,
    unicode_INCREMENT,
    unicode_NABLA,
    unicode_SOLIDUS,
    nonstandard_MAPSTO,
    unicode_FOR_ALL,
    unicode_THERE_EXISTS,
    unicode_NOT_SIGN,
    unicode_EMPTY_SET,
    unicode_BLACK_LETTER_CAPITAL_R,
    unicode_BLACK_LETTER_CAPITAL_I,
    unicode_DOWN_TACK,
    unicode_UP_TACK,
    unicode_ALEF_SYMBOL,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_A,
    unicode_SCRIPT_CAPITAL_B,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_C,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_D,
    unicode_SCRIPT_CAPITAL_E,
    unicode_SCRIPT_CAPITAL_F,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_G,
    unicode_SCRIPT_CAPITAL_H,
    unicode_SCRIPT_CAPITAL_I,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_J,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_K,
    unicode_SCRIPT_CAPITAL_L,
    unicode_SCRIPT_CAPITAL_M,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_N,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_O,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_P,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_Q,
    unicode_SCRIPT_CAPITAL_R,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_S,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_T,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_U,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_V,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_W,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_X,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_Y,
    unicode_MATHEMATICAL_SCRIPT_CAPITAL_Z,
    unicode_UNION,
    unicode_INTERSECTION,
    unicode_MULTISET_UNION,
    unicode_LOGICAL_AND,
    unicode_LOGICAL_OR,
    unicode_RIGHT_TACK,
    unicode_LEFT_TACK,
    unicode_LEFT_FLOOR,
    unicode_RIGHT_FLOOR,
    unicode_LEFT_CEILING,
    unicode_RIGHT_CEILING,
    unicode_LEFT_CURLY_BRACKET,
    unicode_RIGHT_CURLY_BRACKET,
    unicode_LEFT_ANGLE_BRACKET,
    unicode_RIGHT_ANGLE_BRACKET,
    unicode_VERTICAL_LINE,
    unicode_DOUBLE_VERTICAL_LINE,
    unicode_UP_DOWN_ARROW,
    unicode_UP_DOWN_DOUBLE_ARROW,
    unicode_REVERSE_SOLIDUS,
    unicode_WREATH_PRODUCT,
    nonstandard_SQUARE_ROOT_var,
    unicode_N_ARY_COPRODUCT,
    unicode_NABLA,
    unicode_INTEGRAL,
    unicode_SQUARE_CUP,
    unicode_SQUARE_CAP,
    unicode_SQUARE_IMAGE_OF_OR_EQUAL_TO,
    unicode_SQUARE_ORIGINAL_OF_OR_EQUAL_TO,
    unicode_SECTION_SIGN,
    unicode_DAGGER,
    unicode_DOUBLE_DAGGER,
    unicode_PILCROW_SIGN,
    unicode_BLACK_CLUB_SUIT,
    unicode_WHITE_DIAMOND_SUIT,
    unicode_WHITE_HEART_SUIT,
    unicode_BLACK_SPADE_SUIT
};


int cmex_to_unicode[128] =
{   // not done yet!
};

// end of cm-to-unicode.cpp
