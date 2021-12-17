#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "functions.h"

/* functions that i built
    initialization(void)
    print_list(struct person * r)
    size_of_list(struct person*r)
    add_info(struct person *r,char name[],char phone[],char note[])
    person *add_by_order(struct person  *r,char name[],char phone[],char note)
*/

// variables
int user_choice=0;

char temp_name[50];
char temp_phone[11];
char temp_note[50];
char newFilename[50];
char user_filename[50];
char str[50];
char temp;

int main(){
    person *root;
    root = NULL;
    
    while(1){
        user_choice = initialization();
        if(user_choice == 1){
            // new entry 
            printf("Enter a name:");
	        scanf("%[^\n]",temp_name);
            scanf("%c",&temp); 
	        printf("Enter a phone:");
	        scanf("%[^\n]",temp_phone);
            scanf("%c",&temp);
	        printf("Enter a Note:");
	        scanf("%[^\n]",temp_note);
            scanf("%c",&temp);
            //printf("%s %s %s\n",temp_name,temp_phone,temp_note);
            root = add_by_order(root,temp_name,temp_phone,temp_note);


        }else if(user_choice == 2){
            // list all entries
            print_list(root);

        }else if(user_choice == 3){
            // edit
            int local_var;
            printf("which one would you like to edit? \n");
            scanf("%d",&local_var);
            root = edit_element(root, local_var);
            // you should run the sorting algorithm

        }else if(user_choice == 4){
            // delete
            int local_var;
            printf("which one would you like to delete? \n");
            // deleting root should be regulated
            scanf("%d",&local_var);
            root = delete_element(root, local_var);

        }else if(user_choice == 5){
            // search
            printf("what is the word that you want to search? \n");
            scanf("%s",str);
            compare_charList_and_string(root,str);

        }else if(user_choice == 6){
            // save and exit
            //ask user for the name of the file
            printf("what is the file name ? \n");
            scanf("%s",user_filename);
            save_linked_list(root,user_filename);
            printf("file saved succesfully!\n");
            //free all linked list
            free_list(root);
            
            break;
        }else if(user_choice == 7){
            // load
           strcpy(newFilename,load());
           // get all data to linked list
           root = read_from_file_2_linked_list(root,newFilename);
        }
    }
}