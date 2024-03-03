# include <stdio.h>
# include <math.h>
int oct_to_dec(int num){
    int res=0, pos=0;
    while(num>0){
    res += num%10 * pow(8,pos);
    num /= 10;
    pos++;
    }
    return res;
}
int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int c_num = oct_to_dec(num);
    printf("Converted num: %d", c_num);
    return 0;
}