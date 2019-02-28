#include<stdio.h>
#include<ctype.h>
#include<time.h>
int main()
{
	printf( "Enter passwords :");
    char c = getchar();
    char minL[]="Password must be at least 6 characters long.";
    char maxL[]="Password must be at max 12 characters long.";
    char CharSet[]="Password must contain at least one letter from the set";
    char unauth[]="Password cannot contain %!)(";
    int Flag_min[5]={0,0,0,0,0};
    int Flag_max[5]={0,0,0,0,0};
    int Flag_CharSet[5]={0,0,0,0,0};
    int Flag_Unspecified[5]={0,0,0,0,0};
    int arr_commas[5]={0,0,0,0,0};
    int arr_pass_flags[5]={0,0,0,0,0};
   	int submit=0;
    int Flag_AU=0;
    int Flag_AL=0;
    int Flag_N=0;
    int Flag_Spcl=0;
    int comma_count=0;
    int na_count=0;
    int count =0;
    int ticks;
    do
    {
        count++;
        if(isupper(c))
        {
        		Flag_AU++;	
		}
    		
        else if(islower(c))
        {
        	Flag_AL++;
		}
        	
        	
        else if(isdigit(c))
 		{
 				Flag_N++;
		 }
        
		        	
        else if(c=='*' || c=='$' || c=='_' || c=='#' || c=='@' || c=='=')
        	{
        		Flag_Spcl++;
			}
        	
        else if(c == ',' || c == '\n')
        {
            arr_commas[comma_count]=count;
            
			if(na_count>0)
			{	
				Flag_Unspecified[comma_count]=1;
				arr_pass_flags[comma_count]=0;
			}
			else if(Flag_AU>0 && Flag_AL>0 && Flag_N>0 && Flag_Spcl>0)
				arr_pass_flags[comma_count]=1;
				
			else
				{
					Flag_CharSet[comma_count]=1;
				}
			

			comma_count++;
			
			if(c=='\n')
				submit++;
        }
        
        else if(c=='%'||c=='!'||c=='('||c==')')
        	na_count++;
        	
        if(c=='\b')
        	comma_count--;
        	
        c=getchar();
    }while(submit!=1);

    int i=0;
  do
   {
	 if(arr_pass_flags[i]==1)
      {
           if(i==0)
           {
               if(arr_commas[i]>=6)
               {
               		if(arr_commas[i]<=12)
               		{
               			arr_pass_flags[i]=1;
               		}
               		else
               		{
               			arr_pass_flags[i]=0;
               			Flag_max[i]=1;
					}
					       
               }
               else
               {
               		arr_pass_flags[i]=0;
               		Flag_min[i]=1;
			   }  		
       		}
           else
           {
               if((arr_commas[i]-arr_commas[i-1] )>=6)
               {
               		if((arr_commas[i]-arr_commas[i-1])<=12)
                   		arr_pass_flags[i]=1;
                   	else
                   		{
							arr_pass_flags[i]=0;
							Flag_max[i]=1;
						  }	
               }
               else
               {
               		arr_pass_flags[i]=0;
               		Flag_min[i]=1;
			   }	
           } 
		     
     	

   }
  	 if(arr_pass_flags[i]==1)
       {
       	printf("Success %d password \n",i+1);
	   }
   		else if(arr_pass_flags[i]==0)
		{
			if(Flag_max[i]==1)
			printf("Password %d Failure %s\n",i+1,maxL);
			
			else if(Flag_min[i]==1)
			printf("Password %d Failure %s\n",i+1,minL);
			
			else if(Flag_CharSet[i]==1)
			printf("Password %d Failure %s\n",i+1,CharSet);
			
			else if(Flag_Unspecified[i]==1)
			printf("Password %d Failure %s\n",i+1,unauth);
		}  
       i++;
   } while(arr_commas[i-1]!=0);

}

