#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct person{
    
    //int number;
    char name[50];
    char phone[11];
    char note[256];
    struct person *next;

}person; 

// functions Header//
void print_list(struct person * r);
int size_of_list(struct person*r);
void add_info(struct person *r,char name[],char phone[],char note[]);
int initialization();
char* load(void);
struct person *add_by_order(struct person  *r,char temp_name[],char temp_phone[],char temp_note[]);
struct person *delete_element(struct person *r, int number);
struct person *edit_element(struct person *r, int number);
struct person *compare_charList_and_string(struct person *r,char str[]);
struct person *save_linked_list(struct person *r,char user_filename[]);
struct person *read_from_file_2_linked_list(struct person *r,char new_filename[]);
void free_list(struct person *r);
