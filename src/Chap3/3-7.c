// 入力された整数を、2の補数、1の補数、符号と絶対値の形式で表示する。
// 入力値を2進数にしたものを、それぞれの方法で解釈し直し、表示する。
#include <stdio.h>

#define INPUT_MAX 5
#define SIGN_AND_ABS_NEG_ZERO 0x80000000 // 符号ビットと絶対値形式の時の、-0
#define COMP_OF_1_NEG_ZERO 0xFFFFFFFF // 1の補数形式の時の、-0

// 符号付き整数の表現方法
typedef enum {
  SIGN_AND_ABS, // 符号ビットと絶対値
  COMP_OF_1,    // 1の補数
  COMP_OF_2,    // 2の補数
} SignedIntegerType;

// MSBが1か否かをチェックする
int is_negative(int x){
  return (x >> 31 & 1) == 1;
}

// 整数xを指定された符号付き整数の表現方法で画面に表示する。
void print_integer(int x, SignedIntegerType type) {
  if (is_negative(x)) {
    switch (type) {
    case SIGN_AND_ABS:
      if (x == SIGN_AND_ABS_NEG_ZERO) {
        printf("%9c-0",' ');
      }
      else {
        printf("%11d", -(x & 0x7FFFFFFF));
      }
      break;
    case COMP_OF_1:
      if (x == COMP_OF_1_NEG_ZERO) {
        printf("%9c-0",' ');
      }
      else {
        printf("%11d", -1 * ~x);
      }
      break;
    case COMP_OF_2:
      printf("%11d", -1 * ~(x-1));
      break;
    default:
      printf("ERROR");
      break;
    }
  }
  else {
    printf("%11d", x);
  }
}

int main() {
  int xs[INPUT_MAX];
  int i;

  printf("Enter %d integer number.\n", INPUT_MAX);
  for(i = 0; i < INPUT_MAX; i++){
    scanf("%d", &xs[i]);
  }

  printf("%10c |  Comp of 2 |  Comp of 1 |  Sign&Abs  |\n", ' ');
  for(i = 0; i < INPUT_MAX; i++){
    printf("0x%08X |", xs[i]);
    print_integer(xs[i], COMP_OF_2);
    printf(" |");
    print_integer(xs[i], COMP_OF_1);
    printf(" |");
    print_integer(xs[i], SIGN_AND_ABS);
    printf(" |");
    printf("\n");
  }

  return 0;
}
