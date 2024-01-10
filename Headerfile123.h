void menu_cases();           /*/ it contain the switch cases of student record main menu */

void addstudent();           /*/ it used to add student in a record*/
void studentrecord();        /*/ it used to view all record of all students*/
void modify();               /*/ it used to modify a particular student record*/
void searchstudent();        /*/ it used to search the record of a parricular student*/
void delete1();              /*/ it used to delete a particular record of a student*/


void attendance_cases();     /*/ it contains the switch casesof attendance managment menu */
void input();                /*/ it is used to input the attendance at a particular date*/
void edit();                 /*/ it is used to edit the attendance at a paticular date*/
void search();               /*/ it is used to search the attendance of a particular student*/
void view();                 /*/ it is used to view the the attendance at a particular date*/


void mark_cases();           /*/ it contain the switch cases of student marks managment main menu */
void modifyMarks();          /*/ it used to modify a particular student's marks*/
void addMarks();             /*/ it used to add marks of a particular student */
void deleteMarks();          /*/ it used to delete a particular student's marks(subject wise or whole marks)*/
void stats();                /*/ it provides the statistics of whole class*/


void student_menu(char*);    /*/ it contain the switch cases of student main menu */
void search2(char*);         /*/ it is used to search the attendance of a particular student*/
void marksheet2(char*);      /*/ it is used to view the marksheet of a particular student*/
void view_timetable();       /*/ it is used to view the timetable*/
char check_grade(float);     /*/ it gives the grade of a particular subject */


struct items {
    char marked;
    char roll_no[40];
    char date[40];
   
};


struct mark{
float phy;
float maths;
float eng;
float comp;
float urdu;
float history;
float total;
float avg;
float percentage;
};

  struct grading{
	char math;
	char phy;
	char comp;
	char urdu;
	char eng;
	char his;
};

  struct student {
    char first_name[20];
    char last_name[20];
    char roll_no[40];
    char email[30];
    char phone_no[30];
    char gender[20];
    char nationality[20];
    char dob[20];
    int check;
   struct mark m;
   struct grading grade;
};

 void menu_cases()
{    
    int choice;
    while(1){
   
    getch();
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t========STUDENT DATABASE MANAGEMENT SYSTEM========\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t1. Add Student\n");
    printf("\t\t\t\t\t\t\t\t2. Students Records\n");
    printf("\t\t\t\t\t\t\t\t3. Search Student\n");
    printf("\t\t\t\t\t\t\t\t4. Delete Student\n");
    printf("\t\t\t\t\t\t\t\t5. Modify Student\n");
    printf("\t\t\t\t\t\t\t\t6. Manage Attendance\n");
    printf("\t\t\t\t\t\t\t\t7. Manage Marks\n");
    printf("\t\t\t\t\t\t\t\t8. Exit\n");
    printf("\t\t\t\t\t\t\t\t____________\n\n");
    printf("\t\t\t\t\t\t\tSelect an Option: ");
    scanf("%d",&choice);

   switch(choice){
       case 1:
       
          addstudent();
          printf("\n\n\t\t\t\t\t\t\t\t  press any key to exit..... \n"); 
		  break;
     
	 case 2:
        
          system("cls");
          studentrecord();
          printf("\n\n\t\t\t\t\t\t\t\t  press any key to exit..... \n");
		  break;

     case 3:
         system("CLS");
         searchstudent();
         printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");
         break;

     case 4:
         system("CLS");
        delete1();
        printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");
		break;
     
    case 5:
       system("cls");
        modify();
        printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");
		break;
    
	case 6:
       
        attendance_cases();
        printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");
		break;
	case 7:

        mark_cases();
        printf("\n\n\t\t\t\t\t\t\t\tPress any key to exit.......\n");
		break;

	case 8:
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\tThank you, for using this software.\n\n");
		exit(0);
		
		break;
       
    default :
    	 printf("\a");
         printf("\n\n\n\t\t\t\t\t\t\tSelect a Correct Option\n\n");
         printf("\n\n\t\t\t\t\t\t\t\t  Press any key to continue.......");
         getch();
         
       
         break;
    }


    }
}

     
void addstudent(){
   
    char another,roll_no[30];
    FILE *fp;
    int n,i,flag;
    struct student info;
	do{  
        do{
        system("cls");
        printf("\n\n\t\t\t\t\t\t\t\t=======Add Students Info=======\n\n\n");
    	fp=fopen("information.txt","ab+");
         
  		printf("\n\n\t\t\t\t\t\t\t\tEnter Roll-No i.e(22K-4187)       : ");
  		fflush(stdin);
        gets(roll_no);
        flag=0;
        while(fread(&info,(long)sizeof(struct student),1,fp)>0){
			if((strcmp(info.roll_no,roll_no))==0){
				printf("\n\n\t\t\t\t\t\tRoll number already exist!Enter another roll number.\n\n");
				getch();
				flag=1;
				break;
			}
		}
		
		}while(flag==1);
	 	strcpy(info.roll_no,roll_no);          
	    printf("\n\t\t\t\t\t\t\t\tEnter First Name      : ");
	    gets(info.first_name);
		printf("\n\t\t\t\t\t\t\t\tEnter Last Name       : ");
	    gets(info.last_name);
	    printf("\n\t\t\t\t\t\t\t\tEnter Email Address   : ");
	    gets(info.email);
		printf("\n\t\t\t\t\t\t\t\tEnter phone number    : ");
	    gets(info.phone_no);
	    printf("\n\t\t\t\t\t\t\t\tEnter Gender          : ");
	    gets(info.gender);
	    printf("\n\t\t\t\t\t\t\t\tEnter Nationality     : ");
	    gets(info.nationality);
	    printf("\n\t\t\t\t\t\t\t\tEnter Date of birth (dd/mm/yy) :");
	    gets(info.dob);
	    info.check=0;
	 	printf("\n\t\t\t\t\t\t\t\t____________\n");
	
	    if(fp==NULL){
	    	fprintf(stderr,"can't open file");
	    }else{
	        printf("\n\n\t\t\t\t\t\t\t\tRecord stored successfuly\n");
	    }
	    info.check=0;
	    info.grade.comp='\0';
	    info.grade.eng='\0';
	    info.grade.his='\0';
	    info.grade.math='\0';
	    info.grade.phy='\0';
	    info.grade.urdu='\0';
		info.m.avg=0.0;
		info.m.comp=0.0;
		info.m.eng=0.0;
		info.m.history=0.0;
		info.m.maths=0.0;
		info.m.percentage=0.0;
		info.m.phy=0.0;
	    info.m.total=0.0;
	    info.m.urdu=0.0;
	    FILE *fp2;
	    struct items attendance;
	    fp2=fopen("date.txt","a+");
	    strcpy(attendance.roll_no,roll_no);
	    attendance.marked='\0';
	    for (i=0;i<40;i++){
	    	attendance.date[i]='\0';
		}
	    fwrite(&attendance, (long)sizeof(struct items), 1, fp2);
	    fclose(fp2);
	    
	    fwrite(&info, (long)sizeof(struct student), 1, fp);
	    fclose(fp);
	
	    printf("\n\n\t\t\t\t\t\t\tYou want to add another record?(y/n) : ");
	
	
	    scanf("%s",&another);


   }while(another=='y'||another=='Y');
}

