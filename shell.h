#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            	
            int temporal,j;

        	for(int division = size/2; division > 0; division/=2){

                for(int i = division; i< size; i++){

                    temporal = elements[i];

                

                for(j = i; elements[j-division] > temporal && j>=division; j = j-division){
                    elements[j] = elements[j-division];
                }

                elements[j] = temporal;

                }
            }

        }

        inline string name() { return "ShellSort"; }
};

#endif