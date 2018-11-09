//
// Created by Travis on 10/8/2018.
//

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H
#include <cstdint>
using std::size_t;

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

                template<typename T>
                void mergesort(T array[], size_t size) {
                    T _start = 0;
                    T _end = size - 1 ;


                    void _mergesort(array, _start, _end){
                        T newStart = _start;
                        T newEnd =  _end ;
                        T half = (newStart + newEnd)/2;

                        while ( newEnd > newStart ){
                            _mergesort(array, newStart, half);
                            _mergesort(array, half + 1, newEnd);
                            merge(array, newStart, half, newEnd);
                        }
                    }

                }
                template<typename T>
                void merge(T array[], T i, T j, T k){
                    T L = i; //starter index of Left side
                    T R = j + 1; //starter index of Right side
                    T middle = j;

                    T newSize = R - L + 1; //Details the full size of the new array
                    T mergeIndex = 0; //Initialized index of merged element
                    T mergedNumbers = new int[mergeIndex]; //iterator position 0

                    while(L <= j && R <= k){
                        if(array[L] <= array[R]){//organizing new heap array in order from least to greatest
                            mergedNumbers[mergeIndex] = array[L];
                            L++;
                        }
                        else{
                            mergedNumbers[mergeIndex] = array[R];
                            R++;
                        }
                        mergeIndex++; //increments up, sorting in each lesser element of the iteration. GENIUS
                    }

                    while(L <= j){//when loop above ends, need to include remaining values if any exist
                        //Case where left set is larger than right set or singular
                        mergedNumbers[mergeIndex] = array[L];
                        L++;
                        mergeIndex++;
                    }
                    while(R <= k){//Case where right set is larger than left set or singular
                        mergedNumbers[mergeIndex] = array[R];
                        R++;
                        mergeIndex++;
                    }
                    for(mergeIndex = 0; mergeIndex <= k-1; mergeIndex++){ //Copying the sorted indecies in the temporary array
                        array[mergeIndex] = mergedNumbers[mergeIndex];
                    }

                }


//                delete [] mergeIndex;

            }}}}

#endif