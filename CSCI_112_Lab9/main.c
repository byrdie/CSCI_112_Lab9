/* 
 * File:   main.c
 * Author: roy.smart
 *
 * Created on June 12, 2014, 11:13 AM
 */

#include "main.h"

/*
 * opens file puts each character into alphabetical linked list
 */
int main(int argc, char** argv) {
    char * path = "pangram.txt";
    FILE * input_stream = fopen(path, "r");
    
    Node * masterlist;
    
    /*read in file and insert into linked list*/
    int result = 0;
    char new_content;
    while(result != EOF){
        Node * new_node = malloc(sizeof(Node));
        new_node->next = NULL;  //init next node 
        result = fscanf(input_stream, "%c%*[ ]", &(new_node->content));
         //construct new node out of data
        masterlist = insert(masterlist, new_node);
    }
    
    printlist(masterlist);
    
    return (EXIT_SUCCESS);
}

/*print list recursively prints a linked list of nodes*/
void printlist(Node * next_node){
    if(next_node != NULL) {
        printf("%c \n", next_node->content);
        printlist(next_node->next);
    }
}

/*
 * insert puts a new node at the head of the list if empty.
 * Puts a new node in alphabetical order if possible
 * if not inserts it at the end of the list
 */ 
Node * insert(Node * orig_node, Node * new_node){
    puts("got here");
    if(orig_node == NULL){     //base case
        return new_node;
    }
    else if(orig_node->next == NULL){
        if(orig_node < new_node){
            orig_node->next = new_node;
            return orig_node;
        }
        else{
            new_node->next = orig_node;
            return new_node;
        }
    }
    else if(orig_node->next->content > new_node->content){      //insert in-order
        Node * temp_node = orig_node->next;
        orig_node->next = new_node;
        new_node->next = temp_node;
        return orig_node;
    }
    else{       //recursive call
        orig_node->next = insert(orig_node->next, new_node);
        return orig_node;
    }
}