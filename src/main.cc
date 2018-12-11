/**
* CS V15 Data Structures and Algorithms
* CRN:
*Assignment : ex04 - Mergesort
*
* Statement of code ownership : I hereby state that I have written all of this
* code and I have not copied this code from any other person or source.
*
* @author travis_chamness1@my.vcccd.edu
*/

#include"mergesort.h"
#include<iostream>
#include<string>
using std::endl;
using std::cout;
int main(){

    int64_t array[] = {1,3,2,7,4,10,9,8};
    size_t size = 8;
    edu::vcccd::vc::csv15::mergesort(array, size);

    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }

return 0;
}