void searchstudent(){
    struct student info;
    FILE *fp;
    char roll_no[39];
 	int found=0;

    fp=fopen("information.txt","rb");
    printf("\n\n\t\t\t\t\t\t\t\t=======SEARCH STUDENTS RECORD=======\n");
    printf("\n\n\t\t\t\t\t\t\t\tEnter the roll no : ");
    fflush(stdin);
    gets(roll_no);



    while(fread(&info,sizeof(struct student),1,fp)>0){

        if(strcmp(info.roll_no,roll_no)==0){

        	found=1;
        	printf("\n\t\t\t\t\t\t\t\tStudent Name  : %s %s",info.first_name,info.last_name);
        	printf("\n\t\t\t\t\t\t\t\tRoll NO       : %s",info.roll_no);
	        printf("\n\t\t\t\t\t\t\t\tEmail Address : %s",info.email);
	    	printf("\n\t\t\t\t\t\t\t\tPhone number  : %s",info.phone_no);
	        printf("\n\t\t\t\t\t\t\t\tGender        : %s",info.gender);
	        printf("\n\t\t\t\t\t\t\t\tNationality   : %s",info.nationality);
	        printf("\n\t\t\t\t\t\t\t\tDate of birth : %s",info.dob);
	       
	        printf("\n\n\t\t\t\t\t\t\t\t______________________________________\n");

         }

    }

    if(!found){
       printf("\n\n\t\t\t\t\t\t\t\tRecord not found\n");
    }

    fclose(fp);
    getch();

}

 void studentrecord(){

    FILE *fp;

    struct student info;
    fp=fopen("information.txt","rb");

    printf("\n\n\t\t\t\t\t\t\t\t=======STUDENTS RECORD=======\n\n\n");

    if(fp==NULL){

        printf("\n\n\t\t\t\t\t\t\tStudents records not added yet\n");
    }else{
        printf("\n\n\t\t\t\t\t\t\t\tRECORDS :\n");
        printf("\n\n\t\t\t\t\t\t\t\t____________\n");
    }

	while(fread(&info,sizeof(struct student),1,fp)){
    printf("\n\t\t\t\t\t\t\t\tStudent Name  : %s %s",info.first_name,info.last_name);
    printf("\n\t\t\t\t\t\t\t\tRoll NO       : %s",info.roll_no);
   	printf("\n\t\t\t\t\t\t\t\tEmail Address : %s",info.email);
    printf("\n\t\t\t\t\t\t\t\tPhone number  : %s",info.phone_no);
    printf("\n\t\t\t\t\t\t\t\tGender        : %s",info.gender);
    printf("\n\t\t\t\t\t\t\t\tNationality   : %s",info.nationality);
    printf("\n\t\t\t\t\t\t\t\tDate of birth : %s",info.dob);
    printf("\n\t\t\t\t\t\t\t\t      ____________\n");

    }
    fclose(fp);

}

 void delete1(){
    struct student info;
    FILE *fp, *fp1;


    char roll_no[39];
	int found=0;

    printf("\n\n\t\t\t\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
    fp=fopen("information.txt","rb");
    fp1=fopen("temp.txt","wb");
    printf("\n\n\t\t\t\t\t\t\t\tEnter the roll no : ");
    fflush(stdin);
    gets(roll_no);
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }

    while(fread(&info,sizeof(struct student),1,fp)){
        if(strcmp(info.roll_no,roll_no)==0){

            found=1;      /*/ agr rollno. match nhii hota to sara data temp file mein chala jayega or jyese hi rollno, match hoga to wo wala data temp*/
                          /*/ file mein nhi jayega. ab temperory file mein matched rollno. waale data k ilawa saraa data mojood hai*/
        }else{
           fwrite(&info,sizeof(struct student),1,fp1);
        }

    }
    fclose(fp);
    fclose(fp1);

    if(!found){
          printf("\n\n\t\t\t\t\t\t\t\tRecord not found\n");
        }
    if(found){
    	remove("information.txt");      /*/ab hum apni orginal file ko delete krdenge or temporary waali file ko rename krdenge.*/
        rename("temp.txt","information.txt");

        printf("\n\n\t\t\t\t\t\t\t\tRecord deleted succesfully\n");
        }
}

