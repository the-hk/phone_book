#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

int initialization(){
    char temp;
    int user_in=0;
	printf("Welcome to myPhoneBook! Please select an option:\n");
	printf("1) New entry\n");
	printf("2) List all entries\n");
	printf("3) Edit\n");
	printf("4) Delete\n");
	printf("5) Search\n");
	printf("6) Save and exit\n");
	printf("7) Load\n");
	scanf("%d",&user_in);
    scanf("%c",&temp);
    return user_in;
}

void print_list(struct person * r){
    int local_counter=0;
    while(r != NULL){
        local_counter ++;
        printf("%d%s %s %s %s\n",local_counter,":)",r->name,r->phone,r->note);
        r = r->next;
    }

}

int size_of_list(struct person*r){
    int size = 0;
    while(r->next != NULL){
        r = r->next;
        size ++;
    }

    return size;
}
char* load(void){
  	char *newFilename =malloc(100 * sizeof(char));
	printf("what is your file name (don't forget to put extension):\n");
	scanf("%s",newFilename); 
	printf("file name was updated to %s\n",newFilename);
  	return newFilename;
}

struct person *add_by_order(struct person  *r,char temp_name[],char temp_phone[],char temp_note[]){
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int name_counter = 0;
    if(r == NULL){
        r = (person *)malloc(sizeof(person));
        r->next=NULL;
        strcpy(r->name,temp_name);
        strcpy(r->phone,temp_phone);
        strcpy(r->note,temp_note);
        return r;
    
    }
    if(r->name[0]==temp_name[0]){
        for(int i = 0; i<strlen(r->name);i++){
            if(r->name[i]==temp_name[i]){
                name_counter ++;
            }
        } 
    }
    if(r->name[name_counter] > temp_name[name_counter]){//compare two letters which are linked list root's letters and input letters root will be changed
        person *temp_r = (person *)malloc(sizeof(person));
        strcpy(temp_r->name, temp_name);
        strcpy(temp_r->phone, temp_phone);
        strcpy(temp_r->note, temp_note);
        temp_r->next= r;
        return temp_r;
        
    }
    person *iter = r;

    while(iter->next != NULL && iter->next->name[name_counter] < temp_name[name_counter]){
        iter = iter->next;
    }
    
    person *temp = (person *)malloc(sizeof(person));
    temp -> next = iter->next;
    iter->next = temp;
    strcpy(temp->name, temp_name);
    strcpy(temp->phone, temp_phone);
    strcpy(temp->note, temp_note);
    return r;
    
}
struct person *delete_element(struct person *r, int number){

    if(number == 1){
        r = r->next;
        return r;
    }
    if(number == 2){
        r->next = r->next->next;
        return r;
    }
    for(int i=2;i<number;i++){
        r=r->next;
    }
    r->next = r->next->next;
    return r;

}

struct person *edit_element(struct person *r, int number){
    char temp;
    char temp_name[50];
    char temp_phone[11];
    char temp_note[256];
    r = delete_element(r,number);

    printf("Enter a new name:");
    scanf("%c",&temp); 
	scanf("%[^\n]",temp_name);
    scanf("%c",&temp); 
	printf("Enter a new phone:");
	scanf("%[^\n]",temp_phone);
    scanf("%c",&temp);
	printf("Enter a new Note:");
	scanf("%[^\n]",temp_note);
    scanf("%c",&temp);
    r = add_by_order(r,temp_name,temp_phone,temp_note);
    return r;
}

struct person *compare_charList_and_string(struct person *r,char str[]){

    int local_i_str = 0;
    int local_counter = 0;
    int iter_counter=0;
    int match_counter = 0;
    int truth_flag= 0;

    size_t length_str=0;
    length_str = strlen(str);

    person *iter = r;
    while(iter != NULL){
        iter_counter ++;
        local_counter = 0;
        match_counter = 0;
        while(1){
            if(iter->name[local_counter] == str[local_i_str]||toupper(str[local_i_str])==iter->name[local_counter]){
                
                if(length_str>1){
                    for(int i = 0; i<length_str;i++){
                        if(iter->name[local_counter+i] == str[local_i_str+i]||toupper(str[local_i_str+i])==iter->name[local_counter+i]){
                            match_counter++;
                        }        
                    }
                    if(match_counter==length_str){
                        printf("it was found in name part and line number is %d\n",iter_counter);
                        truth_flag = 1;
                        break;
                    }
                    match_counter = 0;
                }else{
                    printf("it was found in name part and line number is %d\n",iter_counter);
                    break;
                }
            }
            local_counter++;
            if(strlen(iter->name)<=local_counter){
                break;

            }

        }
        local_counter =0;
        match_counter = 0;
        while(1){
            if(iter->phone[local_counter] == str[local_i_str]||toupper(str[local_i_str])==iter->phone[local_counter]){
                
                if(length_str>1){
                    for(int i = 0; i<length_str;i++){
                        if(iter->phone[local_counter+i] == str[local_i_str+i]||toupper(str[local_i_str+i])==iter->phone[local_counter+i]){
                            match_counter++;
                        }        
                    }
                    if(match_counter==length_str){
                        printf("it was found in phone part and line number is %d\n",iter_counter);
                        truth_flag = 1;
                        break;
                    }
                    match_counter = 0;
                }else{
                    printf("it was found in phone part and line number is %d\n",iter_counter);
                    break;
                }
            }
            local_counter++;
            if(strlen(iter->phone)<=local_counter){
                break;

            }

        }
        local_counter =0;
        match_counter = 0;
        while(1){
            if(iter->note[local_counter] == str[local_i_str]||toupper(str[local_i_str])==iter->note[local_counter]){
                
                if(length_str>1){
                    for(int i = 0; i<length_str;i++){
                        if(iter->note[local_counter+i] == str[local_i_str+i]||toupper(str[local_i_str+i])==iter->note[local_counter+i]){
                            match_counter++;
                        }        
                    }
                    if(match_counter==length_str){
                        printf("it was found in note part and line number is %d\n",iter_counter);
                        truth_flag = 1;
                        break;
                    }
                    match_counter = 0;
                }else{
                    printf("it was found in note part and line number is %d\n",iter_counter);
                    break;
                }
            }
            local_counter++;
            if(strlen(iter->note)<=local_counter){
                break;

            }

        }

        if(truth_flag == 1){
            break;
        }

        
        printf("%d\n",local_counter);
        iter = iter->next;
        local_counter = 0;
    }
    if(truth_flag == 0){
        printf("the text that you provide doesn't include in the list\n");
    }
    return r;

}
struct person *save_linked_list(struct person *r,char user_filename[]){
        person *iter = r;
        FILE *file;
        file = fopen(user_filename,"w");

        while(iter!=NULL){
            fwrite(iter, sizeof(person), 3, file);
            iter = iter->next;
        }
        fclose(file);
        return r;

}
struct person *read_from_file_2_linked_list(struct person *r,char new_filename[]){

    FILE *file;
    person *temp = (person*)malloc(sizeof(person));
    int loc_ctr=2;
    
    file = fopen(new_filename,"r");
    while(fread(temp,sizeof(person),1,file)){
        loc_ctr++;
        if(loc_ctr ==3){
            r=add_by_order(r,temp->name,temp->phone,temp->note);
            loc_ctr =0;
        }
        
    }
    return r;

}
void free_list(struct person *r){

    person *iter = r, *rnext;

    while (NULL != iter){

        rnext = iter->next;
        free(iter);
        iter = rnext;
    }

}