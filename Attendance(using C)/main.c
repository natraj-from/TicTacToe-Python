#include <stdio.h>
#include <string.h>

#define max_student 50
#define max_days 31
#define namelen 50

void input_student(char name[][namelen],int n);
void mark_attendance (char name[][namelen],int attendance[][max_days],int n ,int days);
void report (char name[][namelen],int atteandance[][max_days],int n ,int days);

int main(){
    
    char name[max_student][namelen];
    int attendance[max_student][max_days]={0};
    int n,days,choice;
    int attendance_marked=0;

    printf("----------------------------ATTENDANCE----------------------------\n\n");
    
    printf("Number of students: ");
    scanf("%d",&n);
    
    if (n<1 || n>max_student){
        printf("Invalid number of student\n");
        return 1;
    }
    
    printf("Number of Attendance days: ");
    scanf("%d",&days);

    if (days<1 || days > max_days){
        printf("Invalid number of days\n");
        return 1;
    }

    input_student(name,n);

    do{
        printf("\n-------------------------------Menu-------------------------------\n");
        printf("Press 1: Mark Attendance\nPress 2: Display Attendance Report\nPress 3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        

        switch (choice){
           
            case 1:
                mark_attendance(name,attendance,n,days);
                attendance_marked=1;
                break;

            case 2:
                if (attendance_marked==0){
                    printf("\nAttendance has not been marked yet.\nPlease mark the attendance before proceeding.\n");
                }
                else{
                    report(name,attendance,n,days);
                }
                break;
                
            case 3:
                printf("Exiting\n");
                break;

            default:
                printf("Invaild choice!\nTry again.\n");
                break;
        }

    }while (choice != 3);

    return 0;
}

void input_student(char name[][namelen],int n){
    int i;
        
    for (i=0;i<n;i++){
            
        printf("Enter name of student %d: ",i+1);
        scanf(" %49[^\n]",name[i]);
    }
}

void mark_attendance(char name[][namelen],int attendance[][max_days],int n, int days){
    int i=0, j=0, check;
    printf("\nEnter 1 for present 0 for absent\n\n");
    for (i=0;i<n;i++){
        printf("Attandance for %s\n",name[i]);

        for (j=0;j<days;j++){
            do{
                printf("Day %d: ",j+1);

                if (scanf("%d",&check)!=1){
                    printf("Please enter 1 or 0.\n");
                    while (getchar()!='\n');
                    check=-1;
                }
                else if(check!=0 && check!=1){
                    printf("Invaild input enter 1 or 0.\n");
                }

            } while(check!=0 && check!=1);
                
            attendance[i][j] = check;
        }

    }

    printf("\nAttendance Successfully recorded.\n");
}

void report(char name[][namelen],int attendance[][max_days],int n,int days){

    int i,j;
    int present, absent;
    
    float percentage ;
    printf("\n------------------------------Report------------------------------\n\n");

    printf("%-20s %-8s %-8s %-12s\n","Student Name","Present","Absent","Percentage");

    for (i=0;i<n;i++){
        present=0;
        absent=0;
        
        for (j=0;j<days;j++){
            
            if (attendance[i][j]==1)
                present++;
            else
                absent++;
        }
    
        percentage=(present*100.00)/days;

        printf("%-20s %-8d %-8d %-8.2f%% ",name[i],present,absent,percentage);

        if (percentage>=75.0f)
            printf("    Eligible\n");
        else
            printf("    Not Eligible\n");

        //printf("----------------------------------------------------------------\n");
        printf("==================================================================\n");
    }   

}

    