void modify()
{
	FILE *fp;
	struct student s;
	int found=0;
	char id[40];
	
	fp=fopen("information.txt","rb+");
	
	printf("\n\n\t\t\t\t\t\t\tEnter student roll no you want to Modify:");
	fflush(stdin);
	gets(id);
	
	while((fread(&s,sizeof(s),1,fp))>0)
	{
		if(strcmp(s.roll_no,id)==0)
		{
			found=1;
			fflush(stdin);
	   		printf("\n\n\t\t\t\t\t\t\t\tEnter First Name     : ");
	        gets(s.first_name);
	        printf("\n\t\t\t\t\t\t\t\tEnter Last Name     : ");
	        gets(s.last_name);
	        printf("\n\t\t\t\t\t\t\t\tEnter Email Address   : ");
	        gets(s.email);
	        printf("\n\t\t\t\t\t\t\t\tEnter phone number    : ");
	        gets(s.phone_no);
			fseek(fp,-(long)sizeof(s),SEEK_CUR);/*/ ye isliye lagaya taake humara cursor apni orginal position se waapis starting of structure par*/
			fwrite(&s,sizeof(s),1,fp);           /*/ chala jaye. or wha se doobara write kre.*/
			break;
		}
	}
	fclose(fp);
	
	
	if(found==0)
	{
		printf("\n\n\t\t\t\t\t\t\tSorry No Record Found\n\n");}

}




 void attendance_cases()
{
    int choose;
    while(1){
   
   
    	system("cls");
        printf("\n\n\n\t\t\t\t\t\t\t\t**********ATTENDANCE***********");
        printf("\n\n\t\t\t\t\t\t\t\t1. Input Attendance");
        printf("\n\t\t\t\t\t\t\t\t2. View Attendance");
        printf("\n\t\t\t\t\t\t\t\t3. Search a Student Attendance");
        printf("\n\t\t\t\t\t\t\t\t4. Edit Attendance");
        printf("\n\t\t\t\t\t\t\t\t5. Return to Main Menu\n");
        printf("\t\t\t\t\t\t\t\t____________\n\n");
        printf("\n\t\t\t\t\t\t\tSelect an Option: ");
        fflush(stdin);
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            input();
            break;
case 2:
   view();
break;
case 3:
   search();
break;
case 4:
   edit();
break;
case 5:
   menu_cases();      
        }
    if(choose>5 || choose<1)
    printf("\n\n\t\t\t\t\t\t\tSelect correct option");
    printf("\n\n\t\t\t\t\t\t\t\tPress any key to Continue..........");
    getch();
}
   
}
void input(){
	char c_date[15];
	struct student info;
	struct items attendance;
	here:
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t\t\tEnter Current date[dd/mm/yy]: ");
	gets(c_date);
	FILE *fp;
	FILE *fp2;
	fp=fopen("date.txt","ab+");
	if(fp==NULL){
		printf("\n\n\t\t\t\tFile not available");
		getch();
		menu_cases();
	}
	while(fread(&attendance,sizeof(struct items),1,fp)>0){
		if((strcmp(attendance.date,c_date))==0){
			printf("\n\n\t\t\t\t\t\t\t\tAttendance Already Taken. TRY ANOTHER DATE");
			goto here;
		}
	}
	strcpy(attendance.date,c_date);
	fp2=fopen("information.txt","rb");
	if(fp2==NULL){
		printf("No file found");
		exit(1);
	}
	while(fread(&info,sizeof(struct student),1,fp2)>0){
	        printf("\n\n\t\t\t\t\t\t\t\tStudent Name  : %s %s",info.first_name,info.last_name);
	        printf("\n\t\t\t\t\t\t\t\tRoll NO       : %s",info.roll_no);
	        strcpy(attendance.roll_no,info.roll_no);
	        printf("\n\n\t\t\t\t\t\t\tPress [P] for present and [A] for absent....");
	        fflush(stdin);
	    	scanf("%c",&attendance.marked);
	    	fwrite(&attendance,sizeof(struct items),1,fp);
	}
    fclose(fp2);
    fclose(fp);
	printf("\n\n\t\t\t\t\t\t\t\tSuccessfully all Attendance are taken");
   
}
void view(){
	struct student info;
	struct items attendance;
	char date[15];
	int flag=0;
	printf("\n\n\t\t\t\t\t\t\t\tEnter the date you want to search attendance: ");
	fflush(stdin);
	gets(date);
	FILE *fp,*fp2;
	fp2=fopen("date.txt","rb");
	fp=fopen("information.txt","rb");
	if(fp2==NULL || fp==NULL){
		printf("\n\t\t\t\tNo file found");
		getch();
		menu_cases();
	}
	printf("\n\n");
	while(fread(&info,sizeof(struct student),1,fp)>0){
		while(fread(&attendance,sizeof(struct items),1,fp2)){
			if((strcmp(info.roll_no,attendance.roll_no)==0) && (strcmp(date,attendance.date)==0)){
				flag=1;
				break;
			}
		}
		if (flag==0){
			break;
		}
		printf("\n\t\t\t\t\t\t\t\tStudent Name: %s %s",info.first_name,info.last_name);
		printf("\n\t\t\t\t\t\t\t\tStudent ID: %s\n",info.roll_no);
		printf("\n\t\t\t\t\t\t\t\tAttendance: %c",attendance.marked);
	
		rewind(fp2);
		printf("\n\n\t\t\t\t\t\t\t-----------------------------------------------------------\n");
	}
	
	if(flag==0){
		printf("\t\t\t\t\t\t\t\tAttendance For this Date had not been Taken");
	}
	fclose(fp2);
	fclose(fp);

}
void search(){
	struct student info;
	struct items attendance;
	int total=0,p=0,a=0,flag=0;
	char id[15],ans;
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t\t\tEnter the Student ID You Want To Search: ");
	gets(id);
	printf("\n\n\t\t\t\t\t\t\t\t>> Attendance <<");
	FILE *fp,*fp2;
	fp2=fopen("date.txt","rb");
	fp=fopen("information.txt","rb");
	if(fp2==NULL || fp==NULL){
		printf("\n\t\t\t\tAttendance or either Records of Students have not been input in the system");
		getch();
		menu_cases();
	}
	printf("\n\n");
	while(fread(&info,sizeof(struct student),1,fp)>0){
		if((strcmp(id,info.roll_no))==0){
			printf("\n\n\t\t\t\t\t\t\t\tStudent Name  : %s %s",info.first_name,info.last_name);
			printf("\n\t\t\t\t\t\t\t\tStudent ID    : %s\n",info.roll_no);
			flag=1;
			break;
		}
	}
	if (flag==0){
		printf("\n\n\t\t\t\t\t\t\tThis Student ID is not available in the System\n\n\t\t\t\t\t\t\tPress any key to continue...");
		getch();
		attendance_cases();
	}
	
	while(fread(&attendance,sizeof(struct items),1,fp2)>0){
		if((strcmp(id,attendance.roll_no))==0 && attendance.marked!='\0'){
			total++;
			if(attendance.marked=='p'||attendance.marked=='P')
				p++;
			else
				a++;
	}
}
    fclose(fp);
    rewind(fp2);
	printf("\n\t\t\t\t\t\t\t\tTotal Classes: %d",total);
	printf("\n\t\t\t\t\t\t\t\tPresent: %d",p);
	printf("\n\t\t\t\t\t\t\t\tAbsent: %d",a);
	printf("\n\t\t\t\t\t\t\t\tAttendance Mark(out of 100%): %.0f",((p*1.0/total*1.0)*100.0));
	printf("\n\n\t\t\t\t\t\t\t\tDo You Want To View Attendance Details[y/n]: ");
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='y'){
		while(fread(&attendance,sizeof(struct items),1,fp2)>0){
			if((strcmp(id,attendance.roll_no))==0 && attendance.marked!='\0'){
				if(attendance.marked=='p'||attendance.marked=='P')
					printf("\n\t\t\t\t\t\t\t\t%s: Present",attendance.date);
				else
					printf("\n\t\t\t\t\t\t\t\t%s: Absent",attendance.date);
			}
		}
	}
	fclose(fp2);
}
void edit(){
	struct student info;
	struct items attendance;
	int flag;
	char id[15],date[15],ans;
	
	flag=0;
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t\t\tEnter Student ID You Want to Edit: ");
	gets(id);
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t\t\tEnter Date[dd/mm/yyyy]: ");
	gets(date);
	FILE *fp,*fp2;
	fp2=fopen("date.txt","rb+");
	fp=fopen("information.txt","rb");
	if(fp2==NULL || fp==NULL){
		printf("\n\t\t\t\tAttendance or either records of students have not been input yet");
		menu_cases();
	}
	printf("\n\n");
	while(fread(&info,sizeof(struct student),1,fp)>0){
		if((strcmp(id,info.roll_no))==0){
			while(fread(&attendance,sizeof(struct items),1,fp2)){
				if((strcmp(id,attendance.roll_no))==0 && (strcmp(date,attendance.date))==0){
					flag=1;
					break;
				}	
			}
		}
		if (flag==1){
			break;
		}
	}
	
	if(flag==1){
		printf("\n\t\t\t\t\t\t\t\tStudent Name: %s %s\n",info.first_name,info.last_name);
		printf("\n\t\t\t\t\t\t\t\tStudent ID: %s\n",info.roll_no);
	
		printf("\n\t\t\t\t\t\t\t\tAttendance: %c",attendance.marked);
		printf("\n\n\t\t\t\t\t\t\tPress [P] for present and [A] for absent....");
		fflush(stdin);
		scanf("%c",&attendance.marked);
	    fseek(fp2,-(long)sizeof(struct items),SEEK_CUR);
	    fwrite(&attendance,sizeof(struct items),1,fp2);
	    printf("\n\n\t\t\t\t\t\t\t\tEdit Successfully");
	}
	
	else{
		printf("\n\t\t\t\t\t\t\t\tAttendance and Student ID not Matched\n\n\t\t\t\t\t\t\t---------------------------------------------------------------------------------------------------\n\n");
	    }
	fclose(fp2);
	fclose(fp);
}

