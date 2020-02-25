//
// Aladin Sidahmed U08614258 
// aladin.sidahmed@gmail.com
// C/C++ Programming II 
// Section 145010 Ray Mitchell 
// 24 FEB 2020
// C2A6E4_List.c
// Operating System: Windows 7 
// Visual Studio Community 2019 Version 16.3.2 
//
// SearchNode: Searches for a string in the linkedList,
//             returns pointer to the node with the string or NULL
// AddNode: Adds a node with a string to the end of the list
// CreateList: Creates a linkedList based on the input file 
// FreeList: recursivly frees memory allocated to store linked list
// PrintList: interates through list printing string and count values
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "C2A6E4_List-Driver.h"

#define BUFSIZE 256

static List *SearchNode(List *head, const char *buffer)
{
    //set the start value to the head of the list
    List *nodePtr = head;
    //iterate through the list until reaching NULL
    while (nodePtr != NULL)
    {
        if (strcmp(nodePtr->str, buffer) == 0)
        {
            //found string, return pointer
            return nodePtr;
        }
        else
        {
            //countinue to the end 
            nodePtr = nodePtr->next;
        }
    }
    return nodePtr;
}

static List *AddNode(List *head, const char *buffer)
{
    size_t bufferLength = (size_t)(strlen(buffer) + 1);
    //checks if the List is empty or not
    if (head)
    {
        //head is not equal to NULL
        List *nodePtr = head;
        //iterate to the end of the list to input the new Node
        while (nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next;
        }
        //create a new node and insert it to the end of the list
        List *newNode = (List *)malloc(sizeof(List));
        if (newNode == NULL)
        {
            fprintf(stderr, "Failed to allocate Node memory\n");
            exit(EXIT_FAILURE);
        }
        newNode->str = (char *)malloc(bufferLength);
        if (newNode->str == NULL)
        {
            fprintf(stderr, "Failed to allocate Node string memory\n");
            exit(EXIT_FAILURE);
        }
        memcpy(newNode->str, buffer, bufferLength);
        newNode->count = 1;
        newNode->next = NULL;
        nodePtr->next = newNode;
    }
    else 
    {
        //emptyList
        // head will be the list
        head = malloc(sizeof(List));
        if (head == NULL)
        {
            fprintf(stderr, "Failed to allocate Node memory\n");
            exit(EXIT_FAILURE);
        }
        head->str = (char *)malloc(bufferLength);
        if (head->str == NULL)
        {
            fprintf(stderr, "Failed to allocate Node string memory\n");
            exit(EXIT_FAILURE);
        }
        //copy the contents of the string to the newly created string
        //initiate remaining values
        memcpy(head->str, buffer, bufferLength);
        head->next = NULL;
        head->count = 1;
    }
    return head;
}

List *CreateList(FILE *fp)
{
    char buffer[BUFSIZE];
    List *linkedList = NULL;
    //read through the values of the file, one string at a time
    while (fscanf(fp, "%255s", buffer) == 1)
    {
        //search for the string in the linkedList
        List *nodePtr = SearchNode(linkedList, buffer);
        if (nodePtr != NULL)
        {
            //the string is found, increment count
            nodePtr->count++;
        }
        else 
        {
            //string not found, add new Node to list
            linkedList = AddNode(linkedList, buffer);
        }
    }
    return linkedList;
}

void FreeList(List *head)
{
    //recursive function, will stop once NULL is reached
    if (head) 
    {
        //Free next node
        FreeList(head->next);
        //Free the string
        free(head->str);
        // Free the node
        free(head);
    }
}

List *PrintList(const List *head)
{
    List *nodePtr = (List *)head;
    //Node will continue until reaches NULL
    while (nodePtr)
    {
        printf("    %-15s %5d ea\n", nodePtr->str, nodePtr->count);
        nodePtr = nodePtr->next;
    }
    return (List *)head;
}
