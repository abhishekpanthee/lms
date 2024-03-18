#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"lms.c"

void password_taker(char []);
void exit_program();
void change_student_password();
void change_teacher_password();
void reg();
void show();
void tshow();
void giveassign();
void seeassign();
void admindatashow();
void studentsearch();
void loginto();

struct student {
    char id[10];
    char password[10];
    char num[30];
    char faculty[30];
    char name[15];
};

struct admin {
    char id[10];
    char password[10];
    char name[15];
};

struct teach {
    char id[10];
    char password[10];
    char name[15];
    char num[20];
    char sub[20];
};

struct assign {
    char sub1[100];
    char sub2[100];
    char sub3[100];
    char sub4[100];
    char sub5[100];
    char sub6[100];
};

void password_taker(char password[]){
 //subtitiuitng every charcter by *

    char ch;        
    int charposition=0;  

    while(1)
    {
        ch=getch();
        if (ch==13){     
            password[charposition]='\0';
            break;
        }
        else if (ch==8)       // if user enters backspace, it will delete current character
            {
                if (charposition >0)
                {
                    charposition--;
                    password[charposition]='\0';
                    printf("\b \b");
                }
            }
            else if (ch==32 || ch==9)    // if user enters tab or space
                continue;
            else{
                password[charposition]=ch;
                charposition++;
                printf("*");
                }
    }
}


void reg(){
	system("cls");
	signup();
	
    int n;
    printf("\n*1.----------------Administration----------------\n");
    printf("\n*2.---------------------Teacher--------------------\n");
    printf("\n*3.---------------------Student--------------------\n");
    printf("\nChoose : \n");
    scanf("%d", &n);

    if(n == 3){
        struct student f;
        FILE *fp;
        student();
        fp = fopen("stu.txt","a");
        if(fp == NULL){
            printf("\nError opening file.");
            return;
        }

        printf("Enter ID: ");
        scanf("%s", f.id);

        printf("\nEnter Password: ");
        password_taker(f.password);

        printf("\nEnter Name: ");
        scanf("%s", f.name);

        printf("\nEnter Phone Number: ");
        scanf("%s", f.num);

        printf("\nEnter Your Faculty: ");
        scanf("%s", f.faculty);

        fwrite(&f, sizeof(f), 1, fp);
        fclose(fp);
    }
    else if(n == 1){
        struct admin f;
        FILE *fp;
        admin();
        fp = fopen("adm.txt","a");
        if(fp == NULL){
            printf("\nError opening file.");
            return;
        }

        printf("\nEnter ID: ");
        scanf("%s", f.id);

        printf("\nEnter Password: ");
        password_taker(f.password);

        printf("\nEnter Name: ");
        scanf("%s", f.name);

        fwrite(&f, sizeof(f), 1, fp);
        fclose(fp);
    }
    else if(n == 2){
        struct teach f;
        FILE *fp;
        teacher();
        fp = fopen("teacher.txt","a");
        if(fp == NULL){
            printf("\nError opening file.");
            return;
        }

        printf("\nEnter ID: ");
        scanf("%s", f.id);

        printf("\nEnter your subject: ");
        scanf("%s", f.sub);

        printf("\nEnter phone number: ");
        scanf("%s", f.num);

        printf("\nEnter Password: ");
        password_taker(f.password);

        printf("\nEnter Name: ");
        scanf("%s", f.name);

        fwrite(&f, sizeof(f), 1, fp);
        fclose(fp);
    }
    else{
        printf("\nInvalid choice.");
    }
}

void show(){
    int i=1;
    FILE *fp;
    struct student s;
    fp=fopen("stu.txt","r");
    if(fp==NULL){
        printf("\n**ERROR IN READING DATA**");
    }

    printf("\nSTUDENT DATA :- \n");
    while(fread(&s,sizeof(s),1,fp)){
    		printf("-------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \t\t NUMBER \t faculty  \t PASSWORD  ");
    	printf("-------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t\t%s \t +977%s \t % \t %s\n",i,s.name,s.id,s.num,s.faculty,s.password);
        printf("-------------------------------------------------------------\n");
        i++;
    }
    fclose(fp);
}
void tshow(){

    int  i=1;
    FILE *fp;
    struct teach f;
    fp=fopen("teacher.txt","r");
    if(fp==NULL){
        printf("\n**ERROR IN READING DATA**");
    }

    printf("\nTeachers data :- \n");
    while(fread(&f,sizeof(f),1,fp)){
    	printf("-------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \t\t NUMBER \t SUBJECT \t PASSWORD  ");
    	printf("-------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t\t%s \t +977%s \t % \t %s\n",i,f.name,f.id,f.num,f.sub,f.password);
        printf("-------------------------------------------------------------\n");
        i++;
    }
    fclose(fp);
}

