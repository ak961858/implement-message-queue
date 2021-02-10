#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h> 
#include<sys/types.h>   
#include<stdio.h>
struct mymesg
{
	long type;
	char data[512];
} *buff;
using namespace std;
int main()
{
	struct msqid_ds *info=new struct msqid_ds();
	buff=new struct mymesg();
	key_t key=ftok("msg",65);
	int msgid;
	msgid=msgget(key,0666|IPC_CREAT);
	cout<<"\ni am p2,starting reading : ";
	int i=0;
	while(1)
	{
		if(msgrcv(msgid,buff,512,2,IPC_NOWAIT)<0)
		{
			cout<<"\np2 has finished reading "<<i<<" messages of type "<<2;
		
			break;
		}
		else
		{
		cout<<"\nread message : "<<i+1<<buff->data;
		sleep(2);
		i++;
		}
	}
	msgctl(msgid,IPC_STAT,info);	            
	sleep(1);  	
       	cout<<"\nmessages left in queue : "<<info->msg_qnum;
	sleep(1);  
	cout<<"\nmy pid"<<getpid();	
		   sleep(1);    
     	cout<<"\npid of last message send "<<info->msg_lspid;
	sleep(1);  
	cout<<"\npid of last message msgrcv "<<info->msg_lrpid;
	sleep(1);  
	cout<<"\nlast msgsnd time "<<info->msg_stime;
	sleep(1);  
	cout<<"\nlast msgrcv time "<<info->msg_rtime;
	sleep(1);  
	
	return 0;
}
