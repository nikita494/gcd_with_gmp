#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void fact(long long q){
    printf("Num factors: ");
    long long divisor = 2;
    while (q != 1){
        while (q % divisor == 0) {
            printf("%llu ", divisor);
            q /= divisor;
        }
        divisor += 1;
    }
    printf("\n");

}


long long main(){
    long long a;
    printf("Enter your number: ");
    scanf("%llu", &a);
    fact(a);
}
