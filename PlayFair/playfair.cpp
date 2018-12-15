#include<iostream>
#include<string.h>

using namespace std ;

int main(){
	
	char array[5][5];
	int alpha[26]={0} , counter= 0 ;
	char key[10] , msg[20] , enc[20];
	char p1,p2 ;
	int count = 0, flag =0;
	cout<<"Enter the Key : " ;
	
	gets(key) ;
	
    int i=0 ,j =0 ,a1,a2,b1,b2;
    int len = strlen(key) ;
    char s ='a' ;	
    while(i<5){
    	
    	while(j<5){
    		
    		if(counter<len){
			
    		if(alpha[key[counter] - 97] == 0){
    			alpha[key[counter]-97] =1;
    			array[i][j] = key[counter];
    			j++ ;
			}
    		counter++ ;
    	 }
      
	   else{
           if(alpha[s-97]==0){
           	 array[i][j]= s ;
           	 alpha[s-97] = 1;
           	 j++ ;
		   }       	
		   s++ ;
	   	
	   }	 
    		
	}
	i++ ;
	j=0;
    	
	}
	
	for(int k =0 ; k<5; k++){
		for(int m = 0; m<5; m++){
			
			cout<<array[k][m]<<"  ";
		}
		cout<<"\n" ;
	}
	
	
	cout<<"Enter the message : " ;
	gets(msg) ;
	
	int l = strlen(msg),sc=0;
	cout<<l;
 
  while(count<l){
     p1 = msg[count];   
     count++ ;
     if(p1==' '){
     	
     	sc++;
     	p1 = msg[count];
     	count++;
	 }
	 
     p2 = msg[count] ;
     count++;
     if(p2==' '){
	 
	 sc++;
	 p2 = msg[count];
	 count++ ;
	 }
     
	for(int i=0 ; i<5 ; i++){
		for(int j=0 ;j<5 ; j++){
	      		
		 	if(array[i][j] == p1){
		 		a1=i;
			    b1 = j;
			 }
			
		}
	}
	   if(l%2!=0 && count >=l){
	   	p2 = 'a';
	   }
	   
		for(int i=0 ; i<5 ; i++){
		for(int j=0 ;j<5 ; j++){
	      		
		 	if(array[i][j] == p2){
		 		a2=i;
			    b2 = j;
			 }
			
		}
	}


	
	
	if(a1 == a2){
		if(b1>b2){
			enc[flag] = array[a1][b1];
			flag++ ;
			enc[flag] = array[a1][(b1+1)%5] ;
			flag++ ;
		}
		
		else if(b2>b1){
			enc[flag] = array[a1][b2];
			flag++ ;
			enc[flag] = array[a1][(b2+1)%5] ;
			flag++ ;
		}
	}
	
	
	else if(b1 == b2){
			if(a1>a2){
			enc[flag] = array[a1][b1];
			flag++ ;
			enc[flag] = array[(a1+1)%5][b1] ;
			flag++ ;
		}
		
		else if(a2>a1){
			enc[flag] = array[a1][b2];
			flag++ ;
			enc[flag] = array[a1][(b2+1)%5] ;
			flag++ ;
		}
		
		
	}
	

 else {
 	
 	enc[flag] = array[a2][b1];
 	flag++ ;
 	enc[flag]  = array[a1][b2];
 	flag++ ;
 }
 
 
 
	
  	
 }
 
 cout<<"\nEncrypted message is : ";
 if(l%2==1){
 	l++;
 }
 	l-=sc;
 	for(int i=0 ; i<l ; i++){
 		cout<<enc[i];
	 }
 
 
	return 0;
}
