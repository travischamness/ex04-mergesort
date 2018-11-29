//
// Created by Travis on 10/8/2018.
//

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H
#include <cstdint>
using std::size_t;

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

                template<typename T>
                void merge(T array[], uint64_t _start, uint64_t halfpoint, uint64_t _end){
                    uint64_t L = _start; //starter index of Left side
                    uint64_t R = halfpoint + 1; //starter index of Right side

                    T newSize = (R - L) + 1; //Details the full size of the new array
                    int mergeIndex = 0; //Initialized index of merged element
                    T *mergedValues = new T [newSize]; //= [mergeIndex]; //iterator position 0

                    while(L <= halfpoint && R <= _end){
                        if(array[L] <= array[R]){//organizing new heap array in order from least to greatest
                            mergedValues[mergeIndex] = array[L];
                            L++;
                        }
                        else{
                            mergedValues[mergeIndex] = array[R];
                            R++;
                        }
                        mergeIndex++; //increments up, sorting in each lesser element of the iteration. GENIUS
                    }

                    while(L <= halfpoint){//when loop above ends, need to include remaining values if any exist
                        //Case where left set is larger than right set or singular
                        mergedValues[mergeIndex] = array[L];
                        L++;
                        mergeIndex++;
                    }
                    while(R <= _end){//Case where right set is larger than left set
                        mergedValues[mergeIndex] = array[R];
                        R++;
                        mergeIndex++;
                    }
                    for(mergeIndex = 0; mergeIndex <= _end-1; mergeIndex++){ //Copying the sorted indecies in the temporary array
                        array[mergeIndex] = mergedValues[mergeIndex];
                    }
                }

                template<typename T>
                void _mergesort(T array[], uint64_t _start, uint64_t _end){
//                    uint64_t _start = _start;
//                    uint64_t _end =  _end ;
                    uint64_t halfpoint = _start + (_start + _end)/2;

                    if ( _end > _start ){
                        _mergesort(array, _start, halfpoint);
                        _mergesort(array, halfpoint + 1, _end);

                        merge(array, _start, halfpoint, _end);
                    }

                }

                template<typename T>
                void mergesort(T array[], size_t size) {
                    uint64_t _start = 0;
                    uint64_t _end = size - 1;

                    _mergesort(array, _start, _end);

                }

            }}}}

#endif