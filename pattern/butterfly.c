#include<stdio.h>
int main() {
   int i,j,n=4;
   //outer loop 
   for(i=1; i<=n; i++){
    //star print
    for(j=1; j<=n; j++){
        printf("*");
    } 
    // for spach
    for(j=1; j<= 2*(n-i); j++){
        printf(" ");
    } 
    //star print
    for(j=1; j<=i; j++){
        printf("*");
    }
    printf("\n");
   }
//second half outer loop
for(i=n; i>=1; i--){
    //star print
    for(j=1; j<=n; j++){
        printf("*");
    }
    // for spach
    for(j=1; j<= 2*(n-i); j++){
        printf(" ");
    } 
    //star print
    for(j=1; j<=i; j++){
        printf("*");
    }
    printf("\n");
}
return 0;
}