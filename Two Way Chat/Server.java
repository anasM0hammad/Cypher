    import java.net.*; 
    import java.io.* ;
    import java.util.*; 
    
    public class Server {  
    public static void main(String[] args){  
    try{  
    ServerSocket ss=new ServerSocket(6666);  
    Socket s=ss.accept();//establishes connection  



		   if(s.isConnected()) {
			System.out.println("connected");
			SocketAddress a=ss.getLocalSocketAddress();
			System.out.println(a.toString());
		   }


	DataOutputStream dout=new DataOutputStream(s.getOutputStream()); 
	Scanner sc=new Scanner(System.in);
	DataInputStream dis=new DataInputStream(s.getInputStream());  
	String send="";

/*	String  str=(String)dis.readUTF();  
	while(!str.equals("over")){
	    System.out.println("message= "+str);  
	 str=(String)dis.readUTF();  
	}

   

	do{ 
	send=sc.next();
	dout.writeUTF(send); 
	dout.flush(); 
	}while(!send.equals("over"));*/

	String Exit="start";
	while(!Exit.equals("exit")){
	
		String  str=(String)dis.readUTF();  
		while(!str.equals("over")){
		   
			if(str.equals("exit")){
			  break;
			}
		 System.out.println("Client send: "+str);  
		 str=(String)dis.readUTF();  
		}
		
		Exit=str;
			if(Exit.equals("exit")){
			  break;
			}


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






	}




	
	      
    dout.close();  

 

  
    ss.close();  
    }catch(Exception e){System.out.println(e);}  
    }  
    }  
