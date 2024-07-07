#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // for getpass()

// Define structure for student, admin, teacher, and assignments
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

// Function prototypes
void password_taker(char []);
void exit_program();
void change_student_password();
void change_teacher_password();
void reg();
void show_students();
void show_teachers();
void give_assignment();
void see_assignment();
void admin_data_show();
void search_student();
void search_teacher();
void login();

// Main function
int main() {
    int choice;
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    login();

    while (true) {
        printf("\n\n***WELCOME TO LMS***");
        printf("\n1. SIGN IN\n2. SIGN UP\n\n0. Exit\n");
        printf("\nChoose : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                reg();
                break;
            case 0:
                exit_program();
                break;
            default:
                printf("\n*****_WRONG_INPUT_*****\n");
                break;
        }
    }

    return 0;
}

// Function definitions

// Function to handle user login
void login() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    printf("\n**1. Administration**");
    printf("\n**2. Teacher**");
    printf("\n**3. Student**");
    printf("\nChoose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            admin();
            break;
        case 2:
            teacher();
            break;
        case 3:
            student();
            break;
        default:
            printf("\n***WRONG INPUT***\n");
            break;
    }
}

// Function to handle user registration
void reg() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signup();

    int choice;
    printf("\n**1. Administration**");
    printf("\n**2. Teacher**");
    printf("\n**3. Student**");
    printf("\nChoose: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            register_admin();
            break;
        case 2:
            register_teacher();
            break;
        case 3:
            register_student();
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }
}

// Function to register an administrator
void register_admin() {
    struct admin f;
    FILE *fp;
    admin();

    fp = fopen("adm.txt", "a");
    if (fp == NULL) {
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

// Function to register a teacher
void register_teacher() {
    struct teach f;
    FILE *fp;
    teacher();

    fp = fopen("teacher.txt", "a");
    if (fp == NULL) {
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

// Function to register a student
void register_student() {
    struct student f;
    FILE *fp;
    student();

    fp = fopen("stu.txt", "a");
    if (fp == NULL) {
        printf("\nError opening file.");
        return;
    }

    printf("\nEnter ID: ");
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

// Function to handle admin operations after login
void admin() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

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
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    int login = 0;
    while (fread(&f, sizeof(f), 1, fp)) {
        if (strcmp(password, f.password) == 0 && strcmp(id, f.id) == 0) {
            printf("\n**LOGGED IN**\n\n");
            login = 1;
            break;
        }
    }
    fclose(fp);

    if (login == 1) {
        admin_menu();
    } else {
        printf("\nWRONG USERNAME/PASSWORD\n\n");
    }
}

// Function to handle teacher operations after login
void teacher() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct teach f;
    char id[10];
    char password[10];

    printf("\nEnter ID: ");
    scanf("%s", id);
    printf("\nEnter Password: ");
    password_taker(password);

    FILE *fp;
    fp = fopen("teacher.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    int login = 0;
    while (fread(&f, sizeof(f), 1, fp)) {
        if (strcmp(password, f.password) == 0 && strcmp(id, f.id) == 0) {
            printf("\n**LOGGED IN**\n\n");
            login = 1;
            break;
        }
    }
    fclose(fp);

    if (login == 1) {
        teacher_menu();
    } else {
        printf("\nWRONG USERNAME/PASSWORD\n\n");
    }
}

// Function to handle student operations after login
void student() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

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
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    int login = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (strcmp(password, s.password) == 0 && strcmp(id, s.id) == 0) {
            printf("\n**LOGGED IN**\n\n");
            login = 1;
            break;
        }
    }
    fclose(fp);

    if (login == 1) {
        student_menu();
    } else {
        printf("\nWRONG USERNAME/PASSWORD\n\n");
    }
}

// Admin menu function
void admin_menu() {
    int choice;
    admin:

    printf("\n1. SHOW STUDENT DATA");
    printf("\n2. SHOW TEACHER DATA");
    printf("\n3. CHANGE STUDENT PASSWORD");
    printf("\n4. CHANGE TEACHER PASSWORD");
    printf("\n5. GIVE ASSIGNMENT");
    printf("\n6. SHOW ASSIGNMENT");
    printf("\n7. SHOW ADMIN DATA");
    printf("\n8. SEARCH STUDENT");
    printf("\n9. SEARCH TEACHER");
    printf("\n\n0. Exit\n");

    printf("\nChoose: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            show_students();
            break;
        case 2:
            show_teachers();
            break;
        case 3:
            change_student_password();
            break;
        case 4:
            change_teacher_password();
            break;
        case 5:
            give_assignment();
            break;
        case 6:
            see_assignment();
            break;
        case 7:
            admin_data_show();
            break;
        case 8:
            search_student();
            break;
        case 9:
            search_teacher();
            break;
        case 0:
            exit_program();
            break;
        default:
            printf("\n**WRONG_INPUT**\n");
            goto admin;
            break;
    }
}

// Function to change student password
void change_student_password() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    char id[10];
    char password[10];
    struct student s;
    FILE *fp, *ft;

    printf("\nEnter ID: ");
    scanf("%s", id);
    printf("\nEnter Old Password: ");
    password_taker(password);

    fp = fopen("stu.txt", "r+");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    int found = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (strcmp(id, s.id) == 0 && strcmp(password, s.password) == 0) {
            found = 1;
            printf("\n**FOUND**\n");

            printf("\nEnter New Password: ");
            password_taker(s.password);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            fclose(fp);
            break;
        }
    }

    if (found == 0) {
        printf("\n**NO SUCH USER FOUND**\n\n");
    } else {
        printf("\n***PASSWORD CHANGED SUCCESSFULLY***\n\n");
    }
}

