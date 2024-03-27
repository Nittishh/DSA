#include <stdio.h>
struct Student{
    int rollNumber;
    char name[30];
    float marks;
};
int main() {
   struct Student s1,s2;

   printf("Enter Roll Number: ");
   scanf("%d", &s1.rollNumber);

   printf("Enter the name: ");
   fflush(stdin);
   gets(s1.name);

   printf("Enter marks: ");
   scanf("%f", &s1.marks);


   printf("Enter Roll Number: ");
   scanf("%d", &s2.rollNumber);

   printf("Enter the name: ");
   fflush(stdin);
   gets(s2.name);

   printf("Enter marks: ");
   scanf("%f", &s2.marks);

   printf("Roll number = %d\n", s1.rollNumber);
   printf("Name = %s\n", s1.name);
   printf("Marks = %.2f\n\n", s1.marks);

   printf("Roll number = %d\n", s2.rollNumber);
   printf("Name = %s\n", s2.name);
   printf("Marks = %.2f\n", s2.marks);
return 0;
}