
//WELCOME MOHAMMAD ANAS

// Lets Code..

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std ;

char input[100],output[100],key[100];
int  inputNo[100], outputNo[100], keyNo[100];
int  len;


void takeInput(){
    
    takeAgain:                        //Check Point for goto 
    
    // 1.Take input
    cout<<"\nEnter the Messege : ";
    cin>>input;
    cout<<"\n";
    
    //2.Take key
    cout<<"Enter the key : ";
    cin>>key;
    cout<<"\n";
    
    //3. check the length of key and input is same or not
    len = strlen(input);
    
    if(len!= strlen(key)){
        goto takeAgain ;                // If length is not same the enter the details again
    }
    
   //4.convert input into corresponding numbers  
    for(int i=0; i<len ; i++){
        inputNo[i] = input[i] - 97 ;
    }
    
    //5.convert key into corresponding numbers
    for(int i=0; i<len; i++){
        keyNo[i] = key[i] - 97;
    }
}


void encryption(){
    
    // 1.Add the keyNo and InputNo to get Encrypted message 
    for(int i=0; i<len; i++){
        outputNo[i] = inputNo[i]+keyNo[i];
        
        //if Addition is more than 25 subtract by 25
        if(outputNo[i] > 25){
            outputNo[i] = outputNo[i] - 25 ;
        }
    }
    
    // 2. Convert Output number in Encrypted message
    for(int i=0; i<len ; i++){
        output[i] = outputNo[i] + 97 ;
    }
    
    cout<<"\nEncrypted message is : ";
}

void decryption(){
    
    //1.Subtract the KeyNo from the inputNo to get decrypted messege 
    for(int i=0; i<len; i++){
        outputNo[i] = inputNo[i] - keyNo[i];
        
        //if subtraction become less than zero add 25
        if(outputNo[i] < 0){
            outputNo[i] = outputNo[i] + 25 ;
        }
    }
    
    //2.Convert Output number into Decrypted message
    for(int i=0; i<len; i++){
        output[i] = outputNo[i] + 97 ;
    }
    
    cout<<"\nDecrypted messege is : " ;
}


void print(){
    
    for(int i=0; i<len; i++){
        cout<<output[i];
    }
}



int main(){

    int choice;
    
    cout<<"\nVernam Cyphering....\n\n";
    
    // Loop will run utill user exit  
    while(true){
        
    //Menu Bar
    cout<<"\n\n"    ;
    cout<<"1. Encryption \n";
    cout<<"2. Decryption \n";
    cout<<"3. Exit \n\n" ;
    cout<<"Enter choice : " ;
    cin>>choice ;
        
    switch(choice){
            
        // Encyption    
        case 1: takeInput();
                encryption();
                print();
                break;
            
        //Decrytion
        case 2: takeInput();
                decryption();
                print();
                break;
            
        //Exit Function to exit from loop        
        case 3: exit(0);
                break;
            
        default: cout<<"\n Please Enter the Right choice \n" ;
                 break ;
    }      
   
  }
    

return 0;

}

//Think twice Code Once