// Function to change teacher password
void change_teacher_password() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    char id[10];
    char password[10];
    struct teach f;
    FILE *fp, *ft;

    printf("\nEnter ID: ");
    scanf("%s", id);
    printf("\nEnter Old Password: ");
    password_taker(password);

    fp = fopen("teacher.txt", "r+");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    int found = 0;
    while (fread(&f, sizeof(f), 1, fp)) {
        if (strcmp(id, f.id) == 0 && strcmp(password, f.password) == 0) {
            found = 1;
            printf("\n**FOUND**\n");

            printf("\nEnter New Password: ");
            password_taker(f.password);

            fseek(fp, -sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            fclose(fp);
            break;
        }
    }

    if (found == 0) {
        printf("\n**NO SUCH USER FOUND**\n\n");
    } else {
        printf("\n***PASSWORD CHANGED SUCCESSFULLY***\n\n");
    }
}

// Function to show student data
void show_students() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct student f;
    FILE *fp;

    fp = fopen("stu.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    while (fread(&f, sizeof(f), 1, fp)) {
        printf("\nID: %s\nPassword: %s\nName: %s\nPhone Number: %s\nFaculty: %s\n", f.id, f.password, f.name, f.num, f.faculty);
    }
    fclose(fp);
}

// Function to show teacher data
void show_teachers() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct teach f;
    FILE *fp;

    fp = fopen("teacher.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    while (fread(&f, sizeof(f), 1, fp)) {
        printf("\nID: %s\nPassword: %s\nName: %s\nPhone Number: %s\nSubject: %s\n", f.id, f.password, f.name, f.num, f.sub);
    }
    fclose(fp);
}

// Function to give assignment
void give_assignment() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct assign f;
    FILE *fp;

    fp = fopen("assign.txt", "a");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    printf("\nEnter Assignment for subject1: ");
    scanf("%s", f.sub1);

    printf("\nEnter Assignment for subject2: ");
    scanf("%s", f.sub2);

    printf("\nEnter Assignment for subject3: ");
    scanf("%s", f.sub3);

    printf("\nEnter Assignment for subject4: ");
    scanf("%s", f.sub4);

    printf("\nEnter Assignment for subject5: ");
    scanf("%s", f.sub5);

    printf("\nEnter Assignment for subject6: ");
    scanf("%s", f.sub6);

    fwrite(&f, sizeof(f), 1, fp);
    fclose(fp);
}

// Function to see assignment
void see_assignment() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct assign f;
    FILE *fp;

    fp = fopen("assign.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    printf("\nAssignment for subject1: %s\n", f.sub1);
    printf("Assignment for subject2: %s\n", f.sub2);
    printf("Assignment for subject3: %s\n", f.sub3);
    printf("Assignment for subject4: %s\n", f.sub4);
    printf("Assignment for subject5: %s\n", f.sub5);
    printf("Assignment for subject6: %s\n", f.sub6);

    fclose(fp);
}

// Function to show admin data
void admin_data_show() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct admin f;
    FILE *fp;

    fp = fopen("adm.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    while (fread(&f, sizeof(f), 1, fp)) {
        printf("\nID: %s\nPassword: %s\nName: %s\n", f.id, f.password, f.name);
    }
    fclose(fp);
}

// Function to search for a student
void search_student() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct student f;
    FILE *fp;
    char id[10];

    printf("\nEnter ID: ");
    scanf("%s", id);

    fp = fopen("stu.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    int found = 0;
    while (fread(&f, sizeof(f), 1, fp)) {
        if (strcmp(id, f.id) == 0) {
            found = 1;
            printf("\nID: %s\nPassword: %s\nName: %s\nPhone Number: %s\nFaculty: %s\n", f.id, f.password, f.name, f.num, f.faculty);
            break;
        }
    }

    if (found == 0) {
        printf("\n**NO SUCH USER FOUND**\n\n");
    }

    fclose(fp);
}

// Function to search for a teacher
void search_teacher() {
    system("cls"); // Assuming Windows, use "clear" for Unix-like systems
    signin();

    struct teach f;
    FILE *fp;
    char id[10];

    printf("\nEnter ID: ");
    scanf("%s", id);

    fp = fopen("teacher.txt", "r");
    if (fp == NULL) {
        printf("\n**ERROR IN READING DATA**\n");
        return;
    }

    int found = 0;
    while (fread(&f, sizeof(f), 1, fp)) {
        if (strcmp(id, f.id) == 0) {
            found = 1;
            printf("\nID: %s\nPassword: %s\nName: %s\nPhone Number: %s\nSubject: %s\n", f.id, f.password, f.name, f.num, f.sub);
            break;
        }
    }

    if (found == 0) {
        printf("\n**NO SUCH USER FOUND**\n\n");
    }

    fclose(fp);
}

// Function to take password input securely
void password_taker(char password[]) {
    int i = 0;
    char ch;
    while (i < 10) {
        ch = getch();
        if (ch == 13)
            break;
        else if (ch == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
}

// Function to exit the program
void exit_program() {
    printf("\nTHANK YOU FOR USING LMS\n");
    exit(0);
}
