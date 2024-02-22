#include <stdlib.h>
#include<stdio.h>
#include "Strlist.h"
#include "string.h"

typedef struct _Node {
    char* _data;
    struct _Node* _next;
} Node;

typedef struct _StrList {
    Node* _head;
    size_t _size;
} StrList;

StrList* StrList_alloc() {
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if(newList){
    newList->_head = NULL;
    newList->_size = 0;
    }
    return newList;
}

void StrList_free(StrList* StrList) {
    Node* tmp = StrList->_head;
    Node* next;

    while (tmp != NULL) {
        next = tmp->_next;
        free(tmp->_data); 
        free(tmp); 
        tmp = next;
    }

    StrList->_head = NULL; 
    StrList->_size = 0; 
}

size_t StrList_size(const StrList* StrList)
{
     return StrList->_size;
}


  
  void StrList_insertLast(StrList* StrList, const char* data) {
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    new_node->_data = (char*)malloc(strlen(data) + 1); 
    if (new_node->_data == NULL) {
        free(new_node); 
        return;
    }
    strcpy(new_node->_data, data); 

    new_node->_next = NULL;
    if (StrList->_head == NULL) {
        StrList->_head = new_node;
    } else {
        Node* tmp = StrList->_head;
        while (tmp->_next != NULL) {
            tmp = tmp->_next;
        }
        tmp->_next = new_node;
    }

    StrList->_size++;
}



void StrList_insertAt(StrList* StrList, const char* data, int index) {
  
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->_data = (char*)malloc(strlen(data) + 1); 
    if (newNode->_data == NULL) {
        free(newNode); 
        return;
    }
    strcpy(newNode->_data, data); 
    if (index == 0) {
        newNode->_next = StrList->_head;
        StrList->_head = newNode;
    } else {
        Node* tmp = StrList->_head;
        for (int i = 0; i < index - 1 && tmp != NULL; ++i) {
            tmp = tmp->_next;
        }

        if (tmp == NULL) {
            free(newNode->_data); 
            free(newNode); 
            return;
        }
        newNode->_next = tmp->_next;
        tmp->_next = newNode;
    }
    StrList->_size++;
}


char* StrList_firstData(const StrList* StrList) {

    if (StrList->_head == NULL) {
        return NULL;
    }
    return StrList->_head->_data;
}

void StrList_print(const StrList* StrList) {
    Node* tmp = StrList->_head;
    
    while (tmp != NULL) {
        printf("%s ", tmp->_data);
        tmp = tmp->_next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* StrList, int index) {
     Node* tmp = StrList->_head;
    int count = 0;
    while (tmp != NULL && count < index) {
        tmp = tmp->_next;
        count++;
    }
        printf("%s\n", tmp->_data);

}

int StrList_printLen(const StrList* StrList) {

    int totalChars = 0;
    Node* tmp = StrList->_head;
    while (tmp != NULL) {
        totalChars += strlen(tmp->_data);
        tmp = tmp->_next;
    }
    return totalChars;
}

int StrList_count(StrList* StrList, const char* data) {
    int count = 0;
    Node* tmp = StrList->_head;
    while (tmp != NULL) {
        if (strcmp(tmp->_data, data) == 0) {
            count++;
        }
        tmp = tmp->_next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data) {

    Node* tmp = StrList->_head;
    Node* prev = NULL;

    while (tmp != NULL) {

        if (strcmp(tmp->_data, data) == 0) {
            if (prev == NULL) {
                StrList->_head = tmp->_next;
                free(tmp->_data);
                free(tmp);
                tmp = StrList->_head;
            } else {
                prev->_next = tmp->_next;
                free(tmp->_data);
                free(tmp);
                tmp = prev->_next;
            }
            StrList->_size--;
        } else {

            prev = tmp;
            tmp = tmp->_next;
        }
    }
}

void StrList_removeAt(StrList* StrList, int index) {
   
    Node* tmp = StrList->_head;
    Node* prev = NULL;
    
    for (int i = 0; i < index; ++i) {
        prev = tmp;
        tmp = tmp->_next;
    }

    if (prev == NULL) {
        StrList->_head = tmp->_next;
        free(tmp->_data);
        free(tmp);
    } else {
        prev->_next = tmp->_next;
        free(tmp->_data);
        free(tmp);
    }

    StrList->_size--;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {

    if (StrList1->_size != StrList2->_size) {
        return 0;
    }
    Node* tmp1 = StrList1->_head;
    Node* tmp2 = StrList2->_head;

    while (tmp1 != NULL && tmp2 != NULL) {
        if (strcmp(tmp1->_data, tmp2->_data) != 0) {
            return 0;
        }
        tmp1 = tmp1->_next;
        tmp2 = tmp2->_next;
    }
    return 1;
}

void StrList_reverse(StrList* StrList) {

    Node *prev = NULL;
    Node *next = NULL;
    Node *tmp = StrList->_head;
    
    while (tmp != NULL) {

        next = tmp->_next;
        tmp->_next = prev;
        prev = tmp;
        tmp = next;
    }
    StrList->_head = prev;
}

int StrList_isSorted(StrList* StrList) {
  if (StrList->_head == NULL || StrList->_head->_next == NULL) {
        return 1;
    }
    Node* tmp = StrList->_head;
    while (tmp->_next != NULL) {
        if (strcmp(tmp->_data, tmp->_next->_data) > 0) {
            return 0;
        }
        tmp = tmp->_next;
    }
    return 1; 
}

void StrList_sort(StrList* StrList) {
if (StrList->_size <= 1) {
        return;  
    }
    int swapped;
    Node *ptr;
    Node *last = NULL;

    do {
        swapped = 0;
        ptr = StrList->_head;
        while (ptr->_next != last) {
            if (strcmp(ptr->_data, ptr->_next->_data) > 0) {
                swap(&(ptr->_data), &(ptr->_next->_data)); 
                swapped = 1;
            }
            ptr = ptr->_next;
        }
        last = ptr;
    } while (swapped);

}
void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}



               



