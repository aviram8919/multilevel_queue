
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Turn_Around(int P[],int n,int TIME_B[],int WTIME[],int TIME_TA[])
{
	for(int i=0;i<n;i++)
	{
		TIME_TA[i]=TIME_B[i]+WTIME[i];
	}
}
void Wait_Time(int P[],int n,int TIME_B[],int WTIME[],int quantum)
{ 
	int RTIME_B[n];
	for(int i=0;i<n;i++)
	{
		RTIME_B[i]=TIME_B[i];
	}
	int t=0;
	while(1)
	{
		bool done=true;
		for(int i=0;i<n;i++)
		{
			if(RTIME_B[i]>0)
			{
				done=false;
				if(RTIME_B[i]>quantum)
				{
					t+=quantum;
					RTIME_B[i]-=quantum;
				}
				else
				{
					t=t+RTIME_B[i];
					WTIME[i]=t-TIME_B[i];
					RTIME_B[i]=0;
				}
			}
		}
		if(done==true)
		{
			break;
		}
	}
}
int main()
{
	int n;
	cout<<"PLEASE ENTER THE NUMBER OF PROCESSES:-";
	cin>>n;
	int P[n];
	int TIME_B[n],TIME_B2[n],TIME_B3[n],k,l,TIME_TA2[n],WTIME2[n],PP[n];
    int WTIME1[n],WTIME3[n],TIME_TA1[n],TIME_TA[n],TWTIME1=0,i,Pos,j,temp;
    int quantum1=4;
	
	cout<<"\nPLEASE ENTER THE PRIORITY BURST TIME :";
	for(i=0;i<n;i++)
	{
		cout<<"\nPROCESS ["<<i+1<<"] :\t";
		cout<<"\nBURST_TIME :";
		cin>>TIME_B[i];
		cout<<"\nPRIORITY :";
		cin>>P[i];	
	}
	for(i=0;i<n;i++)
	{
	    if(1<=P[i] && P[i]<=3)
	    {
			cout<<"\n\t\t\t\t\tROUND ROBIN"<<"\n\n";
			Turn_Around(P,n,TIME_B,WTIME1,TIME_TA1);
			Wait_Time(P,n,TIME_B,WTIME1,quantum1);
            cout<<"\n "<<"PROCESS"<<"\t"<<"BURST_TIME"<<"\t"<<"WAITING_TIME"<<"\t"<<"TURN_ARROUND_TIME"<<endl;
           
			  int y=i+1;
    	      cout<<" ["<<y<<"]\t\t"<<TIME_B[i]<<"\t\t"<<WTIME1[i]<<"\t\t"<<TIME_TA1[i]<<endl;
    	      y=0;
         
 	    }
 	    else if(4<=P[i] && P[i]<=6)
 	    { 	    	
 	    	cout<<"\n\t\t\t\t\tFIRST_COME_FIRST_SERVE"<<"\n\n";
 	    	WTIME2[0]=0;
	        for(k=1;k<n;k++)
	        {
	    	 WTIME2[k]=0;
	    	 for(l=0;l<k;l++)
	    	 {
	    		WTIME2[k]+=TIME_B[l];
			 }
		    }
		     cout<<"\nPROCESS"<<"\t\t"<<"BURST_TIME"<<"\t\t"<<"WAITING_TIME"<<"\t\t"<<"TURN_ARROUND_TIME"<<endl;
		  
		    	TIME_TA2[i]=TIME_B[i]+WTIME2[i];
			    cout<<"\nP["<<i+1<<"]"<<"\t\t"<<TIME_B[i]<<"\t\t\t"<<WTIME2[i]<<"\t\t\t"<<TIME_TA2[i]<<endl;
			    
		     
	     } 
		 else if(7<=P[i] && P[i]<=9)
		 {
		 	   	cout<<"\n\t\t\t\t\tPRIORITY_SCHEDULING_ALGORITHM"<<"\n\n";
		
	            for(int i=0;i<n;i++)
	            {
	    	       Pos=i;
	    	       for(j=i+1;j<n;j++)
	            	{
	    	      	if(P[j]<P[Pos])
	    	        	{
	    			     Pos=j;
				        }
		           	}
		        	temp=P[i];
		        	P[i]=P[Pos];
		         	P[Pos]=temp;
		        	temp=TIME_B[i];
		        	TIME_B[i]=TIME_B[i];
		        	TIME_B[i]=temp;
		        	 
		        	temp=PP[i];
		        	PP[i]=PP[Pos];
		        	PP[Pos]=temp;
	        	}
	        	WTIME3[0]=0;
		        for(int i=0;i<n;i++)
		        {
			     WTIME3[i]=0;
			     for(j=0;j<i;j++)
			        {
				      WTIME3[i]+=TIME_B[i];
		        	}
		       }
		      cout<<"\n"<<"PROCESS"<<"\t\t"<<"BURST_TIME"<<"\t\t"<<"WAITING_TIME"<<"\t\t"<<"TURN_ARROUND_TIME"<<endl;
		    
	           TIME_TA[i]=TIME_B[i]+WTIME3[i];
		       cout<<"\nP["<<i+1<<"]"<<"\t\t"<<TIME_B[i]<<"\t\t\t"<<WTIME3[i]<<"\t\t\t"<<TIME_TA[i]<<endl;	
			   	      
		   }   	
	   }
   }
