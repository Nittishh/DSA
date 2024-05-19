#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
    }
    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);
    int start=0,end=n-1, mid, found=0;

    while(start<=end){
    mid = (start+end)/2;
    if(arr[mid]==target){
        found = 1;
        break;
    }
    else if(target < arr[mid]){
        end = mid - 1;
    }
    else{
        start = mid + 1;
    }
    }
    if(found==1){
        printf("Found at index %d", mid);
    }
    else{
        printf("-1");
    }
return 0;
}