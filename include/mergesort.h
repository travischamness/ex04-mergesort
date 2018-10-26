//
// Created by Travis on 10/8/2018.
//

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H
#include <cstdint>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

    template<typename T>
    void mergeSort(T array[], size_t size) {
        T j = (i + k)/2; //location identities within array
        T i = 0;
        T k = sizeof(array) - 1;

        while( right > 1eft ){
            mergeSort(T array[], int left, int middle);
            mergeSort(T array[], int middle + 1, int right);
        }

    }
    template<typename T>
    void merge(T array[], T i, T j, T k){
        T left = i; //T to keep everything of same type
        T right = j + 1;
        T middle = j;

        newSize = k - i + 1; //Details the full size of the new array
        mergeIndex = 0; //Initialized index of merged element
        mergedNumbers = new int[mergeIndex];

        while(left <= j && right <= k){
            if(array[left] <= array[right]){//organizing new heap array in order from least to greatest
                mergedNumbers[mergedIndex] = array[left];
                left++;
            }
            else{
                mergedNumbers[mergeIndex] = array[right];
                right++;
            }
            mergeIndex++; //increments up, sorting in each lesser element of the iteration. GENIUS
        }

        while(left <= j){//when loop above ends, need to include remaining values if any exist
            //Case where left set is larger than right set or singular
            mergedNumbers[mergeIndex] = array[left];
            left++;
            mergeIndex++
        }
        while(right <= k){//Case where right set is larger than left set or singular
            mergedNumbers[mergeIndex] = array[right];
            right++;
            mergeIndex++;
        }
        for(mergeIndex = 0; mergeIndex <= k-1; mergeIndex++){ //Copying the sorted indecies in the temporary array
            array[mergeIndex] = mergedNumbers[mergeIndex];
        }

    }




}}}}

#endif //EX04_MERGESORT_MERGESORT_H
