
/*

                                                                                                Team : Icon Squad
                                                                                        -----------------------------------
                                                                                        ***********************************
                                                                                        1.Abu Bakar Siddique	191-15-12560
                                                                                        2.Muhaiminul Sarkar	191-15-12425
                                                                                        3.Ashrif Bin Ahmed		191-15-12439



*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
{
    int id,phone;
    char reg_status[50],dept[200],Stu_Name[50],course[50];
    struct node *next;
    struct node *previous;
}*start = NULL, *end = NULL;
    FILE *file;
                                                                                                                /*Insert function*/
void Add_students_Details()
{

    struct node *new_node, *current;
    int i, number_of_node;

    printf("\n\n\n\n\n\n\n\t\t\tHow Many Student's Details You want to add: ");
    scanf("%d", &number_of_node);
    cls();

    for(i = 1; i <= number_of_node; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));

        if(new_node == NULL)
        {
            printf("\nMemory Does Not Created.\n");
            exit(0);
        }
        else
        {   file = fopen("Student's Management.txt","a+");
            if(file == NULL)
            {
                printf("File does not create.\n");
            }
            else
            {

            printf("\n\t\t\t\tENTER STUDENTS DEATAILS BELOW:\n");
            fprintf(file,"\n\n\t\t\t STUDENTS DEATAILS BELOW:\n");
            printf("\t\t\t--------------------------------------------\n");
            fprintf(file,"\t\t\t--------------------------------------------\n");


            printf("\n\tStudent's Id No: ");
            scanf("%d", &new_node->id);
            fprintf(file,"\n\tID: %d",new_node->id);


            printf("\n\tStudent's Name: ");
            fflush(stdin);
            gets(new_node->Stu_Name);
            fprintf(file,"\n\tStudent's Name : %s",new_node->Stu_Name);

            printf("\n\tList of course : ");
            fflush(stdin);
            gets(new_node->course);
            fprintf(file,"\n\tList of course: %s",new_node->course);


            printf("\n\tRegistration Status : ");
            fflush(stdin);
            gets(new_node->reg_status);
            fprintf(file,"\n\tRegistration Status : %s",new_node->reg_status);

            printf("\n\tDepartment : ");
            fflush(stdin);
            gets(new_node->dept);
            fprintf(file,"\n\tDepartment : %s",new_node->dept);

            printf("\n\tPhone No: ");
             scanf("%d", &new_node->phone);
            fprintf(file,"\n\tEnter Phone No : %d",new_node->phone);


                fclose(file);
                fopen("Student's Management.txt","a+");
            }

            new_node->next = NULL;
            new_node->previous = NULL;

            if(start == NULL && end == NULL)
            {
                start = new_node;
                end = new_node;
                current = new_node;
            }
            else
            {
                current->next = new_node;
                new_node->previous = current;
                current = new_node;
                end = new_node;
            }
        }
    }

}



                                                                                                        /*View function*/
void View_Students_Details()
{
     struct node *current;

    current = start;

    if(current == NULL)
    {
        printf("\n\n\n\n\n\n\n\t\t\tSORRY!!There Are No Information..\n");
    }
    else
    {
         while(current != NULL)
         {
            printf("\n\t\t\tSTUDENTS DEATAILS BELOW:\n");
            printf("\t\t\t-------------------------------\n");

            printf("\n\tEnter Student ID :%d",current->id);


            printf("\n\tEnter Student Name: %s",current->Stu_Name);


            printf("\n\tEnter List of course: %s",current->course);


            printf("\n\tEnter Registration Status:%s",current->reg_status);

            printf("\n\tEnter Department : %s",current->dept);


            printf("\n\tEnter Phone No : %d",current->phone);
            current = current->next;
            printf("\n");
         }
    }
    printf("\n\n\tPress Enter....");

}

int pos(student_id)
{
    int position = 0;
    struct node *current;

    current = start;

    while(current != NULL)
    {
        position++;
        if(student_id == current->id)
        {
            return position;
        }
        current = current->next;
    }
    return -1;
}



                                                                                                                 /*Search function*/
int Search_Students_Details(student_id)
{
    int position = 0;
    struct node *current;

    current = start;

    while(current != NULL)
    {
        position++;
        if(student_id == current->id)
        {
           printf("\n\t\t\tSTUDENTS DEATAILS BELOW:\n");
            printf("\t\t\t-------------------------------\n");

            printf("\n\tEnter Student ID :%d",current->id);


            printf("\n\tEnter Student Name: %s",current->Stu_Name);


            printf("\n\tEnter List of course: %s",current->course);


            printf("\n\tEnter Registration Status:%s",current->reg_status);

            printf("\n\tEnter Department : %s",current->dept);


            printf("\n\tEnter Phone No : %d",current->phone);

            printf("\n\n");
            getch();
            cls();

            return position;
        }
        current = current->next;
    }
    return -1;
}

                                                                                                        /*Update function*/
void update(int student_id)
{

    struct node *current;

    current = start;

    while(current != NULL)
        {
		if(student_id == current->id)
            {
            printf("\n\n\n");

			printf("\tStudent ID number %d is found !!!\n",student_id);

			printf("\n");
			printf("\tEnter Registration Status: ");
			scanf("%s",current->reg_status);
			printf("\n");
			printf("\n\t\t***** Update Successful!!! *****\n");

            }
        else
            {
             printf("\n");
             //printf("\t\tStudent ID number %d is not found !!!\n",student_id);

            }
            current = current->next;

	   }


	int b;

	printf("\n\n");
	printf("\tPress '1'  Back To Main Menu:");
	scanf("%d",&b);
	if (b==1)
    {
      main();
    }
    else
    {

        printf("\tYour input is wrong!!!");

       main();

    }


}

                                                                                                                        /*Delete function*/

