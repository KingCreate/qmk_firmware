#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#undef TAPPING_TERM
#undef DEBOUNCE
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 250
#define DEBOUNCE 12
