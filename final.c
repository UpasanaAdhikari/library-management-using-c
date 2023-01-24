#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void password_page();
void password();
void MainPage();
void addbook();
void searchbook();
void issuebook();
void editbook();
void deletebook();
void sName();
void sId();
void sAuthor();
void sCategory();
void issue();
void view_issued_book();
void display_issued_book();
void remove_issued_book();
struct book
{
    int book_id;
    char book_name[50];
    char author_name[50];
    char book_category[60];
};
struct student
{
    int student_id;
    char student_name[80];
    char student_sem[80];
    char student_email[80];
};

int j = 0;
int main()
{
    password_page();
    return 0;
}
void password_page()
{
    password();
}
void password()
{
    int n = 0;
    char user_name[50] = {"libarian"};//username 
    char pass_word[50] = {"acme"};//password
    char user[50];
    char pass[50];
    printf("\nEnter your username:");
    scanf("%s", &user);

    printf("\nEnter your password:");
    scanf("%s", &pass);

    if (strcmp(user_name, user) == 0 && strcmp(pass_word, pass) == 0)
    {
        MainPage();
    }

    else
    {
        printf("\nwrong password or username");
        password();
    }
}
void MainPage()
{
    system("cls");
    printf("                              . ,  '    ;                                          \n");
    printf("          __                 ; . ,                                                 \n");
    printf("          ||.--.         '     '     '  '                                          \n");
    printf("          |||  |        .---.  '  ; ; .                                            \n");
    printf("          |||  |        |   | '.  ;                                                \n");
    printf("          |||==|  .-----.===.    |                                                 \n");
    printf("          |||  |  |     |   |   _|__                                               \n");
    printf("          |||  |  |==+==|   |  (    )                                              \n");
    printf("          |||  |--.     |   | ,-'--'----,                                          \n");
    printf("          |||==|~~|==+==|   |( |        |                                          \n");
    printf("          |||  |__|     |   | ,.--------.---,                                      \n");
    printf("          |||  |  |_____|===|( |            |                                      \n");
    printf("          ||'--^--^-----^---'-'-------------'------------,                         \n");
    printf("          ''---------------------------------------------'                         \n");
    int choice;
    do
    {
        printf("\n1>Add Book\t\t\t\t\t2>Search Book\n3>Display Book\t\t\t\t\t4>Issue Book\n5>Edit Book\t\t\t\t\t6>Delete Book\n7>logout\t\t\t\t\t8>Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            addbook();
            break;
        case 2:
            system("cls");
            searchbook();
            break;
        case 3:
            system("cls");
            display();
            break;
        case 4:
            system("cls");
            issue();
            break;
        case 5:
            system("cls");
            editbook();
            break;

        case 6:
            system("cls");
            deletebook();
            break;

        case 7:
            system("cls");
            password_page();
            break;
        case 8:
            system("cls");
            printf("\n================== Thank You =======================\n");
            exit(0);
            break;
        }
        getch();
    } while (choice != 0);
}
void addbook()
{
    struct book b;
    int j = 0;
    char c = 'x';
    FILE *f = fopen("book_record.txt", "a");
    if (f == NULL)
    {
        printf("\nError Creating File\n");
    }
    printf("====================== ADD BOOKS =====================\n\n\n");
    printf("\nEnter Book Name\t> ");
    scanf("%s", b.book_name);
    printf("\nEnter Author Name > ");
    scanf("%s", b.author_name);
    printf("\nEnter Category\t> ");
    scanf("%s", b.book_category);
    printf("\nEnter Book id\t> ");
    scanf("%d", &b.book_id);
    fprintf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, b.book_id); // file ma data write gareko
    fclose(f);
    printf("\nDo you wish to continue\nYes=Y\tNo=n\n");
    scanf("%s", &c);
    j++;

    if (c == 'Y' || c == 'y')
    {
        addbook();
    }
    else
    {
        MainPage();
    }
    getch();
}
void display()
{
    printf("====================== DISPLAYING BOOKS =====================\n\n\n");
    struct book b;
    int j = 0;
    fflush(stdin);

    FILE *f = fopen("book_record.txt", "r");

    printf("------------------------------------------------------\n");
    printf(">>>>>>>>>>>>>>> List of Book Records <<<<<<<<<<<<<<<<\n");
    printf("------------------------------------------------------\n\n");

    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF) // file bata data read gareko to the end of file
    {
        printf("------------------------------------------------------\n");
        printf("> Book Name: %s \n", b.book_name);
        printf("> Author: %s \n", b.author_name);
        printf("> Category: %s\n", b.book_category);
        printf("> Book ID: %d \n", b.book_id);
        printf("-------------------------------------------------------\n\n\n");
        j++;
    }

    if (j == 0)
    {
        printf("-----------------------------------------------------\n");
        printf(">>>>>>>>>>There is no book records added yet<<<<<<<<<<\n");
        printf("------------------------------------------------------\n\n");
    }
    fclose(f);
}
void searchbook()
{

    int n;

    do
    {
        printf("=======================SEARCH BOOKS======================\n\n\n");
        printf("\nPlease choose the search option below");
        printf("\n1>Search by Name\t\t\t\t2>Search by Id\n3>Search by Aurthor Name\t\t\t4>Search by Category\n5>MainPage\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            system("cls");
            sName();
            break;
        case 2:
            system("cls");
            sId();
            break;
        case 3:
            system("cls");
            sAuthor();
            break;
        case 4:
            system("cls");
            sCategory();
            break;
        case 5:
            system("cls");
            MainPage();
            break;
        }
        getch();
    } while (n != 0);
}
void sName()
{

    char name[50];
    struct book b;
    int x = 0;

    printf("\nenter name of book: ");
    scanf("%s", &name);
    FILE *f = fopen("book_record.txt", "r");

    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF)
    {
        if (strcmp(b.book_name, name) == 0)
        {

            printf("-----------------------------------------------------\n");
            printf(">>>>>>>>>>>>>>>>>>>> Record Found <<<<<<<<<<<<<<<<<<<\n");
            printf("------------------------------------------------------\n\n");
            printf("------------------------------------------------------\n\n");
            printf("> Book Name: %s \n", b.book_name);
            printf("> author name: %s \n", b.author_name);
            printf("> book category:%s \n", b.book_category);
            printf("> book id: %d \n", b.book_id);
            printf("------------------------------------------------------\n\n");

            x = 1;
        }
    }
    if (x != 1)
    {
        printf("-----------------------------------------------------\n");
        printf(">>>>>>>>>>There is no book records added yet<<<<<<<<<<\n");
        printf("------------------------------------------------------\n\n");
    }
    fclose(f);
    getch();
}
void sId()
{

    int id, x = 0;
    struct book b;

    printf("\nEnter book id: \n");
    scanf("%d", &id);
    FILE *f = fopen("book_record.txt", "r");
    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF)
    {
        if (b.book_id == id)
        {

            printf("-----------------------------------------------------\n");
            printf(">>>>>>>>>>>>>>>>>>>> Record Found <<<<<<<<<<<<<<<<<<<\n");
            printf("------------------------------------------------------\n\n");
            printf("------------------------------------------------------\n\n");
            printf("> Book Name: %s \n", b.book_name);
            printf("> author name: %s \n", b.author_name);
            printf("> book category:%s \n", b.book_category);
            printf("> book id: %d \n", b.book_id);
            printf("------------------------------------------------------\n\n");

            x = 1;
        }
    }
    if (x != 1)
    {

        printf("-----------------------------------------------------\n");
        printf(">>>>>>>>>>There is no book records added yet<<<<<<<<<<\n");
        printf("------------------------------------------------------\n\n");
    }
    fclose(f);
    getch();
}
void sAuthor()
{

    char author[50];
    struct book b;
    int x = 0;

    printf("\nenter name of author: ");
    scanf("%s", &author);
    FILE *f = fopen("book_record.txt", "r");

    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF)
    {
        if (strcmp(b.author_name, author) == 0)
        {

            printf("-----------------------------------------------------\n");
            printf(">>>>>>>>>>>>>>>>>>>> Record Found <<<<<<<<<<<<<<<<<<<\n");
            printf("------------------------------------------------------\n\n");
            printf("------------------------------------------------------\n\n");
            printf("> Book Name: %s \n", b.book_name);
            printf("> author name: %s \n", b.author_name);
            printf("> book category:%s \n", b.book_category);
            printf("> book id: %d \n", b.book_id);
            printf("------------------------------------------------------\n\n");

            x = 1;
        }
    }
    if (x != 1)
    {
        printf("-----------------------------------------------------\n");
        printf(">>>>>>>>>>There is no book records added yet<<<<<<<<<<\n");
        printf("------------------------------------------------------\n\n");
    }
    fclose(f);
    getch();
}
void sCategory()
{

    char category[50];
    struct book b;
    int x = 0;

    printf("\nenter book category: ");
    scanf("%s", &category);
    FILE *f = fopen("book_record.txt", "r");

    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF)
    {
        if (strcmp(b.book_category, category) == 0)
        {

            printf("-----------------------------------------------------\n");
            printf(">>>>>>>>>>>>>>>>>>>> Record Found <<<<<<<<<<<<<<<<<<<\n");
            printf("------------------------------------------------------\n\n");
            printf("------------------------------------------------------\n\n");
            printf("> Book Name: %s \n", b.book_name);
            printf("> author name: %s \n", b.author_name);
            printf("> book category:%s \n", b.book_category);
            printf("> book id: %d \n", b.book_id);
            printf("------------------------------------------------------\n\n");

            x = 1;
        }
    }
    if (x != 1)
    {
        printf("-----------------------------------------------------\n");
        printf(">>>>>>>>>>There is no book records added yet<<<<<<<<<<\n");
        printf("------------------------------------------------------\n\n");
    }
    fclose(f);
    getch();
}
void deletebook()
{

    int id, x = 0;
    struct book b;
    printf("\t\t\t\t=======delete bookS RECORD=======\n\n\n");
    printf("\t\t\t\tEnter book id :");
    scanf("%d", &id);
    FILE *f = fopen("book_record.txt", "r");
    FILE *pT = fopen("temporary.txt", "w");
    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF)
    {
        if (b.book_id != id)//yo id namileko data new file ma write garne
        {
            fprintf(pT, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, b.book_id);
        }
        else
        {
            x++;
            printf("\n---------------------\n");
            printf(">>> Record deleted<<< \n");
            printf("---------------------\n\n");
        }
    }
    fclose(f);
    fclose(pT);
    remove("book_record.txt");//purano file remove garne
    rename("temporary.txt", "book_record.txt");//new file ko nam purano file rakhne
}
void editbook()
{
    int id, x = 0;
    struct book upd;
    struct book b;
    printf("\t\t\t\t=======edit bookS RECORD=======\n\n\n");
    printf("\t\t\t\tEnter the book id : ");
    scanf("%d", &id);
    FILE *f = fopen("book_record.txt", "r");
    FILE *pT = fopen("temporary.txt", "w");
    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF)//read data to end of file
    {
        if (b.book_id == id)
        {
            printf("\nenter book name\n");
            scanf("%s", upd.book_name);
            printf("\nenter author name\n");
            scanf("%s", upd.author_name);
            printf("\nenter category\n");
            scanf("%s", upd.book_category);
            printf("\nenter book id\n");
            scanf("%d", &upd.book_id);
            fprintf(pT, "%s\t\t%s\t\t%s\t\t%d\n", upd.book_name, upd.author_name, upd.book_category, upd.book_id); // temporary.txt file ma data update gareara store gareko
        }
        else
        {
           
            fprintf(pT, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, b.book_id);
        }
    }
    fclose(f);
    fclose(pT);
    remove("book_record.txt");                  // book record file hatako
    rename("temporary.txt", "book_record.txt"); // ani temporary file ko nam book record rakheko
    MainPage();
}
void issue()
{
    int n;
    do
    {
        printf("\nPlease choose the search option below\n");
        printf("\n1>Issue New Book\t\t\t\t\t\t2>Display Issued Book\n3>MainPage\t\t\t\t\t\t\t4>Delete/Return Issued Book\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            issuebook();
            break;
        case 2:
            display_issued_book();
            break;
        case 3:
            MainPage();
            break;
        case 4:
            remove_issued_book();
            break;
        }
        getch();
    } while (n != 0);
}
void issuebook()
{
    int id, x = 0;
    char c = 'x';
    struct book b;
    struct student s;
    printf("\t\t\t\t=======ISSUE BOOK=======\n\n\n");

    printf("\t\t\t\tEnter the book id : ");
    scanf("%d", &id);
    FILE *f = fopen("book_record.txt", "r");
    FILE *pT = fopen("issue.txt", "a");
    while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.book_name, b.author_name, b.book_category, &b.book_id) != EOF)
    {
        if (b.book_id == id)
        {
            printf("\nBOOK IS AVAILABLE\n");
            printf(" Book Name : %s \n", b.book_name);
            printf(" Book ID : %d \n", b.book_id);
            printf("\nenter student name\n");
            scanf("%s", s.student_name);
            printf("\nenter student email\n");
            scanf("%s", s.student_email);
            printf("\nenter student sem\n");
            scanf("%d", &s.student_sem);
            printf("\nenter student id\n");
            scanf("%d", &s.student_id);
            fprintf(pT, "%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\n", b.book_name, s.student_name, s.student_email, s.student_sem, s.student_id, b.book_id);
            fclose(pT);
            printf("\ndo you wish to continue\nYes=Y\tNo=n\n");
            scanf("%s", &c);
            j++;
            if (c == 'Y' || c == 'y')
            {
                issuebook();
            }
            else
            {
                issue();
            }
        }
    }
    getch();
}
void display_issued_book()
{
    struct book b;
    struct student s;
    fflush(stdin);
    FILE *pT = fopen("issue.txt", "r");
    printf("-------------------------------\n");
    printf(">>> List of Books Record <<< \n");
    printf("-------------------------------\n\n");

    while (fscanf(pT, "%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\n", b.book_name, s.student_name, s.student_email, &s.student_sem, &s.student_id, &b.book_id) != EOF)
    {
        printf("-------------------------------\n");
        printf("> Book Name: %s \n", b.book_name);
        printf("> student name: %s \n", s.student_name);
        printf("> student email: %s\n", s.student_email);
        printf("> student sem: %d \n", s.student_sem);
        printf("> student ID: %d \n", s.student_id);
        printf("> book ID: %d \n", b.book_id);
        printf("-------------------------------\n\n\n");
        j++;
    }

    if (j == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no book records added yet...\n");
        printf("--------------------------------------\n\n");
    }
    fclose(pT);
}
void remove_issued_book()
{

    int id, x = 0, s_id;
    struct book b;
    struct student s;
    printf("\t\t\t\t======Delete issued book=======\n\n\n");
    printf("\t\t\t\tEnter book id :");
    scanf("%d", &id);
    printf("\t\t\t\tEnter student id :");
    scanf("%d", &s_id);
    FILE *pT = fopen("issue.txt", "r");
    FILE *pTr = fopen("temp.txt", "w");
    while (fscanf(pT, "%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\n", b.book_name, s.student_name, s.student_email, &s.student_sem, &s.student_id, &b.book_id) != EOF)
    {
        if (b.book_id != id && s.student_id != s_id)
        {
            fprintf(pTr, "%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\n", b.book_name, s.student_name, s.student_email, s.student_sem, s.student_id, b.book_id);
        }
        else
        {
            x++;
            printf("\n---------------------\n");
            printf(">>> Record deleted<<< \n");
            printf("---------------------\n\n");
        }
    }
    fclose(pT);
    fclose(pTr);
    remove("issue.txt");
    rename("temp.txt", "issue.txt");
}