void Remove_Students_Details()
{
    struct node *current, *temp1, *temp2;
    int i, delet_id, position;

    printf("\n\n\t-->Enter ID for Remove: ");
    scanf("%d", &delet_id);
    position = Search_Students_Details(delet_id);

    current = start;
    for(i = 1; i <= (position - 1); i++)
    {
        current = current->next;
    }
    if(current == start && current->previous == NULL)
    {
        current = current->next;
        start = current;
        current->previous = NULL;
        printf("\n\t Information Delete Successfully.\n");
        printf("\n\n\n\tPress Enter....");
    }
    else if(current->next == NULL && current == end)
    {
        current = current->previous;
        end = current;
        current->next = NULL;
        printf("\n\t Information Delete Successfully.\n");
        printf("\n\n\n\tPress Enter....");
    }
    else
    {
        temp2 = current->next;
        temp1 = current->previous;
        temp1->next = temp2;
        temp2->previous = temp1;
        printf("\n\tDelete Successfully.\n");
        printf("\n\n\n\tPress Enter....");
    }


}

void cls()
{
    system("cls");
}

int main()
{
    system("color f0");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t--------------------------------------------------------------------------------------------\n");
    printf("\t\t\t--------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t*****WELCOME TO  STUDENT MANAGEMENT SYSTEM*****\n");
    printf("\n\t\t\t--------------------------------------------------------------------------------------------\n");
    printf("\t\t\t--------------------------------------------------------------------------------------------\n");
    printf("\n\n\n\n\t\t\t Press Enter to continue .......");
    getch();
    cls();

     int  choice, position, student_id, insert_choice, display_choice;


     while(1)
     {
         printf("--------------------------------------------------------------------------------------------\n");
         printf("\t\t\t\t\tMAIN MENU\n");
         printf("--------------------------------------------------------------------------------------------\n");
         printf("\n\n");
         printf("\t\t\t\t1.Add Student's Details.\n\n");
         printf("\t\t\t\t2.View Student's Details.\n\n");
         printf("\t\t\t\t3.Search Student's Details.\n\n");
         printf("\t\t\t\t4.Remove Student's Details.\n\n");
         printf("\t\t\t\t5.Update Student's Details.\n\n");
         printf("\t\t\t\t6.Exit.\n\n");
         printf("_____________________________________________________________________________________________\n");
         printf("\n\t\t\tPlease Enter your choice(1-6): ");
         scanf("%d", &choice);
         printf("\n");

          cls();

         switch(choice)
         {
              case 1: Add_students_Details();
                    cls();
                    printf("\n\n\n\n\n\n\n\t\t\t****Student's Information Saved Successfully****");
                    printf("\n\n\n\n\n\t\t\tPress Enter...");
                    getch();
                    cls();
                    break;

              case 2: while (1)
                      {
                        printf("\n\n\n\n\n");
                        printf("------------------------------------------------------------------------------------------");
                        printf("\n\n");
                        printf("\t\t\t\t1. View Student's Information.\n");
                        printf("\t\t\t\t2. Back To Main Menu.\n\n");
                        printf("------------------------------------------------------------------------------------------");

                        printf("\n\n\n\t\t\tPlease Enter your choice: ");
                        scanf("%d", &display_choice);
                        printf("\n\n");

                        cls();

                        switch(display_choice)
                            {
                            case 1: View_Students_Details();
                                    getch();
                                    cls();
                                    break;

                            case 2: main();
                                    break;

                            default:printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                                    printf("\n\t\t\tPlease Enter Correct Key to Access.");
                                    printf("\n\t\t\t\tOr Enter 2 to Main menu.\n");
                                    getch();
                                    cls();
                            }
                      }
                            getch();
                            cls();
                            break;


              case 3: printf("\n\n\n\n\n\n\t\t\tEnter ID: ");
                    scanf("%d",& student_id);
                    cls();

                    position = Search_Students_Details(student_id);
                    if(position == -1)
                    {
                        printf("\n\n\n\n\n\n\t\t\tThis ID is not in the List.\n");
                        getch();
                        cls();
                    }
                    else
                    {
                        printf("\n\n\n\n\n\n\t\t\tThe Position of this list is at Number %d.\n", position);
                        printf("\n\n\n\tPress Enter....");

                        getch();
                        cls();
                    }
                    break;

              case 4: Remove_Students_Details();
                    getch();
                    cls();
                    break;

              case 5:
                    printf("\n\n-->Enter Student's Id for update: ");
                    scanf("%d", &student_id);

                    update(student_id);

                    printf("\n\n\n\n\n\n\n\t\t\t****Student's Information update Successfully****");
                    getch();
                    cls();
                    break;

              case 6: exit(1);
                    break;

            default:printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                    printf("\n\t\t\tPlease Enter Correct Key to Access.");
                    printf("\n\t\t\t\tOr Enter 6 to Exit.\n");
                    getch();
                    cls();

         }

     }

}
