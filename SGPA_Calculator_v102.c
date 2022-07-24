#include <stdio.h> 
#include <stdlib.h>

int menu();
int numchk();
int semcred(int i);
float sgpaf(int i);
int crschk();
int s_cred_course(int j);
int s_mcourse(int j);
int csgpa();
float pcgpaf();
int pcredf();

int main()
{   int menuin, sems, courses, j = 0, k = 0, credit_total = 0, cred_grade = 0;
    printf("\n**********************************************\n             SGPA / CGPA Calculator      \n**********************************************\n\n");

    printf("      Modes: \n\n  [1] SGPA Mode\n  [2] CGPA Mode\n______________________________________________\n");
    menuin = menu();
    if (menuin == 1){
        system("cls"); 
        printf("\n*************************************************\n                  SGPA Calculator\n*************************************************\n\n");
            courses = crschk();
            int credits[courses], marks[courses], grade[courses], credgrade[courses];
            for (j = 0; j < courses; j++){
                credits[j] = s_cred_course(j);
                marks[j] = s_mcourse(j);
                if (marks[j] >= 90) {
                    grade[j] = 10;
                }
                else if (marks[j] > 80) {
                    grade[j] = 9;
                }
                else if (marks[j] > 75) {
                    grade[j] = 8;
                }
                else if (marks[j] > 70) {
                    grade[j] = 7;
                }
                else if (marks[j] > 65) {
                    grade[j] = 6;
                }
                else if (marks[j] > 60) {
                    grade[j] = 5;
                }
                else if (marks[j] > 50) {
                    grade[j] = 4;
                }
                else {
                    grade[j] = 0;
                }
            }
            for (j = 0; j < courses; j++){
                    credit_total += credits[j];
                    credgrade[j] = credits[j] * grade[j];
                    cred_grade += credgrade[j];
            }
            float SGPA = (float)cred_grade / (float)credit_total;
            printf("\n  Your SGPA is %.2f\n", SGPA);
            int c_sgpa = csgpa();
            if (c_sgpa == 1){
                printf("\n**********************************************\n            SGPA to CGPA Calculator\n**********************************************\n\n");
                float pcgpa = pcgpaf();
                int pcred = pcredf();
                float n_cgpa = (pcgpa * (float)pcred + SGPA * (float)credit_total) / ((float)pcred + (float)credit_total);
                printf("\n\n  New CGPA is : %.2f", n_cgpa);
            }
            printf("\n\n  Press any key to exit...");
            getch();
        }
    else {
        system("cls"); 
        printf("\n**********************************************\n               CGPA Calculator\n**********************************************\n\n");
        sems = numchk();
        int scred[sems]; 
        float sgpa[sems], credgpa[sems], crgpa = 0, cgpa;
        credit_total = 0;
        for (int i = 0; i < sems; i++){
            scred[i] = semcred(i);
            sgpa[i] = sgpaf(i);
            credit_total += scred[i];
            credgpa[i] = (float)scred[i] * sgpa[i];
            crgpa += credgpa[i];
        }
        cgpa = crgpa / (float)credit_total;

        printf("\n\nYour CGPA is %.2f", cgpa);
        printf("\n\n\nPress any key to exit...");
        getch();
    }
    return 0;
    }

int menu() {
    printf("\nEnter a menu option in the Keyboard [1,2] : ");
    int input;
    scanf("%d", &input);
    if(input > 0 && input < 3){
        return input;
    }
    else {
        printf("Invalid Option Entered, try again\n\n");
        menu();
    }
}

int numchk(){
    printf("Enter the Number of Semesters: ");
    int input;
    scanf("%d", &input);
    if(input > 0 && input < 12){
        return input;
    }
    else {
        printf("Invalid Semesters Entered, try again\n\n");
        numchk();
    }
}

int semcred(int i){
    int cred;
    printf("\nEnter Credits for Semester %d: ", i+1);
    scanf("%d", &cred);
    if (cred >= 0 && cred <= 200){
        return cred;
    }
    else {
        printf("Invalid Credits Entered, try again\n\n");
        semcred(i);
    }
}

float sgpaf(int i){
    float nsgpa;
    printf("Enter SGPA for Semester %d: ", i+1);
    scanf("%f", &nsgpa);
    if (nsgpa >= 0 && nsgpa <= 10){
        return nsgpa;
    }
    else {
        printf("Invalid SGPA Entered, try again\n\n");
        sgpaf(i);
    }
}

int crschk(){
    int n;
    printf("\n  Enter the Number of Credit Courses: ");
    scanf("%d", &n);
    if(n > 0 && n < 10){
        return n;
    }
    else {
        printf("\n  Invalid Courses Entered, try again\n\n");
        crschk();
    }
}

int s_cred_course(int j){
    int credits;
    printf("\n  Enter the number of credits for course %d: ", j+1);
    scanf("%d", &credits);
    if (credits <= 15 && credits >= 0){
        return credits;
    }
    else{
        printf("  Invalid Credits Entered, try again\n");
        s_cred_course(j);
    }
}

int s_mcourse(int j){
    int mark;
    printf("  Enter the marks (out of 100) for course %d: ", j+1);
    scanf("%d", &mark);
    if (mark >= 0 && mark <= 100){
        return mark;
    }
    else{
        printf("  Invalid Marks Entered, try again\n\n");
        s_mcourse(j);
    }
}

int csgpa(){
    int c;
    printf("\n  Would you like to calculate the CGPA after this SGPA? ['1' for 'Yes' / '0' for 'No']: ");
    scanf("%d", &c);
    if (c == 1){
        return 1;
    }
    else if(c == 0){
        return 0;
    }
    else {
        printf("\n  Invalid Option Entered, try again");
        csgpa();
    }
}

float pcgpaf(){
    float pcgpa;
    printf("\n  Enter previous CGPA: ");
    scanf("%f", &pcgpa);
    if (pcgpa >= 0 && pcgpa <= 10){
        return pcgpa;
    }
    else{
        printf("  Invalid Previous CGPA Entered, try again\n\n");
        pcgpaf();
    }
}

int pcredf(){
    int pcred;
    printf("  Enter previous Credits: ");
    scanf("%d", &pcred);
    if (pcred >= 0 && pcred <= 400){
        return pcred;
    }
    else{
        printf("  Invalid Previous Credits Entered, try again\n\n");
        pcredf();
    }
}