#include <stdio.h>
#include <stdlib.h>

int func2(int a, int b) // Compare a and b
{
	__asm__ __volatile__
  	(
		"movl 16(%ebp),%edx \n\t" // edx = a
		"movl 24(%ebp),%eax \n\t" // eax = b
		"cmpl %eax,%edx \n\t" // a : b
		"jle L0 \n\t" // a <= b 이면 L0로 점프 
		"movl $1,%eax \n\t" // eax = 1  
		"jmp L1 \n\t" // L1로 무조건 점프 
	"L0: \n\t" // a<=b 일 때 
		"movl $0,%eax \n\t" // eax = 0
	"L1: \n\t" // 위의 조건에서 걸리지 않으면 아무 것도 안함. 
	); // a가 b보다 작거나 같으면  0 리턴, 아니면 1 리턴하는 함수 
}

void func1(int *a, int *b) // Swap a and b
{
	__asm__ __volatile__
  	(
		"movl 24(%ebp),%ecx \n\t" // ecx = b(주소)
		"movl 16(%ebp),%edx \n\t" // edx = a(주소)
		"movl (%ecx),%eax \n\t" // eax = *b (b가 가리키는 곳에 있는 값) 
		"movl (%edx),%ebx \n\t" // ebx = *a (a가 가리키는 곳에 있는 값)
		"movl %eax,(%edx) \n\t" // *a = *b
		"movl %ebx,(%ecx) \n\t" // *b = *a
	); // 두 수를 스왑하는 함수 
}

int main(int argc, char *argv[]) {
	 
	int arr[] = { 1, 9, 5, 6, 3, 2, 9, 4, 1, 3 };

	// Sort arr
	// YOU MUST USE func1, func2 

	// Output MUST be
	// 1 1 2 3 3 4 5 6 9 9
	
	// Fill your own codes from here
	
	for(int i=0; i<9; i++){
        for(int j=i+1; j<10; j++){
            if(func2(arr[j], arr[i])==0)
                func1(&arr[j], &arr[i]);    
        }
    }

    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
	
	return 0;
}