#include <cs50.h>
#include <stdio.h>
#include <math.h>

int checkSum(long);
void checkType(long);

int main(void){
    long n;
    do{
        n= get_long("Card number: ");
    }while(n<=0);
    int x=checkSum(n);
    if(x==1){
        checkType(n);
    }
    else{
        printf("INVALID\n");
    }
}
int checkSum(long n){
    long sum=0;
    long sum2=0;
    for(int i =1;i<16;i+=2){
        long val=((((n%(long)pow(10,i+1))-(n%(long)pow(10,i)))/pow(10,i))*2);
        if(val>=10){
           long digit=((val%(long)(pow(10,2))-(val%10))/10);
           val=digit+(val%10);
        }
        sum2+=val;
    }
    for(int j=0;j<16;j+=2){
        sum+=(((n%(long)pow(10,j+1))-(n%(long)pow(10,j)))/pow(10,j));
    }
    if((sum+sum2)%10==0){
        return 1;
    }
    else{
        return 0;
    }
}

void checkType(long n){
    //printf("%li     %li\n",);
    bool amexCon1=n>=(long)pow(10,14)&& n<(long)pow(10,15);
    bool amexCon2=((n-n%(long)pow(10,13))/pow(10,13)==37)||((n-n%(long)pow(10,13))/pow(10,13)==34);
    bool masCon1=n>=(long)pow(10,15)&& n<(long)pow(10,16);
    bool masCon2=((n-n%(long)pow(10,14))/pow(10,14)>50)&&((n-n%(long)pow(10,14))/pow(10,14)<56);
    bool visaCon1=n>=(long)pow(10,12)&& n<(long)pow(10,13)&&(n-n%(long)pow(10,12))/pow(10,12)==4;
    bool visaCon2=n>=(long)pow(10,15)&& n<(long)pow(10,16)&&(n-n%(long)pow(10,15))/pow(10,15)==4;

    if(amexCon1&&amexCon2){
        printf("AMEX\n");
    }
    else if(masCon1&& masCon2){
        printf("%f   %d\n",(n-n%(long)pow(10,14))/pow(10,14),masCon2);
        printf("MASTERCARD\n");
    }
    else if(visaCon1||visaCon2){
        printf("VISA\n");
    }


}
