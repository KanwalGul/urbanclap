#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
struct person {

    char na[60];
    int  age;
    char ci[60];
    char e_ma[30];
    long long int ph;
    int id_no;
    int ex;
    char po[50];
    
    };
    
void regs()
{
	    FILE *post;
		system("CLS");
st1:	        printf("\t\t\t\t\t ***********************************************\n");
				printf("\t\t\t\t\t                                                \n");
				printf("\t\t\t\t\t         REGISTRATION FORM FOR TECHNICIAN       \n");
				printf("\t\t\t\t\t                                                \n");
				printf("\t\t\t\t\t ************************************************\n\n");
		int j;		
        struct person inf;
		printf ("\n\t\t\t\t\tEnter Your Name: ");
		fflush(stdin);
        gets (inf.na);  
		printf ("\n\t\t\t\t\tEnter Your City Name: ");
		fflush(stdin);
        gets (inf.ci);
		printf ("\n\t\t\t\t\tEnter Your e-mail id : ");
		fflush(stdin);
		gets (inf.e_ma);
		printf ("\n\t\t\t\t\tEnter Your Age :");
		fflush(stdin);
		scanf ("%d",&inf.age);
		printf ("\n\t\t\t\t\tEnter Your Post :");
		fflush(stdin);
		gets(inf.po);
		printf ("\n\t\t\t\t\tEnter Your Experience :");
		scanf ("%d",&inf.ex);
		printf ("\n\t\t\t\t\tEnter Your Phone Number :");
		scanf ("%lld",&inf.ph);
				
		if (strcmp(inf.po,"carpenter")==0||strcmp(inf.po,"CARPENTER")==0)
       {  

	    printf("\n\n\t\t\t\tREGISTRATION SUCCESSFUL");

			post=fopen("carpenter.dat","ab+");
			fwrite(&inf,sizeof (struct person),1,post);
		    fclose(post);
		   
		
		}
		else if (strcmp(inf.po,"plumber")==0||strcmp(inf.po,"PLUMBER")==0)
		{
    
	    printf("\n\n\t\t\t\tREGISTRATION SUCCESSFUL");
	
			post=fopen("plumber.dat","ab+");
            fwrite(&inf,sizeof (struct person),1,post);			
		    fclose(post);
		}
		else if (strcmp(inf.po,"electrician")==0 ||strcmp(inf.po,"ELECTRICIAN")==0)
		{ 
	       printf("\n\n\t\t\t\tREGISTRATION SUCCESSFUL");

			post=fopen("electrician.dat","ab+");
            fwrite(&inf,sizeof (struct person),1,post);
			fclose(post);
		}
		int op;
		printf ("\t\t\t\t\tENTER '0' TO QUIT\n\t\t\t\t\tENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;
	}
}
		
void tech()
{
	
	system ("CLS");
	int q;
	n1:
		system("CLS");
		
		
	printf("\n\n\n");
	            printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t|>>WHICH TECHNICIAN YOU WANT TO HIRE           |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
                printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t| PRESS '1' FOR HIRING A PLUMBER               |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
			    printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t| PRESS '2' FOR HIRING A ELECTRICIAN           |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
				printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t| PRESS '3' FOR HIRING A CARPENTER             |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
				scanf ("%d",&q);
	switch (q)
	{
		case 1:pul();
		break;
		case 2:ele();
		break;
		case 3:car();
		break;
		default:
		goto n1;
		break;	
	
	
	
}
}
pul()
	{
		FILE *p1;
		FILE *ptr2 = fopen("temp.dat","ab+");
		char *ptr;
		int k;
		struct person inf;
		system ("CLS");
		FILE *po,*po1;
		
		po= fopen ("plumber.dat", "rb");
		po1=fopen("hire1.dat","ab+");
		
		printf("NAME\t\t\tCITY\t\tAGE\t\tPOST\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po))  
        printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d\t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose (po);
        char name[20];  

        po= fopen ("plumber.dat", "rb");
        
		fflush(stdin);
        printf("\n\n\t\t\t\tENTER NAME OF PLUMBER YOU WANT TO HIRE  : ");
        scanf ("%s",&name);
 
        while(fread(&inf, sizeof(struct person), 1, po))
       {
    	char name1[30];
    	strcpy(name1,inf.na);
        if(strcmp(name1,name)!=0)
        fwrite(&inf,sizeof(struct person),1,ptr2);
        if(strcmp(name1,name)==0)
        fwrite(&inf,sizeof(struct person),1,po1);
       
    }  
	
		fclose(po1);
        fclose(po);
        fclose(ptr2);
		 
        remove("plumber.dat");
    	rename("temp.dat","plumber.dat");
    	printf("\t\t\t\t\tYour technician is arriving......");
       
       
        
		int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;
	    }	
}
ele()
	{
		struct person inf;
		system ("CLS");
		FILE *po,*po1,*ptr2;
		int k;
		po= fopen ("electrician.dat", "rb");
        ptr2=fopen("temp2.dat","ab+");
        po1=fopen("hire2.dat","ab+"); 
		printf("NAME\t\t\tCITY\t\tAGE\t\t  POST\t\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po)) 
        
		printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d  \t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose(po);
		char name[20];
		po=fopen("electrician.dat","rb");
		  
        
     
        fflush(stdin);
        printf("\n\n\t\t\t\tENTER NAME OF ELECTRICIAN YOU WANT TO HIRE  : ");
        scanf ("%s",&name);
 
        while(fread(&inf, sizeof(struct person), 1, po))
       {
    	char name1[30];
    	strcpy(name1,inf.na);
        if(strcmp(name1,name)!=0)
        fwrite(&inf,sizeof(struct person),1,ptr2);
        if(strcmp(name1,name)==0)
        fwrite(&inf,sizeof(struct person),1,po1);
       
    }
		fclose(po1);
        fclose(po);
        fclose(ptr2);
   
         remove("electrician.dat");
         rename("temp2.dat","electrician.dat");
    	printf("\t\t\t\t\tYour technician is arriving......");
       
	    int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;
	}}
