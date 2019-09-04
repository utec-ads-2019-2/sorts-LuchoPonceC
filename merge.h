#ifndef MERGE_H
#define MERGE_H
#include <iostream>
#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}

        void Merge(int left, int middle, int right){
        	int tam1 = middle - left + 1;
        	int tam2 = right - middle;

        	int aux1[tam1], aux2[tam2];

        	for(int i=0; i<tam1; i++){
        		aux1[i] = elements[left+i];
        	}
        	for(int i=0; i<tam2; i++){
        		aux2[i] = elements[middle+1+i];
        	}

        	int i=0,j=0,k=left;

        	while(i<tam1 and j<tam2){
        		if(aux1[i]<=aux2[j]){
        			elements[k] = aux1[i];
        			i++;
        		}
        		else{
        			elements[k] = aux2[j];
        			j++;
        		}
        		k++;
        	}

        	
        	while(i<tam1){
        		elements[k] = aux1[i];
        		i++;k++;
        	}

        	while(j<tam2){
        		elements[k] = aux2[j];
        		j++;k++;
        	}


        }

        void MyMergeSort(int left, int right){
        	if(right>left){
        		int middle = (left+right)/2;
        		MyMergeSort(left,middle);
        		MyMergeSort(middle+1,right);
        		Merge(left,middle,right);
        	}
        }

        void execute() {
        	int left = 0,right = size-1;
        	int middle = (left + right)/2;
            MyMergeSort(left, middle);
            MyMergeSort(middle+1,right);
            Merge(left,middle,right);
   
        }

        inline string name() { return "MergeSort"; }
};

#endif