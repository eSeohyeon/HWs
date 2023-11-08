#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LEN 10000

void swap(int *a, int *b);
double selection_sort(int list[], int n);
double bubble_sort(int list[], int n);
double insertion_sort(int list[], int n);

int main(){

    int list_selection[LEN], list_bubble[LEN], list_insertion[LEN];
    double time_selection, time_bubble, time_insertion;

    for(int k=0; k<100; k++){

        for(int i=0; i<LEN; i++){ // 랜덤으로 크기 LEN인 리스트 3개 생성
        int x;
        x=rand()%1000000;
        list_selection[i]=x;
        list_bubble[i]=x;
        list_insertion[i]=x;
    }

    time_selection=selection_sort(list_selection, LEN);
    time_bubble=bubble_sort(list_bubble, LEN);
    time_insertion=insertion_sort(list_insertion, LEN);

    
    printf("<Elapsed Time>\n\n");
    printf("Selection Sort: %lf   Bubble Sort: %lf  Insertion Sort: %lf\n\n\n", time_selection, time_bubble, time_insertion);
    }

    return 0;
}

double selection_sort(int list[], int n){ // 선택 정렬
    int i, j, min_idx;

    clock_t start=clock(); // 측정 시작

    for(i=0; i<n-1; i++){
        min_idx=i;
        for(j=i+1; j<n; j++){
            if(list[j]<list[min_idx])
                min_idx=j;
        }
        if(min_idx!=i) // i가 제일 작을 때 말고
            swap(&list[min_idx], &list[i]);
    }

    clock_t end=clock(); // 측정 끝

    return ((double)(end-start))/CLOCKS_PER_SEC; // 소요 시간 리턴
}


double bubble_sort(int list[], int n){ // 버블 정렬
    int i, j, swapped;

    clock_t start=clock(); // 측정 시작

    for(i=0; i<n-1; i++){
        swapped=0; // false
        for(j=0; j<n-i-1; j++){
            if(list[j]<list[j+1]){
                swap(&list[j], &list[j+1]);
                swapped=1; // true
            }
        }
        if(swapped==0)
            break;
    }

    clock_t end=clock(); // 측정 끝

    return ((double)(end-start))/CLOCKS_PER_SEC; // 소요 시간 리턴
}

double insertion_sort(int list[], int n){ // 삽입 정렬
    int i, j, key;

    clock_t start=clock(); // 측정 시작

    for(i=1; i<n; i++){
        key=list[i];
        j=i-1;
        while((j>=0)&&(list[j]>key)){
            list[j+1]=list[j];
            j=j-1;
        }
        list[j+1]=key;
    }

    clock_t end=clock(); // 측정 끝

    return ((double)(end-start))/CLOCKS_PER_SEC; // 소요 시간 리턴
}
 


void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}