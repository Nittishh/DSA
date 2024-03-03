# include <stdio.h>
# include <math.h>

int dectoOct(int num){
    int res=0, pos=1;
    while(num>0){
        res += num%8 * pos;
        num/=8;
        pos*=10;
    }
    return res;
}

int main() {
    int num;
    printf("Enter the num: ");
    scanf("%d", &num);

    printf("Converted number: %d", dectoOct(num));
return 0;
}