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
} buff;
using namespace std;
int main()
{
	struct msqid_ds *info=new struct msqid_ds();
	key_t key=ftok("msg",65);
	int msgid;
	msgid=msgget(key,0666|IPC_CREAT);

	cout<<"\nhow many message you want to send to p2 : ";
	int n;cin>>n;
	buff.type=2;
	cout<<"\nstart entering "<<n<<" messages : ";
	cin.ignore();
	for(int i=0;i<n;i++)
	{
	cout<<"\nenter message : "<<i+1;
	cin.getline(buff.data,512);
	msgsnd(msgid,&buff,strlen(buff.data),2);
	sleep(1);
	cout<<"\nsent m"<<i+1<<endl;
	}

	cout<<"\nhow many messages you want to sent to p3 : ";
	cin>>n;
	buff.type=3;
	cin.ignore();
	for(int i=0;i<n;i++)
	{       
		cout<<"\nenter message : "<<i+1;
		cin.getline(buff.data,512);
       		sleep(1);	       
		if(msgsnd(msgid,&buff,strlen(buff.data),3)<0) 
			perror("error()");		
		
		cout<<"\nsent m"<<i+1;
	}
	msgctl(msgid,IPC_STAT,info);
	
	cout<<"\nmy pid"<<getpid();
	cout<<"\nmessage in queue "<<info->msg_qnum<<" ";
	cout<<"\npid of last message send "<<info->msg_lspid;
	cout<<"\nlast msgsnd time "<<info->msg_stime;
	cout<<"\nlast msgrcv time "<<info->msg_rtime;
	
	return 0;
}