void giveassign(){
    char assign[200];
    struct assign n;
    FILE *fp;
    fp=fopen("assign.txt","a");
//limitations(flaw) all teachers can give any subject assigment 
    int s=1;
    printf("\n Choose the subject for the assigment ");
    scanf("%d",&s);

    if(s==1){
        printf("\nEnter Assigments for Physics ");
        scanf("%s",&n.sub1);

    }
    else if(s==2){
        printf("\nEnter Assigments for Workshop: ");
        scanf("%s",&n.sub2);
    }
    else if(s==3){
        printf("\nEnter Assigments for Physics:  ");
        scanf("%s",&n.sub3);
    }
       else if(s==4)
       {
        printf("\nEnter Assignments for C-programming ");
        scanf("%s",&n.sub4);
}
    else if(s==5){
        printf("\nEnter Assigments for Fundamentals of electrical and ELctronics : ");
        scanf("%s",&n.sub5);
		   }
    else if(s==6){
        printf("\nEnter Assigments for maths  ");
        scanf("%s",&n.sub6);
    }
    else{
        printf("\nError Input\n");
    }

    fwrite(&n,sizeof(n),1,fp);
    printf("\n!!!DATA HAS BEEN SHARED!!!\n");
    fclose(fp);




}
void seeassign(){
    FILE *fp;
    fp=fopen("assign.txt","r");
    struct assign n;

    int s;
    printf("\nEnter Subject Number : 1-3\n");
    scanf("%d",&s);

    int i=1;

    while(fread(&n , sizeof(n),1,fp)){

        if(s==1){
            printf("\t%d\t%s\n",i,n.sub1);
            i++;

        }
        else if(s==2){
            printf("\t%d\t%s\n",i,n.sub2);
            i++;

        }
        else if(s==3){
            printf("\t%d\t%s\n",i,n.sub3);
            i++;
        }
         else if(s==4){
            printf("\t%d\t%s\n",i,n.sub4);
            i++;
        }
         else if(s==5){
            printf("\t%d\t%s\n",i,n.sub5);
            i++;
        }
         else if(s==6){
            printf("\t%d\t%s\n",i,n.sub6);
            i++;
        }
        else{
            printf("\nError Input\n");
        }


    }


    fclose(fp);

}
void admindatashow(){
    struct admin f;
    FILE *fp;
    fp=fopen("adm.txt","r");

    int i=1;
    while(fread(&f , sizeof(f),1,fp)){
    	printf("-------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \n  ");
    	printf("-------------------------------------------------------------\n");
        printf("\t%d\t\t%s\n",i,f.name);
       	printf("-------------------------------------------------------------\n");
        i++;
    }
    fclose(fp);
}
void studentsearch(){
	int i=1;
    struct student s;
    FILE *fp;
    fp=fopen("stu.txt","r");
    char id[10];
    printf("\nEnter ID To Search : ");
    scanf("%s",&id);
    int found=0;
    while(fread(&s,sizeof(s),1,fp)){
        if(strcmp(id,s.id)==0){
       	found=1;
       	printf("-------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \t\t NUMBER \t faculty  \t PASSWORD  ");
    	printf("-------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t\t%s \t +977%s \t % \t %s\n",i,s.name,s.id,s.num,s.faculty,s.password);
        printf("-------------------------------------------------------------\n");
        i++;
        }
    }
    if(found==0){
        printf("\n*Data_Not_Found");
    }
}
void teachersearch(){
	int i=1;
    struct teach s;
    FILE *fp;
    fp=fopen("teacher.txt","r");
    char id[10];
    printf("\nEnter ID To Search : ");
    scanf("%s",&id);
    int found=0;
    while(fread(&s,sizeof(s),1,fp)){
        if(strcmp(id,s.id)==0){
            found=1;
           	printf("-------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \t\t NUMBER \t SUBJECT \t PASSWORD  ");
    	printf("-------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t\t%s \t +977%s \t % \t %s\n",i,s.name,s.id,s.num,s.sub,s.password);
        printf("-------------------------------------------------------------\n");
        i++;
        }
    }
    if(found==0){
        printf("\n*Data_Not_Found\n \n ");
    }
}
void loginto() {
	system("cls");
	signin();
    int n;
    int login, a;
    printf("\n*1. Administration");
    printf("\n*2. Teacher");
    printf("\n*3. Student");
    printf("\nChoose: ");
    scanf("%d", &n);
    if (n == 1) {
    	admin();
        struct admin f;
        char id[10];
        char password[10];

        printf("\nEnter ID: ");
        scanf("%s", id);
        printf("\nEnter Password: ");
        password_taker(password);

        FILE *fp;
        fp = fopen("adm.txt", "r");
        if (fp == NULL) {
            printf("\n**ERROR IN READING DATA**");
        }
        while (fread(&f, sizeof(f), 1, fp)) {
            if (strcmp(password, f.password) == 0 && strcmp(id, f.id) == 0) {
                printf("\n**LOGGED IN**\\n\n\n");
                login = 1;
            }
        }
        fclose(fp);

        if (login == 1) {
        	system("cls");
        	admin();
        	admin:
            printf("\n1. SHOW STUDENT DATA");
            printf("\n2. SHOW TEACHERS DATA");
            printf("\n3. SEARCH TEACHER ID");
            printf("\n4. SEARCH WITH STUDENT ID");
            printf("\n5. Change student password");
            printf("\n6. Change Teacher Password");
            printf("\n7. Show Admin Data");
            printf("\n8. EXIT");
            printf("\nChoose: ");
            scanf("%d", &a);
            if (a == 1) {
                show();
            }
			 else if (a == 2) {
                tshow();
			}
			 else if (a == 3) {
                teachersearch();
            }
			 else if (a == 4) {
                studentsearch();
            }
			 else if (a == 5) {
                change_student_password();
            }
			 else if (a == 6) {
                change_teacher_password();
            }
			 else if (a == 7) {
                admindatashow();
            }
			 else if (a == 8) {
                main();
            }
			 else {
                printf("\n***WRONG INPUT***\n");
            }
            goto admin;
        }
		 else {
            printf("\nWRONG USERNAME/PASSWORD\n\n");
        }
    }
	 else if (n == 2) {
	 	student();
        struct student s;
        char id[10];
        char password[10];

        printf("\nEnter ID: ");
        scanf("%s", id);
        printf("\nEnter Password: ");
        password_taker(password);

        FILE *fp;
        fp = fopen("stu.txt", "r");
        if (fp == NULL) {
            printf("\n**ERROR IN READING DATA**\n\n");
        }
        while (fread(&s, sizeof(s), 1, fp)) {
            if (strcmp(password, s.password) == 0 && strcmp(id, s.id) == 0) {
                printf("\n\n\n**LOGGED IN**\n\n\n");
                login = 1;
                break;
            }
        }
        fclose(fp);

        if (login != 1) {
            printf("\nWRONG USERNAME/PASSWORD");
        }
        system("cls");
        student();
		student:
        printf("\n1. Show Teacher Subjects And Names");
        printf("\n2. Show Assignments");
        printf("\n3. Exit");
        printf("\nChoose: ");
        scanf("%d", &a);
        if (a == 1) {
            tshow();
        }
        
		 else if (a == 2) {
            seeassign();
        }
        
		 else if (a == 3) {
            main();
        }
        
		 else {
            printf("\n-----Wrong Choice-------\n\n]m");
        }
        goto student;
    }
	 else if (n == 3) {
        struct teach f;
        char id[10];
        char password[10];
        teacher();
        printf("\nEnter ID: ");
        scanf("%s", id);
        printf("\nEnter Password: ");
        password_taker(password);

        FILE *fp;
        fp = fopen("teach.txt", "r");
        if (fp == NULL) {
            printf("\n**ERROR IN READING DATA**\n\n");
        }
        while (fread(&f, sizeof(f), 1, fp)) {
            if (strcmp(password, f.password) == 0 && strcmp(id, f.id) == 0) {
                printf("\n\n\n**LOGGED IN**\n\n");
                login = 1;
            }
        }
        fclose(fp);

        if (login != 1) {
            printf("\nWRONG USERNAME/PASSWORD\n\n");
        }
        system("cls");
      teacher();
        teacher:
        printf("\n1. SHOW STUDENTS DETAILS");
        printf("\n2. GIVE ASSIGNMENTS");
        printf("\n3. SEARCH WITH STUDENT ID");
        printf("\n4. CHANGE YOUR STUDENT PASSWORD");
        printf("\n4. EXIT");
        printf("\nChoose: ");
        scanf("%d", &a);
        if (a == 1) {
            show();
        } 
		else if (a == 2) {
            giveassign();
		} 
		else if (a == 3) {
            studentsearch();
        }
		 else if (a == 4) {
          change_student_password();
        }
         else if (a == 5) {
            main();
        }
        goto teacher;
    } else {
        printf("\n***WRONG INPUT***");
    }
}

 
int main(){
    int n=1;
    system("cls");
    lms();

    while(n!=0){
        printf("\n\n***WELCOME TO LMS***");
        printf("\n1.SIGN IN\n2.SIGN UP\n\n0.Exit\n");
        printf("\nChoose : \n");
        scanf("%d",&n);
        char password[10];
        if(n==2){
            reg();
        }
        else if(n==1){
            loginto();
        }

        else if (n==0){
            exit_program();
        }
        else{
            printf("\n*****_WRONG_INPUT_*****\n");

        }
    }
    return 0;
}
void change_student_password() {
    char id[10];
    char new_password[10];

    printf("\nEnter the ID of the student whose password you want to change: ");
    scanf("%s", id);

    struct student s;
    FILE *fp;
    fp = fopen("stu.txt", "r+");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**");
        return;
    }

    int found = 0;
    FILE *temp_fp;
    temp_fp = fopen("temp.txt", "w"); // Temporary file to store modified data
    if (temp_fp == NULL) {
        printf("\n**ERROR IN TEMPORARY FILE**");
        fclose(fp);
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        if (strcmp(id, s.id) == 0) {
            found = 1;
            printf("\nEnter the new password for student %s: ", s.name);
            password_taker(new_password);
            strcpy(s.password, new_password);
        }
        fwrite(&s, sizeof(s), 1, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    if (!found) {
        printf("\nStudent with ID %s not found.\n", id);
        remove("temp.txt"); // Delete temporary file
        return;
    }

    if (remove("stu.txt") == 0 && rename("temp.txt", "stu.txt") == 0) {
        printf("\nPassword changed successfully for student %s.\n", s.name);
    } else {
        printf("\n**ERROR IN CHANGING PASSWORD**");
    }
}
void change_teacher_password() {
    char id[10];
    char new_password[10];

    printf("\nEnter the ID of the teacher whose password you want to change: ");
    scanf("%s", id);

    struct teach f;
    FILE *fp;
    fp = fopen("teacher.txt", "r+");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**");
        return;
    }

    int found = 0;
    FILE *temp_fp;
    temp_fp = fopen("temp.txt", "w"); // Temporary file to store modified data
    if (temp_fp == NULL) {
        printf("\n**ERROR IN TEMPORARY FILE**");
        fclose(fp);
        return;
    }

    while (fread(&f, sizeof(f), 1, fp)) {
        if (strcmp(id, f.id) == 0) {
            found = 1;
            printf("\nEnter the new password for teacher %s: ", f.name);
            password_taker(new_password);
            strcpy(f.password, new_password);
        }
        fwrite(&f, sizeof(f), 1, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    if (!found) {
        printf("\nTeacher with ID %s not found.\n", id);
        remove("temp.txt"); 
        return;
    }

    if (remove("teacher.txt") == 0 && rename("temp.txt", "teacher.txt") == 0) {
        printf("\nPassword changed successfully for teacher %s.\n", f.name);
    } else {
        printf("\n**ERROR IN CHANGING PASSWORD**");
    }
}


void exit_program(){
    system("cls");
    printf("\n\n\t-------------LEAVING ALREADY------------\n");
    printf("\tCreated  by:\n");
    printf("\tABHISHEK PANTHEE\t(080BCT002)\n");
    printf("\tSULAV PAUDEL\t(080BCT00)\n");
    printf("\tABHISHEK BHATTARAI\t(080BCT001)\n");
    printf("\tPRASIDDHA RAJ PAUDEL\t(080BCT0)\n");
    exitsed();
    exit(0);
}
