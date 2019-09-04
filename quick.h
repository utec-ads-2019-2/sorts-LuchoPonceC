#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        int partition(int posl,int posr){
        	int i = posl;
        	for(int j = posl; j<posr-1; j++){
        		if(elements[j]<=elements[posr-1]){
        			swap(elements[i],elements[j]);
        			i++;
        		}
        	}
        	swap(elements[i],elements[posr-1]);
        	return i;
        }

        void quick(int posl, int posr){

        	if(posr-posl>1){
            	int mid = partition(posl,posr);
        		quick(posl,mid);
        		quick(mid+1,posr);  
        	}
        }

        void execute() {
        	int posr,posl;
    		posr = size;
    		posl = 0;
        	quick(posl, posr);
        	
        }

        inline string name() { return "QuickSort"; }
};

#endif