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
    int data;
    struct node *next;
};

struct list{
    struct node *first;
    int number;
};

int main(int argc, const char * argv[]) {
    //create our vars
    struct list ordered[25];
    struct list unordered[25];
    int values[1000];
    int ulSearch, olSearch, ulInsert, olInsert;
//    : M + rand() / (RAND_MAX / (N - M + 1) + 1)
    int r, i;
    int N = 0;
    int M =  32767;
    ulSearch = olSearch = ulInsert = olInsert = 0;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate secret number between 1 and 32767 */
    for(i=0; i < 1000 ; i++){
        values[i] =
        printf("\n%d", M + rand() / (RAND_MAX / (N - M + 1) + 1));
    }

    //generate our array of 1000 random numbers
//    for(i = 0; i < 1000; i++)
//    {
//        values[i] = rand();
//    }
    
    
    printf("%d", RAND_MAX);
    
    
}
