#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
movl 12(%ebp), %edx   ==    stores y into edx
subl 16(%ebp), %edx   ==    y-z into edx
movl %edx, %eax       ==    stores y-z into eax
imull 8(%ebp), %edx   ==    x*(y-z) into edx
sall $31, %eax        ==    shift eax <<31
sarl $31, %eax        ==    shift eax >>31
xorl %edx, %eax       ==    edx^eax
*/

int decode(int x, int y, int z)     // x =ebp8, y =ebp12, z =ebp16
{
  int result = y-z;       //subl 16(%ebp), %edx
  int store = result;     //movl %edx, %eax
  result *= x;            //imull 8(%ebp), %edx
  store = store <<31;     //sall $31, %eax
  store =store >>31;      //sarl $31, %eax
  result = result^store;  //xorl %edx, %eax

  return result;
}

int main(){
	printf("%d\n",decode(1,2,4));
  printf("%d\n",decode(-4, -8, -12));
}