void mark_cases(){
	int choose;
	char id[40];
	getch();
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t     ====MARKS MANAGEMENT====\n\n\n\n");
	printf("\n\t\t\t\t\t\t\t\t1.Add Marks");
	printf("\n\t\t\t\t\t\t\t\t2.Modify Marks");
	printf("\n\t\t\t\t\t\t\t\t3.Delete Marks");
	printf("\n\t\t\t\t\t\t\t\t4.Generate Marksheet of a Student");
	printf("\n\t\t\t\t\t\t\t\t5.Statistics of Class");
	printf("\n\t\t\t\t\t\t\t\t6.Return to Main Menu\n");
	printf("\t\t\t\t\t\t\t\t____________\n\n");
	printf("\n\t\t\t\t\t\t\tSelect an Option: ");
	fflush(stdin);
	scanf("%d",&choose);
	
	switch (choose){
		case 1:
		    system("cls");
			addMarks();
			break;
		
		case 2:
			system("cls");
			modifyMarks();
			break;
		
		case 3:
			system("cls");
			deleteMarks();
			break;
		
		case 4:
			system("cls");
			printf("\n\n\t\t\t\t\t\t\t\tEnter the student roll no: ");
		    fflush(stdin);
		    gets(id);
			marksheet2(id);
			break;
		case 5:
			system("cls");
			stats();
			break;
			
		
		case 6:
			system("cls");
			menu_cases();
			break;
		
		default:
			printf("\a");
			printf("\n\n\t\t\t\t\t\t\t\tInvalid option");
			printf("\n\n\t\t\t\t\t\t\t\tPress any key to Continue..........");
			getch();
	        mark_cases();
		}
		 mark_cases();
   
   

}



void modifyMarks(){
	FILE *fp;
	struct student s;
	int found=0,choice;
	char id[40],another;
	
	printf("\n\n\t\t\t\t\t\t\t\tEnter student roll no you want to Modify: ");
	fflush(stdin);
	gets(id);
	
	do{
		fp=fopen("information.txt","rb+");
		if (fp==NULL){
			printf("file not found");
			return;
		}
		
		while((fread(&s,sizeof(s),1,fp))>0)
		{
			if(strcmp(s.roll_no,id)==0)
			{
				found=1;
				printf("\n\n\t\t\t\t\t\t\t\tChoose which subject you want to modify: ");
				printf("\n\t\t\t\t\t\t\t\t1.MATHS\n\t\t\t\t\t\t\t\t2.PHYSICS\n\t\t\t\t\t\t\t\t3.COMPUTER\n\t\t\t\t\t\t\t\t4.URDU\n\t\t\t\t\t\t\t\t5.HISTORY\n\t\t\t\t\t\t\t\t6.ENGLISH\n\n\t\t\t\t\t\t\t\tSelect: ");
				scanf("%d",&choice);
				printf("\n\t\t\t\t\t\t\t\t(Enter all marks out of 100)");
				switch(choice){
					case 1:
						printf("\n\n\t\t\t\t\t\t\tEnter maths marks : ");
						scanf("%f",&s.m.maths);
							s.grade.math=check_grade(s.m.maths);
						break;
					case 2:
						printf("\n\n\t\t\t\t\t\t\tEnter physics marks : ");
						scanf("%f",&s.m.phy);
							s.grade.phy=check_grade(s.m.phy);
						break;
					case 3:
						printf("\n\n\t\t\t\t\t\t\tEnter computer marks : ");
						scanf("%f",&s.m.comp);
							s.grade.comp=check_grade(s.m.comp);
						break;
					case 4:
						printf("\n\n\t\t\t\t\t\t\tEnter urdu marks : ");
						scanf("%f",&s.m.urdu);
							s.grade.urdu=check_grade(s.m.urdu);
						break;
					case 5:
						printf("\n\n\t\t\t\t\t\t\tEnter history marks : ");
						scanf("%f",&s.m.history);
							s.grade.his=check_grade(s.m.history);
						break;
					case 6:
						printf("\n\n\t\t\t\t\t\t\tEnter english marks : ");
						scanf("%f",&s.m.eng);
							s.grade.eng=check_grade(s.m.eng);
						break;
					default:
						printf("\a");
						printf("\n\n\t\t\t\t\t\t\tInvalid Option");
						modifyMarks();
				}
				s.m.total=s.m.maths+s.m.eng+s.m.history+s.m.urdu+s.m.phy+s.m.comp;
				s.m.avg=s.m.total/6.0;
				s.m.percentage=(s.m.total/600.0)*100.0;
				fseek(fp,-(long)sizeof(s),SEEK_CUR);
				fwrite(&s,(long)sizeof(s),1,fp);
				break;
			       
			}
		}
		fclose(fp);
		
		
		if(found==0)
		{
			printf("\n\n\t\t\t\t\t\t\t\tSorry No Record Found\n\n");
			return;
		}
		else{
			printf("\n\n\t\t\t\t\t\t\tDo you want to modify another marks (y/n) :");
			scanf(" %c",&another);}
	}while(another=='Y' || another=='y' && found==1);

}




void addMarks(){
	FILE *fp;
	struct student s;
	int found=0;
	char id[40],another;
	
	do{
		fp=fopen("information.txt","rb+");
		printf("\n\n\n\t\t\t\t\t\t\tEnter student roll no whose marks you want to add : ");
		fflush(stdin);
		gets(id);
		
		while((fread(&s,sizeof(s),1,fp))>0)
		{
			found=0;
			if(strcmp(s.roll_no,id)==0)
			{	
				if(s.check==1){
					printf("\n\n\t\t\t\t\t\t\tThe Marks For this Student ID have been Added already");
					found=1;
					break;
				}
				s.check=1;
			    found=1;
		        printf("\n\t\t\t\t\t\t\t(Enter all marks out of 100)");
				printf("\n\n\t\t\t\t\t\t\tEnter Maths marks : ");
				scanf("%f",&s.m.maths);
				s.grade.math=check_grade(s.m.maths);/*/ it will return the grade of the maths subject*/
				printf("\n\t\t\t\t\t\t\tEnter Physics marks : ");
				scanf("%f",&s.m.phy);
				s.grade.phy=check_grade(s.m.phy);
				printf("\n\t\t\t\t\t\t\tEnter Computer marks : ");
				scanf("%f",&s.m.comp);
				s.grade.comp=check_grade(s.m.comp);
				printf("\n\t\t\t\t\t\t\tEnter Urdu marks : ");
				scanf("%f",&s.m.urdu);
				s.grade.urdu=check_grade(s.m.urdu);
				printf("\n\t\t\t\t\t\t\tEnter History marks : ");
				scanf("%f",&s.m.history);
				s.grade.his=check_grade(s.m.history);
				printf("\n\t\t\t\t\t\t\tEnter English marks : ");
     		    scanf("%f",&s.m.eng);
				s.grade.eng=check_grade(s.m.eng);
				s.m.total=s.m.maths+s.m.eng+s.m.history+s.m.urdu+s.m.phy+s.m.comp;
				s.m.avg=s.m.total/6.0;
				s.m.percentage=(s.m.total/600.0)*100.0;
				fseek(fp,-(long)sizeof(s),SEEK_CUR);
				fwrite(&s,sizeof(s),1,fp);
		        break;
			}
		}
		
		fclose(fp);
		
		
		if(found==0)
		{
			printf("\n\n\t\t\t\t\t\t\tSorry No Record Found\n\n");
		}
			printf("\n\n\t\t\t\t\t\t\tDo you want to add another student's marks (y/n) :");
			scanf(" %c",&another);
}while(another=='Y' || another=='y');

}


