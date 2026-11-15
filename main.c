/*
Name:Manjusha Thiruveedhula
Registration Number:25048_005
Description:                    main.c
            main.c is the driver file of the project that controls the overall execution of the Inverted Search application. 
            It accepts file names as command-line arguments, validates them, stores the valid files in a linked list, 
            initializes the hash table, and displays the menu. 
            Based on the user's choice, it calls the functions to create, display, search, save, or update the database, 
            and manages the program flow until the user exits.
                                Validations.c
            validations.c contains all the file validation functions used before processing input files. 
            It checks whether the file has a .txt extension, verifies that the file exists and is not empty, 
            detects duplicate file names, inserts valid files into the linked list, and provides a function to 
            display the list of validated files. These validations ensure that only valid input files are used 
            to create the inverted search database.
                                Create_list.c
            The create_database() function builds the inverted search database by reading all the input files one by one. 
            Each word is hashed based on its first character and stored in the corresponding hash table index. 
            If the word is already present, the function updates its file information and occurrence count; otherwise, 
            it creates a new main node and subnode for the word. 
            After processing all the files, the hash table contains every unique word along with the filenames 
            in which it appears and the number of times it occurs.
                                Update_data.c
            update_data.c is responsible for updating the current database from a previously saved database file. 
            It validates the database file, reconstructs the hash table by creating the required main and sub nodes, 
            and removes files that are already present in the database from the file linked list. 
            This ensures that only newly added files are available for indexing.
                                Search_word.c
            search_word.c implements the search functionality of the project. It accepts a word from the user, 
            computes its hash index based on the first character, searches the corresponding hash table bucket, 
            and displays the files in which the word is present along with the number of occurrences in each file.
                                Save_data.c
            save_data.c contains the function to save the inverted database into a text file. 
            It validates the output file name, opens the file in write mode, traverses the hash table, and writes 
            each word along with its file count, total occurrences, filenames, and word counts in a predefined format. 
            This allows the database to be restored later without recreating it.
*/



#include "main.h"
#include<stdio.h>

int main(int argc,char *argv[])
{

    if(argc < 2)
    {
        printf(RED "ERROR: File usage should be ./a.out <file1name> file2name>.....<filenname>\n"RESET);
        return 0;
    }
    fileNode_t *head=NULL;
    for(int i=1;i<argc;i++)
    {
        int ret=validate_and_insert(&head,argv[i]);
        {
            if(ret==SUCCESS)
            {
                printf(GREEN "Validation success for %s\n"RESET,argv[i]);
            
                printf(GREEN "insertion of %s is done\n"RESET,argv[i]);
                print_file(head);
                
            }
            else if(ret==FAILURE)
            {
                printf(RED "validation failed for %s\n"RESET,argv[i]);
                return 0;
            }
            else if(ret==DUPLICATE)
            {
                printf(RED"Duplicate file is skipped: %s\n"RESET,argv[i]);
            }
        }
    }


    hash_t arr[27];
    hash_table(arr);

    int created=0;
    int update=0;

    int choice;
    while(1)
    {
        printf(CYAN "=====================================MENU===================================\n"RESET);
        printf(DEEP_PURPLE "1. Create Database\n"RESET);
        printf(DEEP_PURPLE "2. Display Database\n"RESET);
        printf(DEEP_PURPLE "3. Search Word\n"RESET);
        printf(DEEP_PURPLE "4. Save Database\n"RESET);
        printf(DEEP_PURPLE "5. Update Database\n"RESET);
        printf(DEEP_PURPLE "6. Exit\n");
        printf(CYAN "===========================================================================\n"RESET);
        scanf("%d",&choice);

        switch(choice)
        {
            int ret;
            case 1:
                if(created==1)
                {
                    printf(RED "ERROR: Database already created...Can't create again\n"RESET);
                    break;

                }
                
                ret=create_database(arr,&head);
                if(ret==SUCCESS)
                {
                    printf(GREEN "INFO : DATABASE IS CREATED SUCCESSFULLY\n"RESET);
                    created=1;
                }
                else 
                {
                    printf(RED "INFO : Creation of Database for is failed\n"RESET);
                }
            break;

            case 2:
                
                ret=display_database(arr);
                if(ret==SUCCESS)
                {
                    printf(GREEN "SUCCESS : DATABASE IS DISPLAYED SUCCESSFULLY\n"RESET);
                }
                else
                {
                    printf(RED"ERROR : Display Database is failed\n"RESET);
                }
            break;

            case 3:
                
                search_database(arr);
            break;
            case 4:
                ret=save_database(arr);
                if(ret==SUCCESS)
                {
                    printf(GREEN "INFO : DATABASE IS SAVED SUCCESSFULLY\n"RESET);
                }
                else
                {
                    printf(RED "ERROR : Unable to save the database\n"RESET);
                }

            break;

            case 5:
                if(update==1)
                {
                    printf(RED"Database is already updated\n"RESET);
                }
                ret=update_database(arr,&head);
                if(ret==SUCCESS)
                {
                    printf(GREEN "DATABASE IS UPDATED SUCCESSFULLY\n"RESET);
                    print_file(head);
                    created=0;
                    update=1;
                }
                else
                {
                    printf(RED "ERROR : Database update is failed\n"RESET);
                }
            break;

            case 6:
                printf(BLUE "Exiting the program....\n"RESET);
                return 0;
            default:
                printf(RED "ERROR : Invalid choice. Try again\n"RESET);
        }
    }

}
