#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, sum=0;
    printf("Enter size: ");
    scanf("%d", &n);
    int *arr = (int *)calloc(5, sizeof(int));
    printf("Enter elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
        sum+=arr[i];
    }
    free(arr);
    printf("sum = %d", sum);
return 0;
}

#include <stdio.h>

int main() {
    int *arr = (int*)calloc(5, sizeof(int));
    printf("Enter elements: \n");
    for(int i=0; i<5; i++){
        scanf("%d", arr+i);
    }
    for(int i=0; i<5; i++){
        printf("%d\t", *(arr+i));
    }
    free(arr);
return 0;
}