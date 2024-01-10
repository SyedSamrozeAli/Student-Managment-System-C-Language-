#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Headerfile123.h"
#include <conio.h>

void student();
void teacher();
int  Register();
void login_signup();
char* pass_validation();
void beep();
void heading();

struct student_registration{
char id[30];
char password[30];
};

int main(){
system("color f0");

login_signup();

return 0;
}

void heading(){
printf("\n\n\n\t\t\t\t\t\t  <<--------------STUDENT RECORD MANAGEMENT SYSTEM-------------->>\n\n\n\n\n\n\n\n\n");
}

void login_signup(){
heading();
int ans;

printf("\n\n\t\t\t\t\t\t\t\tAre you a student or a teacher?\n\n\t\t\t\t\t\t\t\tPress>> 1-For Student\n\n\t\t\t\t\t\t\t\tPress>> 2-For Teacher\n\n");
printf("\t\t\t\t\t\t\t\t_________________________\n");
printf("\n\t\t\t\t\t\t\t\tChoose the correct option: ");
scanf(" %d",&ans);

switch(ans){

case 1:
 student();
 break;


case 2:
 system("CLS");
 heading();
     teacher();
 break;
 
default:
      beep();
      system("CLS");
  login_signup();  
 
}
}


void student(){
int check,count=0;
static char id2[10];
char pass[30];
struct student_registration s;


do{


check=Register();
if(check==1){   /*/-----------> SIGN UP CODE(STUDENT)*/
   FILE *log;
    log=fopen("login.txt","ab+");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
   
printf("\n\n\t\t\t\t\t\t\t\tEnter your Student ID, i.e(22k-4586): ");
fflush(stdin);
gets(s.id);
printf("\n\n\t\t\t\t\t\t\t\tCreate Password");
       /*USE OF DMA*//*the returned password*/
       char *ptr=pass_validation();
       strcpy(s.password,ptr);
       
       fwrite(&s,sizeof(s),1,log);
       free(ptr);
    fclose(log);
    printf("\n\t\t\t\t\t\t\t\tRegistration Successful!\n");
    printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to continue...");
        getchar();
 

}
else if (check==2)
{                 /*/--------------> LOGIN CODE(STUDENT)*/
   count++;
   FILE *log;

   log = fopen("login.txt","rb");
   if (log == NULL)
   {
       fputs("Error at opening File!", stderr);
       exit(1);
   }
   printf("\n\n\t\t\t\t\t\t\t\tEnter your Student ID, i.e(22K-4586): ");
fflush(stdin);
gets(id2);
printf("\n\n\t\t\t\t\t\t\t\tEnter password: ");
fflush(stdin);
gets(pass);

   while(fread(&s,sizeof(s),1,log))
        {
        if(strcmp(id2,s.id)==0 && strcmp(pass,s.password)==0)

            {  
                printf("\n\n\t\t\t\t\t\t\t\tSuccessful Login!\n");
                printf("\n\n\t\t\t\t\t\t\t\tPress any key to continue...");
                getch();
                student_menu(id2);
            }
        }
      
        printf("\n\n\t\t\t\t\t\t\t\tIncorrect Login Details\n\n\t\t\t\t\t\t\t\tPlease enter the correct credentials\n");
               
            
        

    fclose(log);

    printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to continue...");
    getch();


}
else {
beep();
}

/*maximum limit*/
if (count==4){
printf("\n\n\t\t\t\tSorry, close and restart the software, as you have reached the maximum number of attempts");
exit(0);
}


}while(1);


}

int  Register(){
int choice;
system("CLS");
heading();
printf("\n\n\n\t\t\t\t\t\t\t\tPress>> 1-To Signup:\n\n\t\t\t\t\t\t\t\tPress>> 2-To Login:\n ");
printf("\t\t\t\t\t\t\t\t_________________________\n");
printf("\n\t\t\t\t\t\t\t\tChoose the correct option: ");
scanf("%d",&choice);
return choice;
}


char* pass_validation(){
	
    /*static char pass[200]; */  /*/---------------->PASSWORD VALIDATION FOR REGISTRATION*/
    int i,number,special,capital,small;
    number=special=capital=small=0;
    /*USE OF DMA ---> We can either return static array(pass) or DMA array(ptr). In my scenario I am returning DMA array*/
    char *pass=(char*)calloc(25,sizeof(char));
    printf("\n\n\t\t\t\t\t\t\t\tPasword must have at least one:\n\t\t\t\t\t\t\t\t-Captital letter\n\t\t\t\t\t\t\t\t-Small letter\n\t\t\t\t\t\t\t\t-Special character(!,@,#,$,%,*)\n\t\t\t\t\t\t\t\t-Numeric character");
    printf("\n\n\t\t\t\t\t\t\t\tEnter Password: ");
    fflush(stdin);
    gets(pass);
    
	/*strcpy(ptr,pass);*/
	
    for(i=0;pass[i]!='\0';i++)
    {
        if(pass[i]>='0' && pass[i]<='9')
        number=1;
        if(pass[i]>='a' && pass[i]<='z')
        small=1;
        if(pass[i]>='A' && pass[i]<='Z')
        capital=1;
        if(pass[i]=='!' || pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%' || pass[i]=='*')
        special=1;
    }
    if(number==0 || special==0 || capital==0 || small==0){
        printf("\n\n\t\t\t\t\t\t\t\tInvalid Password\n\n\t\t\t\t\t\t\t\tPlease enter the details again.");
		printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to continue...");
        getchar();    
		Register();
	}
    else{
        printf("\n\n\t\t\t\t\t\t\t\tAccount Created Successfully\n\n");
    }
    return pass;

}


void beep(){    /*/-------------->SOUND EFFECT*/
printf("\a");
printf("\n\n\t\t\t\t\t\t\t\t");
usleep(200000);
printf("Wrong input!");
usleep(200000);
printf(" Try again");
sleep(1);
}

void teacher(){
             /*/--------------> TEACHER LOGIN CODE*/
static int count1=0;
char username[20],pass[20];
printf("\n\n\t\t\t\t\t\t\t\tEnter your username: ");
fflush(stdin);
gets(username);

printf("\n\n\t\t\t\t\t\t\t\tEnter your password: ");
fflush(stdin);
gets(pass);

if(strcmp(username,"123")==0 && strcmp(pass,"123")==0){
puts("\n\n\t\t\t\t\t\t\t\tLOGIN Successfull!\n");
printf("\t\t\t\t\t\t\t\t\t\tPress any key to continue.......");
menu_cases();
}
else {
puts("\n\n\t\t\t\t\t\t\t\tInncorrect Username or Password!\n");
printf("\a");
count1++;
printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to continue......");
getch();
system("CLS");
heading();
}

if(count1==4){    /*//------>MAXIMUM ATTEMPTS CHECK*/
printf("\n\n\t\t\t\t\t\tSorry, close and restart the software, as you have reached the maximum number of attempts!");
exit(0);
} else if(count1>=1){
  teacher();

}
}

