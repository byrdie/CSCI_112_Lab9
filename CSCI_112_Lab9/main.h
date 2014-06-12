/* 
 * File:   main.h
 * Author: roy.smart
 *
 * Created on June 12, 2014, 11:13 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char content;
    struct Node * next;
    struct Node * previous;
}Node;

//typedef struct linkedl{
//    Node * head;
//    Node * tail;
//}linkedl;

void printlist(Node * next_node);
Node * insert(Node *, Node *);

#endif	/* MAIN_H */

