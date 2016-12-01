#include <stdio.h>

int GetSize(long data[])
{
  return sizeof(data);
}

int main(int argc, char* argv[]){
  long data[] = {1,2,3,4,5};
  int size1 = sizeof(data);

  int *data2 = data;
  int size2 = sizeof(data2);
  int size3 = GetSize(data);

  printf("size1 = %d, size2 = %d, size3 = %d \n", size1, size2, size3 );
}