char check_grade(float marks){
	switch((int)marks){
		case 80 ... 100:
			return 'A';
			break;
		case 70 ... 79:
			return 'B';
			break;
		case 60 ... 69:
			return 'C';
			break;
		case 50 ... 59:
			return 'D';
			break;
		case 40 ... 49:
			return 'E';
			break;
		case 0 ... 39:
			return 'F';
			break;
	}
}



void deleteMarks(){
	FILE *fp;
	struct student s;
	int found,choice,ans;
	char id[40], ans2;
	
	printf("\n\n\t\t\t\t\t\t\tEnter student roll no. whose marks you want to delete: ");
	fflush(stdin);
	gets(id);
	printf("\n\n\t\t\t\t\t\t\tDo you want to -->\n\t\t\t\t\t\t\t1) Delete marks of a particular subjects\n\t\t\t\t\t\t\t2) Delete All Subjects Marks \n\n___________\n\t\t\t\t\t\t\tSelect (1/2): ");
	scanf("%d",&ans);
	if(ans==1){
	
		fp=fopen("information.txt","rb+");
		while((fread(&s,sizeof(s),1,fp))>0)
		{
			found=0;
			if(strcmp(s.roll_no,id)==0)
			{
				    found=1;
				    above:
				    here:
					printf("\n\n\t\t\t\t\t\t\tChoose which subject's marks you want to delete: ");
					printf("\n\t\t\t\t\t\t\t\t1.MATHS\n\t\t\t\t\t\t\t\t2.PHYSICS\n\t\t\t\t\t\t\t\t3.COMPUTER\n\t\t\t\t\t\t\t\t4.URDU\n\t\t\t\t\t\t\t\t5.HISTORY\n\t\t\t\t\t\t\t\t6.ENGLISH\n");
					printf("\n\t\t\t\t\t\t\t\t____________\n\n");
					printf("\n\t\t\t\t\t\t\tSelect an Option: ");
					scanf("%d",&choice);
					switch(choice){
					case 1:
					s.m.maths=0;
					s.grade.math=check_grade(s.m.maths);
					break;
					case 2:
					s.m.phy=0;
					s.grade.phy=check_grade(s.m.phy);
					break;
					case 3:
					s.m.comp=0;
					s.grade.comp=check_grade(s.m.comp);
					break;
					case 4:
					s.m.urdu=0;
					s.grade.urdu=check_grade(s.m.urdu);
					break;
					case 5:
					s.m.history=0;
					s.grade.his=check_grade(s.m.history);							
					break;
					case 6:
					s.m.eng=0;
					s.grade.eng=check_grade(s.m.eng);
					break;
					default:
					printf("\n\n\t\t\t\t\t\t\t\tInvalid Option");
					goto here;
					}
					printf("\n\n\t\t\t\t\t\t\t\tSUccessfully Deleted!\n\n\t\t\t\t\t\t\t\tDo you want to delete any other subject marks?(y/n): ");
					fflush(stdin);
					scanf("%c",&ans2);
					if(ans2=='y' || ans2=='Y')
					goto above;
					s.m.total=s.m.maths+s.m.eng+s.m.history+s.m.urdu+s.m.phy+s.m.comp;
					s.m.avg=s.m.total/6;
					s.m.percentage=(s.m.total/600)*100;
					fseek(fp,-(long)sizeof(s),SEEK_CUR);
					fwrite(&s,sizeof(s),1,fp);
					
					break;
			}
		}
		fclose(fp);
		
		if(found==0)
		{
			printf("\n\n\t\t\t\t\t\t\t\tSorry No Record Found\n\n");
		}
	
	}
	else if (ans==2){
		found=0;
		fp=fopen("information.txt","rb+");
		while((fread(&s,sizeof(s),1,fp))>0)
		{
			if(strcmp(s.roll_no,id)==0)
			{
			    found=1;
				s.m.maths=0;
				s.grade.math=check_grade(s.m.maths);
				s.m.phy=0;	
				s.grade.phy=check_grade(s.m.phy);
				s.m.comp=0;
				s.grade.comp=check_grade(s.m.comp);
				s.m.urdu=0;
				s.grade.urdu=check_grade(s.m.urdu);
				s.m.history=0;
				s.grade.his=check_grade(s.m.history);
				s.m.eng=0;
				s.grade.eng=check_grade(s.m.eng);
				s.m.total=0.0;
				s.m.avg=0.0;
				s.m.percentage=0.0;
				fseek(fp,-(long)sizeof(s),SEEK_CUR);
				fwrite(&s,sizeof(s),1,fp);
				printf("\n\n\t\t\t\t\t\t\t\tSuccessfully Deleted!");
				break;
		}
	}
	fclose(fp);
	
	if(found==0)
	{
		printf("\n\n\t\t\t\t\t\t\t\tSorry No Record Found\n\n");
	}
		
	}
	printf("\n\n\t\t\t\t\t\t\t\tPress any key to Continue....");
	


}

