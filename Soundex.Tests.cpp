#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 generateSiundex("BHF",soundex);
 generateSiundex("BAF",soundex);
 generateSiundex("L321",soundex);
 // ASSERT_EQ(soundex,"A200");
}
