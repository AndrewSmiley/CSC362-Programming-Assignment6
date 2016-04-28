//
//  main.c
//  CSC362-Programming-Assignment6
//
//  Created by Andrew Smiley on 4/21/16.
//  Copyright © 2016 Andrew Smiley. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node{
    struct node *next;
    int data;
};

struct list{
    struct node *first;
    int number;
};

int hash(int value, int size);
struct list* insertOrdered(int hashed,int value, struct list *lists, int *counter);
struct list* insertUnordered(int hashed,int value, struct list *lists, int *counter);

int main(int argc, const char * argv[]) {
    //create our vars
    struct list lists1[25]={};
    struct list lists2[25]={};
    int values[1000];
    int ulSearch, olSearch, ulInsert, olInsert;
    struct list emptyO, emptyU;
    struct list a={NULL, 0};
//    emptyO =struct list {NULL, 0};
    
//    : M + rand() / (RAND_MAX / (N - M + 1) + 1)
    int r, i;
    int N = 0;
    int M =  32767;
    ulSearch = olSearch = ulInsert = olInsert = 0;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate secret number between 1 and 32767 */
    for(i=0; i < 1000 ; i++){
        values[i] =M + rand() / (RAND_MAX / (N - M + 1) + 1);
///        printf("\n%d", );
    }
    for(i=0; i < 23; i++){
        //a={NULL,0};
        struct list b= {NULL,0};
        lists1[i] = a;
        lists2[i] = b;
        
        
//        lists1[i] = struct list{NULL, 0}
//        lists2[i] = a;
    }
    //the first iteration
    for(i=0; i < 23; i++){
        //do the insertions
        insertUnordered(hash(values[i], 23), values[i], lists2, &ulInsert);
        insertOrdered(hash(values[i], 23), values[i], lists1, &olInsert);
        
    }
    printf("%d %d", ulInsert, olInsert);
    
    
//    printf("%d", RAND_MAX);
    
    
}


int hash(int value, int size){
    return value % size;
}

struct list* insertOrdered(int hashed,int value, struct list *lists, int *counter){
//    int hashed = hash(<#int value#>, <#int size#>)
    if (lists[hashed].first == NULL) {
        (*counter)++;
        struct list fuck = {{NULL, value}, 1};
        lists[hashed] = fuck;
        lists[hashed].number++;
        return &lists[hashed];
    
    }else{
        struct node fuck = *lists[hashed].first;
        while (fuck.next != NULL) {
            //check to see if this one goes next
            (*counter)++;
            if (value >= fuck.data ) {
                //just insert it
                struct node new = {fuck.next, value};
                fuck.next = &new;
                
            }
        }
        lists[hashed].number++;
        return &lists[hashed];
    }
    
    
}

struct list* insertUnordered(int hashed,int value, struct list *lists, int *counter){
    if (lists[hashed].first == NULL) {
        (*counter) ++;
        struct list fuck = {{NULL, value}, 1};
        lists[hashed] = fuck;
        lists[hashed].number++;
        return &fuck;
       
        
    }else{
        (*counter)++;
        struct list fuck = {{lists[hashed].first, value}, 1};
        lists[hashed] =fuck;
        lists[hashed].number++;
        return &lists[hashed];
        
        
    }
}









