//
//  main.c
//  LinkListInC
//
//  Created by Sunil Kumar on 20/03/16.
//  Copyright © 2016 Sunil Kumar. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>


struct node {
    int val;
    struct node *next;
};



void insert(struct node** head, int value) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    
    if (temp != NULL){
        temp -> val = value;
        temp -> next = NULL;
    }
    
    if(*head == NULL) {
        *head = temp;
    } else {
        struct node *save = *head;
        while (save ->next != NULL) {
            save = save ->next;
        }
        save -> next = temp;
    }
    
}

void show(struct node *head) {
    if (head == NULL) {
        return ;
    } else {
        while (head != NULL) {
            printf("%d -->",head -> val);
            head = head -> next;
        }
    }
    
}

struct node* reverseList(struct node* head){
    if (head == NULL) {
        return NULL;
    }
    
    if (head ->next == NULL) {
        return head;
    }
    
    struct node *secondNode = head -> next;
    head ->  next = NULL;
    struct node * save;
    while(secondNode != NULL) {
        save = secondNode -> next;
        secondNode -> next =  head;
        head =  secondNode;
        secondNode = save;
    }
    return head;
}


struct node * reverseListRecursive(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    if (head -> next == NULL) {
        return head;
    }
    struct node* temp = reverseListRecursive(head -> next);
    head -> next ->  next = head;
    head -> next = NULL;
    return temp;
}

void showInReverseOrder(struct node *head) {
    if (head == NULL) {
        return;
    }
    
    showInReverseOrder(head ->  next);
    printf("-->%d", head -> val);
}


int recursiveSum(struct node* head) {
    static int  sum;
    if (head == NULL) {
        return 0;
    }
    
    recursiveSum(head ->  next);
    sum = sum + head -> val;
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    struct node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    show(head);
    head = reverseList(head);
    show(head);
    head = reverseListRecursive(head);
    show(head);
    showInReverseOrder(head);
    int sum = recursiveSum(head);
    printf("-->sum == %d", sum);
    
    
    return 0;
}
