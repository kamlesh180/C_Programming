#include<stdio.h>
int main() {
     int i,j;
     int n=5;
     
     //outer loop 
     for(i=1; i<=n; i++){
        //inner loop
        for(j=1; j<=i; j++){
            //for print binary number 

            if((i+j)%2 == 0){
                printf("1 ");
            }
            else{
                 printf("0 ");
            }
        }
         printf("\n");
     }
     return 0;
}