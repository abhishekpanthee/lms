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
void tstudentshow();

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

        printf("\n\nEnter Name: ");
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

        printf("\n\n Enter Name: ");
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

        printf("\n\nEnter Name: ");
        scanf("%s", f.name);

        fwrite(&f, sizeof(f), 1, fp);
        fclose(fp);
    }
    else{
        printf("\nInvalid choice.");
    }
}

void loginto() {
	system("cls");
	signin();
    int n;
    int login, a;
    printf("\n*1. Administration");
    printf("\n*2. Student");
    printf("\n*3. Teacher");
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
            printf("\n3. SEARCH  WITH TEACHER ID");
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
    } else {
        int login = 0;
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
        } else {
            system("cls");
            student();
            int a;
            student_menu:
            printf("\n1. Show Teacher Subjects And Names");
            printf("\n2. Show Assignments");
            printf("\n3. Exit");
            printf("\nChoose: ");
            scanf("%d", &a);
            if (a == 1) {
                tstudentshow();
            } else if (a == 2) {
                seeassign();
            } else if (a == 3) {
                main();
            } else {
                printf("\n-----Wrong Choice-------\n\n");
                goto student_menu;
            }
       goto student_menu;
	    }
        
    }
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
    fp = fopen("teacher.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n\n");
    } else {
        int login = 0; // Initialize login flag
        while (fread(&f, sizeof(f), 1, fp)) {
            if (strcmp(password, f.password) == 0 && strcmp(id, f.id) == 0) {
                printf("\n\n\n**LOGGED IN**\n\n");
                login = 1;
                break;
            }
        }
        fclose(fp);

        if (login != 1) {
            printf("\nWRONG USERNAME/PASSWORD\n\n");
        } else {
            system("cls");
            teacher();
            int a;
            teacher_menu:
            printf("\n1. SHOW STUDENTS DETAILS");
            printf("\n2. GIVE ASSIGNMENTS");
            printf("\n3. SEARCH WITH STUDENT ID");
            printf("\n4. CHANGE YOUR STUDENT PASSWORD");
            printf("\n5. EXIT");
            printf("\nChoose: ");
            scanf("%d", &a);
            if (a == 1) {
                show();
            } else if (a == 2) {
                giveassign();
            } else if (a == 3) {
                studentsearch();
            } else if (a == 4) {
                change_student_password();
            } else if (a == 5) {
                main();
            } else {
                printf("\n-----Wrong Choice-------\n\n");
                goto teacher_menu;
            }
            goto teacher_menu;
        }
    }
} else {
    printf("\n***WRONG INPUT***");
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
    		printf("-------------------------------------------------------------------------------------------\n");
    	printf("S.N \t ID \t \t NAME \t \t NUMBER \t  FACULTY \tPASSWORD \n ");
    	printf("-----------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t+977%s \t    %s\t  %s\n",i,s.id,s.name,s.num,s.faculty,s.password);
        printf("------------------------------------------------------------------------------------------------\n");
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
    	printf("--------------------------------------------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \t\t NUMBER \t SUBJECT \t PASSWORD \n  ");
    	printf("--------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t\t+977%s \t %s \t  %s\n",i,f.id,f.name,f.num,f.sub,f.password);
        printf("--------------------------------------------------------------------------------------------------\n");
        i++;
    }
    fclose(fp);
}
void tstudentshow(){

    int  i=1;
    FILE *fp;
    struct teach f;
    fp=fopen("teacher.txt","r");
    if(fp==NULL){
        printf("\n**ERROR IN READING DATA**");
    }

    printf("\nTeachers data :- \n");
    while(fread(&f,sizeof(f),1,fp)){
    	printf("--------------------------------------------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \t\t NUMBER \t SUBJECT \t  \n  ");
    	printf("--------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t\t+977%s \t %s \n",i,f.id,f.name,f.num,f.sub);
        printf("--------------------------------------------------------------------------------------------------\n");
        i++;
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
    	printf("S.N\t ID\t NAME \n  ");
    	printf("-------------------------------------------------------------\n");
        printf("%d\t%s\t %s\n",i,f.id,f.name);
       	printf("-------------------------------------------------------------\n");
        i++;
    }
    fclose(fp);
}
void giveassign() {
    struct assign n;
    FILE *fp;
    fp = fopen("assign.txt", "a");

    if (fp == NULL) {
        printf("\n**ERROR IN OPENING FILE**\n\n");
        return;
    }

    int s;
    printf("\nSubjects: \n  Physics -1 \n Workshop -2 \n Chemistry -3 \n C-Programming  -4 \n Fundamentals of Electrical and Electronics -5 \n  Maths -6  \n Choose: ");
    scanf("%d", &s);

    if (s < 1 || s > 6) {
        printf("\nInvalid Input\n");
        fclose(fp);
        return;
    }

    char subject[200];
    switch (s) {
        case 1:
            strcpy(subject, "Physics");
            break;
        case 2:
            strcpy(subject, "Workshop");
            break;
        case 3:
            strcpy(subject, "Chemistry");
            break;
        case 4:
            strcpy(subject, "C-programming");
            break;
        case 5:
            strcpy(subject, "Fundamentals of Electrical and Electronics");
            break;
        case 6:
            strcpy(subject, "Maths");
            break;
        default:
            printf("\nInvalid Input\n");
            fclose(fp);
            return;
    }

    printf("\nEnter Assignments for %s: ", subject);
    fflush(stdin);
    fgets(n.sub1, sizeof(n.sub1), stdin);
    fprintf(fp, "%s: %s\n", subject, n.sub1);

    printf("\n!!!DATA HAS BEEN SHARED!!!\n");
    fclose(fp);
}

