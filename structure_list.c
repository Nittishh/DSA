#include <stdio.h>
struct Student{
    int rollNumber;
    char name[30];
    float marks;
};

int main(){
    struct Student list[5];
    for(int i=0; i<5; i++){
        printf("Enter roll Number: ");
        scanf("%d", &list[i].rollNumber);
        printf("Enter name: ");
        fflush(stdin);
        gets(list[i].name);
        printf("Enter marks: ");
        scanf("%f", &list[i].marks);
    }
    printf("\n%15s %15s %15s\n", "Roll Number", "Name", "Marks");
    for(int i=0; i<5; i++){
        printf("%15d %15s %15f\n", list[i].rollNumber, list[i].name, list[i].marks);
    }
    return 0;
}