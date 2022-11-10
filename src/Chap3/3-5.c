// 符号付き整数の表現方法(ex. 2の補数)を判定する
#include <stdio.h>

// 2進数で表示する
void print_binary(char x)
{
  int bit;
  for(bit = 7; bit >= 0; bit--) {
    printf("%d",(x >> bit)&1);
    if(bit%4 == 0) {
      printf(" ");
    }
  }
}

// 2の補数か？
int is_complement_of_2(char x)
{
  return -x == (~x + 1);
}

// 1の補数か？
int is_complement_of_1(char x)
{
  return -x == (~x);
}

int main()
{
  char x = 25;
  printf(" %d = ", x);
  print_binary(x);
  printf("\n");

  printf("%d = ", -x);
  print_binary(-x);
  printf("\n");

  if(is_complement_of_1(x)){
    printf("Complement of 1\n");
  }
  else if(is_complement_of_2(x)){
    printf("Complement of 2\n");
  }
  else {
    printf("Other\n");
  }
  return 0;
}