car()
	{
		struct person inf;
		system ("CLS");
		FILE *po,*po1,*ptr2;
		int k;
		po= fopen ("carpenter.dat", "rb");
        ptr2=fopen("temp3.dat","ab+");
        po1=fopen("hire3.dat","ab+");
        
		printf("NAME\t\t\tCITY\t\tAGE\t\t  POST\t\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po)) 
       
	    printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d  \t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
       fclose(po);
	    char name[20];  
        po=fopen("carpenter.dat","rb");
        fflush(stdin);
        printf("\n\n\t\t\t\tENTER NAME OF CARPENTER YOU WANT TO HIRE  : ");
        scanf ("%s",&name);
 
        while(fread(&inf, sizeof(struct person), 1, po))
       {
    	char name1[30];
    	strcpy(name1,inf.na);
        if(strcmp(name1,name)!=0)
        fwrite(&inf,sizeof(struct person),1,ptr2);
        if(strcmp(name1,name)==0)
        fwrite(&inf,sizeof(struct person),1,po1);
       
    }   
    
        fclose(po1);
        fclose(po);
        fclose(ptr2);
         remove("carpenter.dat");
         rename("temp3.dat","carpenter.dat");
    	printf("\t\t\t\t\tYour technician is arriving......");
		
       
		int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;
	}}
void show1()
{
system ("CLS");
		FILE *po;
		po= fopen ("plumber.dat", "rb");
		struct person inf;
		printf("NAME\t\t\tCITY\t\tAGE\t\tPOST\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po))  
        printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d\t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose (po);
        int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0 :
		exit (0);
		break;
		case 1:
		list();
		break;        	
		
}}
void show2()
{
system ("CLS");
		FILE *po;
		po= fopen ("carpenter.dat", "rb");
		struct person inf;
		printf("NAME\t\t\tCITY\t\tAGE\t\tPOST\t\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po))  
        printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d\t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose (po);
        int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;        	
		
}}
void show3()
{
system ("CLS");
		FILE *po;
		po= fopen ("electrician.dat", "rb");
		struct person inf;
		printf("NAME\t\t\tCITY\t\tAGE\t\tPOST\t\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po))  
        printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d\t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose (po);
        int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;        	
		
}}
void show4()
{
system ("CLS");
		FILE *po;
		po= fopen ("hire1.dat", "rb");
		struct person inf;
		printf("NAME\t\t\tCITY\t\tAGE\t\tPOST\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po))  
        printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d\t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose (po);
        int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;        	
		
}}
void show5()
{
system ("CLS");
		FILE *po;
		po= fopen ("hire2.dat", "rb");
		struct person inf;
		printf("NAME\t\t\tCITY\t\tAGE\t\tPOST\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po))  
        printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d\t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose (po);
        int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;        	
		
}}
void show6()
{
system ("CLS");
		FILE *po;
		po= fopen ("hire3.dat", "rb");
		struct person inf;
		printf("NAME\t\t\tCITY\t\tAGE\t\tPOST\t\tEXPERI\t\tPHONE.NO\n"); 
		while(fread(&inf, sizeof(struct person), 1, po))  
        printf ("%s\t\t\t%s\t\t%d\t\t%s\t\t%d\t\t%lld\n",inf.na,inf.ci,inf.age,inf.po,inf.ex,inf.ph);
        fclose (po);
        int op;
		printf ("\n\n\n\t\t\t\t\t>>>>ENTER '0' TO QUIT\n\n\t\t\t\t\t>>>>ENTER '1' FOR THE MENU ");
		scanf ("%d",&op);
		switch (op)
		{
		
 		case 0:
		exit (0);
		break;
		case 1:
		list();
		break;        	
		
}}




