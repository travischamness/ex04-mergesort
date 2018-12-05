//
// Created by Travis on 10/8/2018.
//
//Line 45 SegFault
#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H
#include <cstdint>

using std::size_t;

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

                template<typename T>
                void merge(T array[], uint64_t _start, uint64_t halfpoint, uint64_t _end){
                    uint64_t L = _start; //Left step - Starts at array[0]
                    uint64_t R = halfpoint + 1; //Right step - Starts at array[half + 1]

                    uint64_t newSize = ((_end - _start) + 1); // Evaluates the new size of portion
                    int mergeIndex = 0; //Initialized index of merged element
                    T *mergedValues = new T [newSize];

                    while((L <= halfpoint) && (R <= _end)){
                        if(array[L] <= array[R]){//organizing new heap array in order from least to greatest including equivalency
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
                    while(R < _end){//Case where right set is larger than left set
                        mergedValues[mergeIndex] = array[R];
                        R++;
                        mergeIndex++;
                    }
                    for(mergeIndex; mergeIndex < _end; mergeIndex++){ //Copying the sorted indecies in the temporary array
                        array[mergeIndex] = mergedValues[mergeIndex];
                        //std::cout <<
                    }
                    delete [] mergedValues;
                }

                template<typename T>
                void _mergesort(T array[], uint64_t _start, uint64_t _end){

                    if ( _end > _start ){
                        uint64_t halfpoint = _start + ((_end - _start)/2);
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