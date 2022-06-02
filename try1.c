/*#include <stdio.h>

int main() {
  int m=10;
  int *p=&m;

  printf("\n%d",m);
  printf("\n%p",&m);
  printf("\n%p",p);

  return 0;
}
*/
/*#include <stdio.h>

int main() {
  int m = 7956;  // Variable declaration
  int* ptr = &m;  // Pointer declaration

  // Reference: Output the memory address of myAge with the pointer (0x7ffe5367e044)
  printf("%p\n", ptr);

  // Dereference: Output the value of myAge with the pointer (43)
  printf("%p\n", *ptr);

  return 0;
}
*/
/*
#include <stdio.h>

int main() {
  int m = 43;  // Variable declaration
  int ptr = &m;  // Pointer declaration

  // Reference: Output the memory address of myAge with the pointer (0x7ffe5367e044)
  printf("%p\n", ptr);

  // Dereference: Output the value of myAge with the pointer (43)
  printf("%d\n", *ptr);

  return 0;
}
*/

/*#include <stdio.h>

int main()
{
  int x=5,i;
  while(i<x)
  {
  printf("\n%d",i);
  i++;
  }
  return 0;
}*/

/*#include <stdio.h>

int main() {
  int i = 0;

  while (i < 10) {

    if (i == 4) {
      continue;
    }
    printf("%d\n", i);
    i++;
  }

  return 0;
}*/
 /*  #include <stdio.h>

   int main()
  {
  char a[] = "Hello World!";
  printf("%s", a);

  return 0;
  }
*/

#include <stdio.h>

int main() {
  char greetings[] = "Hello World!";
  printf("%c", greetings[13]);

  return 0;
}