void menu2()
{
	
	    int op;
	    m1:
	    system("CLS");
    	
    	printf("\n\n\n\n\n\t\t\t\t\t  ====>WELCOME MANAGEMENT PORTAL<====\n");
    	
    	printf("\t\t\t\t\t _______________________________________________________\n");
    	printf("\t\t\t\t\t|                                                       |\n");
    	printf("\t\t\t\t\t|     PRESS '1' FOR REGISTRATION                        |\n");
    	printf("\t\t\t\t\t|_______________________________________________________|\n");
    	printf("\t\t\t\t\t                                                         \n");
    	printf("\t\t\t\t\t _______________________________________________________\n");
    	printf("\t\t\t\t\t|                                                       |\n");
    	printf("\t\t\t\t\t| PRESS '2' FOR THE LIST OF AVAILABLE PLUMBERS          |\n");
    	printf("\t\t\t\t\t|_______________________________________________________|\n");
    	printf("\t\t\t\t\t                                                         \n");
    	printf("\t\t\t\t\t _______________________________________________________\n");
    	printf("\t\t\t\t\t|                                                       |\n");
    	printf("\t\t\t\t\t| PRESS '3' FOR THE LIST OF AVAILABLE CARPENTER         |\n");
    	printf("\t\t\t\t\t|_______________________________________________________|\n");
    	printf("\t\t\t\t\t                                                         \n");
    	printf("\t\t\t\t\t _______________________________________________________\n");
    	printf("\t\t\t\t\t|                                                       |\n");
    	printf("\t\t\t\t\t| PRESS '4' FOR THE LIST OF AVAILABLE ELECTRICIAN       |\n");
    	printf("\t\t\t\t\t|_______________________________________________________|\n");
    	printf("\t\t\t\t\t                                                         \n");
    	printf("\t\t\t\t\t _______________________________________________________\n");
    	printf("\t\t\t\t\t|                                                       |\n");
    	printf("\t\t\t\t\t| PRESS '5' FOR THE LIST OF HIRED PLUMBERS              |\n");
    	printf("\t\t\t\t\t|_______________________________________________________|\n");
    	printf("\t\t\t\t\t                                                         \n");
    	printf("\t\t\t\t\t _______________________________________________________\n");
    	printf("\t\t\t\t\t|                                                       |\n");
		printf("\t\t\t\t\t| PRESS '6' FOR THE LIST OF HIRED CARPENTER             |\n");
		printf("\t\t\t\t\t|_______________________________________________________|\n");
		printf("\t\t\t\t\t                                                         \n");
		printf("\t\t\t\t\t _______________________________________________________\n");
		printf("\t\t\t\t\t|                                                       |\n");
    	printf("\t\t\t\t\t| PRESS '7' FOR THE LIST OF HIRED ELECTRICIAN           |\n");
    	printf("\t\t\t\t\t|_______________________________________________________|\n");
    	scanf ("%d",&op);
    	switch(op)
    	{
    		case 1:
			regs();
    		break;
    		case 2:
    		show1();
    		break;
    		case 3:
    		show2();
			break;	
    	    case 4:
    		show3();
			break;	
            case 5:
    		show4();
			break;	
            case 6:
    		show5();
			break;	
            case 7:
    		show6();
			break;
			default:
			goto m1;
			break;	

		  

}
}
void manag()
{
system("CLS");
n1:printf ("\n\n\n\t\t\t\t====>PLEASE ENTER PASSWORD TO LOGIN: ");
char pa,co[20];
int i=0,op;
scanf ("%s",co);

    if (strcmp(co,"code")==0 ||strcmp(co,"CODE")==0 )
    {
    	menu2();		
		 	
	}
    else
    {
    	printf ("\n\n\t\t\t\tWRONG PASSWORD !!");
    	goto n1;
    	system ("CLS");
	}
}
list ()
{
	system ("CLS");
	int a;
	            printf("\n\n\n");
	            printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t|        ==>1.REGISTRATION                     |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
                printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t|        ==>2.HIRE A TECHNICIANS               |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
			    printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t|        ==>3.MANAGEMENT                       |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
			s1:	printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t|==> PRESS RELEVENT KEY TO SEE OPTIONS(1,2,3):|\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
				
	scanf ("%d",&a);
	switch (a)
	{
		case 1:regs();
		break;
		case 2:tech();
		break;
	    case 3:manag();
		break;
		default:
		{
				printf("\t\t\t\t\t ______________________________________________\n");
				printf("\t\t\t\t\t|                                              |\n");
				printf("\t\t\t\t\t|==>INVALID ENTRY!!                            |\n");
				printf("\t\t\t\t\t|______________________________________________|\n\n");
								goto s1;
		}			

	}
}
main()
{
	list();
}