void student_menu(char *id2){
	FILE *fp;
	int flag=0;
    struct student info;
    
    while(1){
    	system("cls");
    	printf("\n\n\t\t\t\t\t\t\t\t=========STUDENT PORTAL=========\n\n\n");
    	fp=fopen("information.txt","rb");

     	printf("\n\n\t\t\t\t\t\t\t\t-----------Personal Information-----------\n\n\n");

    	if(fp==NULL){

        	printf("\n\n\t\t\t\tThe owner have not input the data yet\n");
    	}

        while(fread(&info,sizeof(struct student),1,fp)){
        	if (strcmp(info.roll_no,id2)==0){
        		flag=1;
		        printf("\n\t\t\t\t\t\t\t\tStudent Name  : %s %s",info.first_name,info.last_name);
		        printf("\n\t\t\t\t\t\t\t\tRoll NO       : %s",info.roll_no);
		   		 printf("\n\t\t\t\t\t\t\t\tEmail Address : %s",info.email);
		    	printf("\n\t\t\t\t\t\t\t\tPhone number  : %s",info.phone_no);
		        printf("\n\t\t\t\t\t\t\t\tGender        : %s",info.gender);
		        printf("\n\t\t\t\t\t\t\t\tNationality   : %s",info.nationality);
		        printf("\n\t\t\t\t\t\t\t\tDate of birth : %s",info.dob);
		        printf("\n\t\t\t\t\t\t\t\t      ____________\n");
        		break;
         	}

         }
        if (flag==0){
         	system("cls");
         	printf("\n\n\n\n\n\n\t\t\t\t\tThe Teacher have Deleted or Not added your Record in the System. Please Contact your Teacher. Thank you");
         	printf("\n\n\n\t\t\t\t\tPress any key to exit..\n\n");
         	getch();
         	exit(1);
		}
		fclose(fp);

		int choice;
	
    

	printf("\n\n\t\t\t\t\t\t\t\t1.View Marksheet");
	printf("\n\n\t\t\t\t\t\t\t\t2.View attendance");
	printf("\n\n\t\t\t\t\t\t\t\t3.View timetable");
	printf("\n\n\t\t\t\t\t\t\t\t4.Exit\n");
	printf("\t\t\t\t\t\t\t\t_______\n\n");
	printf("\n\n\t\t\t\t\t\t\tSelect an option : ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
				system("cls");
				marksheet2(id2);
				printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");

		          getch();
		          break;
		case 2:
				system("cls");
				search2(id2);
				printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");
				getch();
	    		break;
	    case 3:
	      		system("cls");
				view_timetable();
				printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");
				getch();
	    		break;
        case 4:
	          	exit(0);
	          	break;
        default: 
	        	printf("Invalid Option");
	        	printf("\n\n\t\t\t\t\t\t\t\t  Press any key to exit.......\n");
	       		getch();
	       		break;
}}}

  void marksheet2(char *id2)
{
	FILE *fp,*fp1;
	struct student s;
	int found=0;
	char id[40];
	fp=fopen("information.txt","rb");
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		if(strcmp(s.roll_no,id2)==0)
	{
			found=1;
			system("cls");
	    	printf("\n\n\n\t\t\t\t ------------------------------------------------------------------------------------\n");
		    printf("\t\t\t\t|                               MARKSHEET                                            |\n");
		    printf("\t\t\t\t|------------------------------------------------------------------------------------\n");
		    printf("\t\t\t\t| Your name: %s %s\t\tRoll Number: %s\n\n", s.first_name,s.last_name,s.roll_no);
		  
		    printf("\t\t\t\t|------------------------------------------------------------------------------------\n");
		    printf("\t\t\t\t|\tSUBJECTS      \tMAX MARKS\tMIN MARKS\tOBTAINED MARKS\t\tGRADE\n");
		    printf("\t\t\t\t|-------------------------------------------------------------------------------------\n");
		    printf("\t\t\t\t|\tMATHS         \t  100      \t   39       \t    %.2f       \t  %c\n", s.m.maths,s.grade.math);
		    printf("\t\t\t\t|\tENGLISH       \t  100      \t   39       \t    %.2f       \t  %c\n", s.m.eng,s.grade.eng);
		    printf("\t\t\t\t|\tURDU          \t  100      \t   39       \t    %.2f       \t  %c\n", s.m.urdu,s.grade.urdu);
		    printf("\t\t\t\t|\tHISTORY       \t  100      \t   39       \t    %.2f       \t  %c\n", s.m.history,s.grade.his);
		    printf("\t\t\t\t|\tPHYSICS       \t  100      \t   39       \t    %.2f       \t  %c\n", s.m.phy,s.grade.phy);
		    printf("\t\t\t\t|\tCOMPUTER      \t  100      \t   39       \t    %.2f       \t  %c\n", s.m.comp,s.grade.comp);
		    printf("\t\t\t\t|------------------------------------------------------------------------------------\n");
		    printf("\t\t\t\t|\t              \t  600    |    GRAND TOTAL\t    %.2f\n",s.m.total);
		    printf("\t\t\t\t|\t              \t         |    PERCENTAGE \t    %.2f\n",s.m.percentage);
		    printf("\t\t\t\t|------------------------------------------------------------------------------------\n");
		    
		     if (s.m.percentage >= 80 && s.m.percentage <= 100)
		    {
		        
		        printf("\t\t\t\t|GRADE  : A+\n");
		    }
		    if (s.m.percentage >= 70 && s.m.percentage < 80)
		    {
		        
		        printf("\t\t\t\t|GRADE  : A\n");
		    }
		    else if (s.m.percentage >= 60 && s.m.percentage <70)
		    {
		        
		        printf("\t\t\t\t|GRADE  : B\n");
		    }
		    else if (s.m.percentage >= 49 && s.m.percentage <60)
		    {
		        
		        printf("\t\t\t\t|GRADE  : C\n");
		    }
		    else if (s.m.percentage >=40 && s.m.percentage <49)
		    {
		       
		        printf("\t\t\t\t|GRADE  : D\n");
		    }
		    else if (s.m.percentage >=0 && s.m.percentage <40)
		    {
		       
		        printf("\t\t\t\t|GRADE  : F\n");
		    }
			printf("\t\t\t\t|------------------------------------------------------------------------------------\n");
		}
	}
	if(found==0)
	{
		printf("\n\n\t\t\t\t\t\t\tSorry No Record Found");
	}
	fclose(fp);


}
void search2(char *id2){
	struct student info;
	struct items attendance;
	int total=0,p=0,a=0;
	char id[15],ans;
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t\t\t>> Attendance <<");
	FILE *fp,*fp2;
	fp2=fopen("date.txt","rb");
	fp=fopen("information.txt","rb");
	if(fp2==NULL || fp==NULL){
		printf("\n\n\t\t\t\tThe Teacher have not input Attendance for Any Date in the System Yet");
		student_menu(id2);
	}
	printf("\n\n");
	while(fread(&info,sizeof(struct student),1,fp)>0){
		if((strcmp(id2,info.roll_no))==0){
		printf("\n\n\t\t\t\t\t\t\t\tStudent Name  : %s %s",info.first_name,info.last_name);
		printf("\n\n\t\t\t\t\t\t\t\tStudent ID    : %s\n",info.roll_no);
	   
	}
	}
	while(fread(&attendance,sizeof(struct items),1,fp2)>0){
		if((strcmp(id2,attendance.roll_no))==0 && attendance.marked!='\0'){
			total++;
			if(attendance.marked=='p' || attendance.marked=='P')
				p++;
			else
				a++;
		}
	}
	fclose(fp);
    rewind(fp2);
	printf("\n\t\t\t\t\t\t\t\tTotal Classes: %d",total);
	printf("\n\t\t\t\t\t\t\t\tPresent: %d",p);
	printf("\n\t\t\t\t\t\t\t\tAbsent: %d",a);
	printf("\n\t\t\t\t\t\t\t\tAttendance Mark(out of 100%): %.0f",((p*1.0/total*1.0)*100.0));
	printf("\n\n\t\t\t\t\t\t\t\tDo You Want To View Attendance Details[y/n]: ");
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='y'){
		while(fread(&attendance,sizeof(struct items),1,fp2)>0){
			if((strcmp(id2,attendance.roll_no))==0 && attendance.marked!='\0'){
				if(attendance.marked=='p'||attendance.marked=='P')
					printf("\n\t\t\t\t\t\t\t\t%s: Present",attendance.date);
				else
					printf("\n\t\t\t\t\t\t\t\t%s: Absent",attendance.date);
			}
		}
	}
	fclose(fp2);
}


