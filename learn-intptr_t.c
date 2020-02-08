/* atol example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <stdarg.h>
#include <stdint.h>     /* intptr_t */
void parse_va_arg(int length, ...) {

  va_list va, vb, vc;
  va_start(va, length);
  va_start(vb, length);
  va_start(vc, length);
  char *tmp=NULL;
  long tmpl;
  intptr_t ptr;
  int i;

  puts("--Working with long directly");
  for(i = 0; i < length; ++i) {
      // long va_arg works
      tmpl = va_arg(va, long int);
      printf("%li\n", tmpl);
  }

  puts("--Working with char* and (long) casting, which causes warning in Windows");
  for(i = 0; i < length; ++i) {
      // char casting to long work, too
      tmp = va_arg(vb, char *);
      printf("%li\n", (long)tmp);
  }

  puts("--Working with intptr_t, which works across platforms");
  for(i = 0; i < length; ++i) {
      tmp = va_arg(vc, char *);
      printf("%li\n", (intptr_t)tmp);
  }
}

int main ()
{
  long int li;
  long int lid;

  puts("--First we show that atol and (long) has different effect on a char*");
  char buffer[256]="12345";
  // printf ("Enter a long number: ");
  // fgets (buffer, 256, stdin);
  li = atol(buffer);
  lid = (long)buffer;
  printf ("The value entered is %ld. Result of long casting is %ld.\n",li,lid);

  parse_va_arg(3, 234, 395, 3423);
  return 0;
}
