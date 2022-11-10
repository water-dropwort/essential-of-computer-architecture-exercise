// 最大の整数に1を足し、2の補数表現を使っているかを確かめる
#include <stdio.h>

int main() {
  const char c_max = 127;
  const char c_min = -128;
  if ((char)(c_max + 1) == c_min) {
    printf("Complement of 2");
  }
  else {
    printf("Other");
  }
  return 0;
}
