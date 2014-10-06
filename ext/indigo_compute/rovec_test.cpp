#include <stdio.h>
#include "rovec.h"
#include <iterator>

int main() {
  int buf[] = {1, 2, 3, 4, 5};
  rovec<int> rv(buf, 5);

  for (unsigned int i=0; i<rv.size(); i++)
    printf("%d\n", rv[i]);

  for (int x : rv)
    printf("%d\n", x);

  return 0;
}
