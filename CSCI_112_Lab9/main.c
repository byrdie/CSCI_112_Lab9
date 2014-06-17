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

    Node * masterlist = NULL;

    /*read in file and insert into linked list*/
    int result = 0;
    while (result != EOF) {
        Node * new_node = malloc(sizeof (Node));
        new_node->next = NULL; //init next node 
        result = fscanf(input_stream, "%c", &(new_node->content));
        //construct new node out of data
        if (isalpha(new_node->content)) masterlist = insert(masterlist, new_node);
    }
    printlist(masterlist);
    printf("\n");

    /*call to construct circular linked list*/
    Node * end_node = extra_credit_1(masterlist, masterlist);

    /*call to delete linked list*/
    extra_credit_2(masterlist, masterlist);
    if(masterlist == NULL){
        printf("List deleted successfully");
    }



    return (EXIT_SUCCESS);
}

/*print list recursively prints a linked list of nodes*/
void printlist(Node * next_node) {
    if (next_node != NULL) {
        printf("%c, ", next_node->content);
        printlist(next_node->next);
    }

}

/*
 * insert puts a new node at the head of the list if empty.
 * Puts a new node in alphabetical order if possible
 * if not inserts it at the end of the list
 */
Node * insert(Node * orig_node, Node * new_node) {
    if (orig_node == NULL) { //base case
        return new_node;
    }
    else if (orig_node->content > new_node->content) { //insert in-order
        new_node->next = orig_node;
        return new_node;
    } else if (orig_node->next == NULL) { //list has one member
        if (orig_node < new_node) { //new node is second
            orig_node->next = new_node;
            return orig_node;
        } else { //new node is first
            new_node->next = orig_node;
            return new_node;
        }
    } else { //recursive call
        orig_node->next = insert(orig_node->next, new_node);
        return orig_node;
    }
}

/*
 * extra_credit_1 receives a linked list and makes it circular by linking the
 * end node to the start of the list. The function returns the end of the list
 * for testing
 */
Node * extra_credit_1(Node * start_node, Node * current_node) {
    if (current_node->next == NULL) {
        current_node->next = start_node;
        return current_node;
    } else {
        return extra_credit_1(start_node, current_node->next);
    }
}

/*
 * extra_credit_2 frees all of the objects in the provided linked list returns 1
 * if successful, 0 if unsuccessful
 */
int extra_credit_2(Node* start_node, Node* current_node) {
    Node * temp_node = current_node->next;
    printf("freed %c\n", current_node->content);
    free(current_node);
    if(temp_node != start_node){
        extra_credit_2(start_node, temp_node);
    }    
}