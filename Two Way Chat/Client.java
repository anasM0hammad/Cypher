    import java.util.Scanner;   
    import java.io.* 
    import java.net.*;  
    public class Client {  
    public static void main(String[] args) {  
    try{      
    Socket s=new Socket("localhost",6666); 
 	DataInputStream dis=new DataInputStream(s.getInputStream());  
  	DataOutputStream dout=new DataOutputStream(s.getOutputStream()); 
	Scanner sc=new Scanner(System.in);
	String send="";
	String Exit="start";
	while(!Exit.equals("exit")){
	
		do{ 
		System.out.print("Write message: "); 
		send=sc.nextLine();
			if(send.equals("exit")){
			  break;
			}
		dout.writeUTF(send); 
		dout.flush(); 
		}while(!send.equals("over"));
	      	Exit=send;
			if(send.equals("exit")){
			  break;
			}
    		
		 String  str=(String)dis.readUTF();  
		while(!str.equals("over")){
		    System.out.println("Server send: "+str);  
			if(str.equals("exit")){
			  break;
			}
		 str=(String)dis.readUTF();  
		}
		Exit=str;






	}


     
    dout.close();

    s.close();  
    }catch(Exception e){
	System.out.println(e);
    }  
    }  
    }  
