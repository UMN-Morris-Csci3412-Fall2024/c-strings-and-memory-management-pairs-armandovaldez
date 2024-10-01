#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *x = disemvowel((char*) "");
  ASSERT_STREQ("", x);
  free(x); 
}

TEST(Disemvowel, HandleNoVowels) {
  char *x = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", x);
  free(x);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *x = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", x);
  
  free(x); 
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *x = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", x);
  free(x); 
}

TEST(Disemvowel, HandlePunctuation) {
  char *x = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", x);\

  free(x); 
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char *x= disemvowel(str);
  ASSERT_STREQ("xyz", x);

  free(x); 
  free(str); 

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}