void seeassign() {
    FILE *fp;
    fp = fopen("assign.txt", "r");

    if (fp == NULL) {
        printf("\n**ERROR IN OPENING FILE**\n\n");
        return;
    }

    struct assign n;
    int s;
    printf("\nSubjects: \n  Physics -1 \n Workshop -2 \n Chemistry -3 \n C-Programming  -4 \n Fundamentals of Electrical and Electronics -5 \n  Maths -6  \n Choose: ");
    scanf("%d", &s);

    if (s < 1 || s > 6) {
        printf("\nError Input\n");
        fclose(fp);
        return;
    }

    char subject[200];
    switch (s) {
        case 1:
            strcpy(subject, "Physics");
            break;
        case 2:
            strcpy(subject, "Workshop");
            break;
        case 3:
            strcpy(subject, "Chemistry");
            break;
        case 4:
            strcpy(subject, "C-programming");
            break;
        case 5:
            strcpy(subject, "Fundamentals of Electrical and Electronics");
            break;
        case 6:
            strcpy(subject, "Maths");
            break;
        default:
            printf("\nError Input\n");
            fclose(fp);
            return;
    }

    printf("\nAssignments for %s:\n", subject);

    int found = 0;
    char line[200];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *assignment = strstr(line, ":");
        if (assignment != NULL) {
            *assignment = '\0'; 
            if (strcmp(line, subject) == 0) {
                printf("%s", assignment + 1); 
                found = 1;
            }
        }
    }

    if (!found) {
        printf("\nNo assignments found for the selected subject.\n");
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
       	printf("-----------------------------------------------------------------------------------------\n");
    	printf("S.N \t ID \t \t NAME \t \t NUMBER \t  FACULTY \tPASSWORD \n  ");
    	printf("-----------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t+977%s \t    %s\t  %s\n",i,s.id,s.name,s.num,s.faculty,s.password);
        printf("-----------------------------------------------------------------------------------------\n");
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
           	printf("------------------------------------------------------------------------------------------------\n");
    	printf("S.N \t ID\t\t NAME \t\t NUMBER \t SUBJECT \t PASSWORD \n   ");
    	printf("-----------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t\t%s\t\t+977%s \t %s \t  %s\n",i,s.id,s.name,s.num,s.sub,s.password);
        printf("-----------------------------------------------------------------------------------------------------\n");
        i++;
        }
    }
    if(found==0){
        printf("\n*Data_Not_Found\n \n ");
    }
}

 
void change_student_password() {
    char id[10];
    char new_password[10];

    printf("\nEnter the ID of the student whose password you want to change: ");
    scanf("%s", id);

    struct student s;
    FILE *fp, *temp_fp;
    fp = fopen("stu.txt", "r");
    temp_fp = fopen("temp.txt", "w");
    if (fp == NULL || temp_fp == NULL) {
        printf("\n**ERROR IN READING/WRITING DATA**");
        return;
    }

    int found = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (strcmp(id, s.id) == 0) {
            found = 1;
            printf("\nEnter the new password for student %s: ", s.name);
            scanf("%s", new_password);
            strcpy(s.password, new_password);
        }
        fwrite(&s, sizeof(s), 1, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    if (!found) {
        printf("\nStudent with ID %s not found.\n", id);
        remove("temp.txt"); // Delete temporary file
    } else {
        if (remove("stu.txt") == 0 && rename("temp.txt", "stu.txt") == 0) {
            printf("\nPassword changed successfully for student %s.\n", s.name);
        } else {
            printf("\n**ERROR IN CHANGING PASSWORD**");
        }
    }
}
void change_teacher_password() {
    char id[10];
    char new_password[10];

    printf("\nEnter the ID of the teacher whose password you want to change: ");
    scanf("%s", id);

    struct teach f;
    FILE *fp, *temp_fp;
    fp = fopen("teacher.txt", "r");
    temp_fp = fopen("temp.txt", "w");
    if (fp == NULL || temp_fp == NULL) {
        printf("\n**ERROR IN READING/WRITING DATA**");
        return;
    }

    int found = 0;
    while (fread(&f, sizeof(f), 1, fp)) {
        if (strcmp(id, f.id) == 0) {
            found = 1;
            printf("\nEnter the new password for teacher %s: ", f.name);
            scanf("%s", new_password);
            strcpy(f.password, new_password);
        }
        fwrite(&f, sizeof(f), 1, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    if (!found) {
        printf("\nTeacher with ID %s not found.\n", id);
        remove("temp.txt"); // Delete temporary file
    } else {
        if (remove("teacher.txt") == 0 && rename("temp.txt", "teacher.txt") == 0) {
            printf("\nPassword changed successfully for teacher %s.\n", f.name);
        } else {
            printf("\n**ERROR IN CHANGING PASSWORD**");
        }
    }
}

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


void exit_program(){
    system("cls");
    printf("\n\n\t-------------LEAVING ALREADY------------\n");
    printf("\tCreated  by:\n");
    printf("\tABHISHEK PANTHEE\t(080BCT002)\n");
    printf("\tSULAV PAUDEL\t(080BCT046)\n");
    printf("\tRakesh Kumar Yadav\t(080BCT030)\n");
    printf("\tPRASIDDHA RAJ PAUDEL\t(080BCT027)\n");
    exitsed();
    exit(0);
}