void view_timetable(){

	int i=1;
	FILE*fp;
	
	fp=fopen("timetable12.csv","r");
	
	if(fp==NULL){
		printf("ERROR IN OPENING FILE!");
		exit(1);
	}
	
	 
	char period[20],mon[20],tue[20],wed[20],thur[20],fri[20];
	
	char line[200];
	
	char *sp;
	/*/printf("%s|%20s|%20s|%24s|%20s|%20s|","PERIOD",",MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY");*/
	
	printf("\n\n\t\t\t\t<--------------------------------STUDENTS TIME TABLE------------------------------------->\n\n\n");
	while(fgets(line,200,fp)!=NULL){
		
		sp=strtok(line,",");
		strcpy(period,sp);  /*/ strtok is function which return the base address of the first character of the token.*/
	
		sp=strtok(NULL,",");
		strcpy(mon,sp);
		
		sp=strtok(NULL,",");
		strcpy(tue,sp);
		
		sp=strtok(NULL,",");
		strcpy(wed,sp);
		
		sp=strtok(NULL,",");
		strcpy(thur,sp);	
		
		sp=strtok(NULL,",");
		strcpy(fri,sp);
		
		if(i==1){
			printf("________________________________________________________________________________________________________________________________________________________________________");
			
		}
		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("|%11s|%30s|%30s|%30s|%30s|%30s|",period,mon,tue,wed,thur,fri);
		if(i==1){
			printf("________________________________________________________________________________________________________________________________________________________________________");
			puts("");
		}
		i++;
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	fclose(fp);
	
}


void stats(){
	struct student s;
	int i;
	float arr_max[6]={0};
	float arr_min[6];
	for(i=0;i<6;i++)
		arr_min[i]=100.0;
	float arr_total[6]={0.0};
	char arr_roll[6][20];
	char arr_fname[6][20];
	char arr_lname[6][20];
	char arr2_roll[6][20];
	char arr2_fname[6][20];
	char arr2_lname[6][20];
	int arr_f[6]={0};
	int arr_p[6]={0};
	int ctr=0;
	
	FILE *fp;
	fp=fopen("information.txt","rb");
	while(fread(&s,sizeof(s),1,fp)>0){
		arr_total[0]=arr_total[0]+s.m.phy;
		if(s.m.phy>arr_max[0]){
			arr_max[0]=s.m.phy;
			strcpy(arr_roll[0],s.roll_no);
			strcpy(arr_fname[0],s.first_name);
			strcpy(arr_lname[0],s.last_name);
			
		}
		if(s.m.phy<arr_min[0]){
			arr_min[0]=s.m.phy;
			strcpy(arr2_fname[0],s.first_name);
			strcpy(arr2_lname[0],s.last_name);
			strcpy(arr2_roll[0],s.roll_no);
		}
		if(s.m.phy<=39){
			arr_f[0]++;
		}
		if (s.m.phy>39){
			arr_p[0]++;
		}
		arr_total[1]=arr_total[1]+s.m.comp;
		if(s.m.comp>arr_max[1]){
			arr_max[1]=s.m.comp;
			strcpy(arr_roll[1],s.roll_no);
			strcpy(arr_fname[1],s.first_name);
			strcpy(arr_lname[1],s.last_name);
			
		}
		if(s.m.comp<arr_min[1]){
			arr_min[1]=s.m.comp;
			strcpy(arr2_fname[1],s.first_name);
			strcpy(arr2_lname[1],s.last_name);
			strcpy(arr2_roll[1],s.roll_no);
		}
		if(s.m.comp<=39){
			arr_f[1]++;
		}
		if(s.m.comp>39){
			arr_p[1]++;
		}
		arr_total[2]=arr_total[2]+s.m.maths;
		if(s.m.maths>arr_max[2]){
			arr_max[2]=s.m.maths;
			strcpy(arr_fname[2],s.first_name);
			strcpy(arr_lname[2],s.last_name);
			strcpy(arr_roll[2],s.roll_no);
			
			
		}
		if(s.m.maths<arr_min[2]){
			arr_min[2]=s.m.maths;
			strcpy(arr2_fname[2],s.first_name);
			strcpy(arr2_lname[2],s.last_name);
			strcpy(arr2_roll[2],s.roll_no);
		}
		if(s.m.maths<=39){
			arr_f[2]++;
		}
		if(s.m.maths>39){
			arr_p[2]++;
		}
		arr_total[3]=arr_total[3]+s.m.maths;
		if(s.m.eng>arr_max[3]){
			arr_max[3]=s.m.eng;
			strcpy(arr_fname[3],s.first_name);
			strcpy(arr_lname[3],s.last_name);
			strcpy(arr_roll[3],s.roll_no);
			
			
		}
		if(s.m.eng<arr_min[3]){
			arr_min[3]=s.m.eng;
			strcpy(arr2_fname[3],s.first_name);
			strcpy(arr2_lname[3],s.last_name);
			strcpy(arr2_roll[3],s.roll_no);
		}
		if(s.m.eng<=39){
			arr_f[3]++;
		}
		if (s.m.eng>39){
			arr_p[3]++;
		}
		arr_total[4]=arr_total[4]+s.m.history;
		if(s.m.history>arr_max[4]){
			arr_max[4]=s.m.history;
			strcpy(arr_fname[4],s.first_name);
			strcpy(arr_lname[4],s.last_name);
			strcpy(arr_roll[4],s.roll_no);
			
			
		}
		if(s.m.history<arr_min[4]){
			arr_min[4]=s.m.history;
			strcpy(arr2_fname[4],s.first_name);
			strcpy(arr2_lname[4],s.last_name);
			strcpy(arr2_roll[4],s.roll_no);
		}
		if(s.m.history<=39){
			arr_f[4]++;
		}
		if (s.m.history>39){
			arr_p[4]++;
		}
		arr_total[5]=arr_total[5]+s.m.urdu;
		if(s.m.urdu>arr_max[5]){
			arr_max[5]=s.m.urdu;
			strcpy(arr_fname[5],s.first_name);
			strcpy(arr_lname[5],s.last_name);
			strcpy(arr_roll[5],s.roll_no);
			
			
		}
		if(s.m.urdu<arr_min[5]){
			arr_min[5]=s.m.urdu;
			strcpy(arr2_fname[5],s.first_name);
			strcpy(arr2_lname[5],s.last_name);
			strcpy(arr2_roll[5],s.roll_no);
		}
		if(s.m.urdu<=39){
			arr_f[5]++;
		}
		if(s.m.urdu>39){
			arr_p[5]++;
		}
		ctr++;
		
}
	rewind(fp);
	float max=0.0,min=100.0;
	char fname[2][20],lname[2][20],roll[2][20];
	int f=0,p=0,a=0;
	while(fread(&s,sizeof(s),1,fp)>0){
		if(s.m.percentage>max){
			max=s.m.percentage;
			strcpy(fname[0],s.first_name);
			strcpy(lname[0],s.last_name);
			strcpy(roll[0],s.roll_no);
		}
		if(s.m.percentage<min){
			min=s.m.percentage;
			strcpy(fname[1],s.first_name);
			strcpy(lname[1],s.last_name);
			strcpy(roll[1],s.roll_no);
		}
		if(s.m.percentage<=39.0){
			f++;
		}
		if (s.m.percentage>=80.0){
			p++;
		}
		if (s.m.percentage>39.0 && s.m.percentage<80.0 ){
			a++;
		}
		
	}
		printf("\n\n\n\t\t\t\t\t-----------------------------------------------------------------------------------------------\n");
	    printf("\t\t\t\t\t|                                   STATSTICS OF CLASS                                        |\n");
	    printf("\t\t\t\t\t-----------------------------------------------------------------------------------------------\n");
	    printf("\n\n\n\t\t\t\t\t\t---------------------\n");
	    printf("\t\t\t\t\t\t|     PHYSICS       |\n");
	    printf("\t\t\t\t\t\t---------------------\n");
		printf("\t\t\t\t\t\tPHYSICS:\n");
	    printf("\t\t\t\t\t\tMaximum marks            : %.0f --->ID: %s (%s %s)\n",arr_max[0],arr_roll[0],arr_fname[0],arr_lname[0]);
	    printf("\t\t\t\t\t\tMinimum marks            : %.0f --->ID: %s (%s %s)\n",arr_min[0],arr2_roll[0],arr2_fname[0],arr2_lname[0]);
	    printf("\t\t\t\t\t\tAverage marks            : %.0f\n",arr_total[0]/(ctr));
	    printf("\t\t\t\t\t\tNumber of passed students: %d\n",arr_p[0]);
	    printf("\t\t\t\t\t\tNumber of failed students: %d\n",arr_f[0]);
	    printf("\t\t\t\t\t\t______________________________________\n");
	   
	   
	    printf("\n\n\n\t\t\t\t\t\t----------------------\n");
	    printf("\t\t\t\t\t\t|     COMPUTER       |\n");
	    printf("\t\t\t\t\t\t----------------------\n"); 
	    printf("\t\t\t\t\t\tMaximum marks            : %.0f --->ID: %s (%s %s)\n",arr_max[1],arr_roll[1],arr_fname[1],arr_lname[1]);
	    printf("\t\t\t\t\t\tMinimum marks            : %.0f --->ID: %s (%s %s)\n",arr_min[1],arr2_roll[1],arr2_fname[1],arr2_lname[1]);
	    printf("\t\t\t\t\t\tAverage marks            : %.0f\n",arr_total[1]/(ctr));
	    printf("\t\t\t\t\t\tNumber of passed students: %d\n",arr_p[1]);
	    printf("\t\t\t\t\t\tNumber of failed students: %d\n",arr_f[1]);
		printf("\t\t\t\t\t\t______________________________________\n");
		
		
		printf("\n\n\n\t\t\t\t\t\t-------------------\n");
	    printf("\t\t\t\t\t\t|     MATHS       |\n");
	    printf("\t\t\t\t\t\t-------------------\n");
	    printf("\t\t\t\t\t\tMaximum marks            : %.0f --->ID: %s (%s %s)\n",arr_max[2],arr_roll[2],arr_fname[2],arr_lname[2]);
	    printf("\t\t\t\t\t\tMinimum marks            : %.0f --->ID: %s (%s %s)\n",arr_min[2],arr2_roll[2],arr2_fname[2],arr2_lname[2]);
	    printf("\t\t\t\t\t\tAverage marks            : %.0f\n",arr_total[2]/(ctr));
	    printf("\t\t\t\t\t\tNumber of passed students: %d\n",arr_p[2]);
	    printf("\t\t\t\t\t\tNumber of failed students: %d\n",arr_f[2]);
		printf("\t\t\t\t\t\t______________________________________\n");
		
		
		printf("\n\n\n\t\t\t\t\t\t--------------------\n");
	    printf("\t\t\t\t\t\t|     ENGLISH       |\n");
	    printf("\t\t\t\t\t\t---------------------\n");
		
	    printf("\t\t\t\t\t\tMaximum marks            : %.0f --->ID: %s (%s %s)\n",arr_max[3],arr_roll[3],arr_fname[3],arr_lname[3]);
	    printf("\t\t\t\t\t\tMinimum marks            : %.0f --->ID: %s (%s %s)\n",arr_min[3],arr2_roll[3],arr2_fname[3],arr2_lname[3]);
	    printf("\t\t\t\t\t\tAverage marks            : %.0f\n",arr_total[3]/(ctr));
	    printf("\t\t\t\t\t\tNumber of passed students: %d\n",arr_p[3]);
	    printf("\t\t\t\t\t\tNumber of failed students: %d\n",arr_f[3]);
		printf("\t\t\t\t\t\t______________________________________\n");
		
		
		printf("\n\n\n\t\t\t\t\t\t---------------------\n");
	    printf("\t\t\t\t\t\t|     HISTORY       |\n");
	    printf("\t\t\t\t\t\t---------------------\n");
		
	    printf("\t\t\t\t\t\tMaximum marks            : %.0f --->ID: %s (%s %s)\n",arr_max[4],arr_roll[4],arr_fname[4],arr_lname[4]);
	    printf("\t\t\t\t\t\tMinimum marks            : %.0f --->ID: %s (%s %s)\n",arr_min[4],arr2_roll[4],arr2_fname[4],arr2_lname[4]);
	    printf("\t\t\t\t\t\tAverage marks            : %.0f\n",arr_total[4]/(ctr));
	    printf("\t\t\t\t\t\tNumber of passed students: %d\n",arr_p[4]);
	    printf("\t\t\t\t\t\tNumber of failed students: %d\n",arr_f[4]);
		printf("\t\t\t\t\t\t______________________________________\n");
		
		
		printf("\n\n\n\t\t\t\t\t\t------------------\n");
	    printf("\t\t\t\t\t\t|     URDU       |\n");
	    printf("\t\t\t\t\t\t------------------\n");
		printf("\t\t\t\t\t\tURDU:\n");
	    printf("\t\t\t\t\t\tMaximum marks            : %.0f --->ID: %s (%s %s)\n",arr_max[5],arr_roll[5],arr_fname[5],arr_lname[5]);
	    printf("\t\t\t\t\t\tMinimum marks            : %.0f --->ID: %s (%s %s)\n",arr_min[5],arr2_roll[5],arr2_fname[5],arr2_lname[5]);
	    printf("\t\t\t\t\t\tAverage marks            : %.0f\n",arr_total[5]/(ctr));
	    printf("\t\t\t\t\t\tNumber of passed students: %d\n",arr_p[5]);
	    printf("\t\t\t\t\t\tNumber of failed students: %d\n",arr_f[5]);	
	    
	    printf("\n\n\n\t\t\t\t|---------------------------------------------------------------------------------------------------|\n");
	    printf("\n\n\n\t\t\t\t\t\t|   Highest Percentage             : %.2f  by %s %s (ID: %s)\n",max,fname[0],lname[0],roll[0]);
	    printf("\t\t\t\t\t\t|   Lowest Percentage              : %.2f % by %s %s (ID: %s)\n",min,fname[1],lname[1],roll[1]);
	    printf("\t\t\t\t\t\t|   No.of Excellent Students       : %d\n",p);
	    printf("\t\t\t\t\t\t|   No.of Average Students         : %d\n",a);
	    printf("\t\t\t\t\t\t|   No.of Failed Students          : %d\n",f);  
	    printf("\n\n\n\t\t\t\t|---------------------------------------------------------------------------------------------------|\n");
    
  
}
