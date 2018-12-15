#include<stdio.h> 
#include<conio.h>
#include<math.h> 
  
// Power function to return value of a ^ b mod P 
long long int power(long long int a, long long int b,long long int P) 
{  
    if (b == 1) 
        return a; 
  
    else
        return (((long long int)pow(a, b)) % P); 
} 
  
//Driver program 
int main() 
{ 
    long long int P, G, x, a, y, b, ka, kb;  
      
    // Both the persons will be agreed upon the  
        // public keys G and P  
    printf("Enter the value P : ");
    scanf("%d" ,&P); // A prime number P is taken 
    printf("\nThe value of P : %lld\n", P);  
  
     printf("\nEnter the value G : ");
     scanf("%d" , &G) ;// A primitve root for P, G is taken 
    printf("\nThe value of G : %lld\n\n", G);  
  
    // Alice will choose the private key a 
    printf("\nEnter Private Key Person 1 : ")  ;
    scanf("%d", &a);  // a is the chosen private key  
    printf("\nThe private key a for Person 1 : %lld\n", a); 
    x = power(G, a, P); // gets the generated key 
      
   printf("\nEnter Private key of Person 2 : ");
   scanf("%d",&b); // b is the chosen private key 
    printf("\nThe private key b for Person 2 : %lld\n\n", b); 
    y = power(G, b, P); // gets the generated key 
  
    // Generating the secret key after the exchange 
        // of keys 
    ka = power(y, a, P); // Secret key for Alice 
    kb = power(x, b, P); // Secret key for Bob 
      
    printf("Secret key for the Person 1 is : %lld\n", ka); 
    printf("Secret Key for the Person 2 is : %lld\n", kb); 

    getch();
      
    return 0; 
} 
