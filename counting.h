#ifndef COUNTING_H
#define COUNTING_H

#include <iostream>
#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int max=elements[0];
            for(int i=0;i<size;i++){
                if(max<elements[i]){
                    max = elements[i];
                }
            }
            int output[size+1] = {0};
            int ayuda[max+1] = {0};

            for(int i=0; i<size;i++){
                ayuda[elements[i]]+=1;
            }
                
            for(int i=1; i<=max; i++){
                ayuda[i] += ayuda[i-1];
            }

            for(int i=0;i<size;i++){
                output[ayuda[elements[i]]-1] = elements[i];
                --ayuda[elements[i]];
            }        

            for(int i=0; i<size; i++){
                elements[i] = output[i];
            }

            

        }

        inline string name() { return "CountingSort"; }
};

#endif