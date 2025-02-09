#include <stdio.h>
#define N 5
//Переписать из массива А в массив В те элементы массива А, индексы которых
//совпадают со значениями
int main()
{
int a[N];
int b[N];
int i;
int m = 4;
for (i = 0; i < N; i++)
{
printf("a[%d] = ", i);
scanf_s("%d", &a[i]);
}
__asm
{
mov esi, 0//номер элемента
mov ebx, 0
F:mov eax, a[esi * 4]
cmp eax, esi
je L1
jne L2
L1 :
mov eax, a[esi * 4]
mov b[esi * 4], eax
jmp go
L2 : mov b[esi * 4], 0
go: inc esi
cmp esi, N
je L3
jne F
L3 : nop
}
for (i = 0; i < N; i++)
{
printf("%d", b[i]);
}
return 0;
}
