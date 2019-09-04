#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}


        void execute() {
            for(int i=0; i<size;i++){
            	int min = elements[i],indice=i;
            	for(int j=i+1;j<size;j++){
            		if(elements[j]<min){
            			indice = j;
            			min = elements[j];
            		}
            	}
            	swap(elements[i],elements[indice]);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif