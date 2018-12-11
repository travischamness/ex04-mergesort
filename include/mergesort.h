//
// Created by Travis on 10/8/2018.
//
//Line 45 SegFault
#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H
#include <cstdint>
#include <iostream>
#include<string>
using std::size_t;

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

                template<typename T>
                void merge(T array[], uint64_t _start, uint64_t halfpoint, uint64_t _end) {

                    size_t newSize = (_end - _start + 1); // Evaluates the new size of portion
                    auto *mergedValues = new T[newSize];
                    uint64_t mergeIndex = 0; //Initialized index of merged element
                    uint64_t L = _start; //Left step - Starts at array[0]
                    uint64_t R = halfpoint + 1; //Right step - Starts at array[half + 1]

                        while ((L <= halfpoint) && (R <= _end)) {
                            if (array[L] <= array[R]) {//organizing new heap array in order from least to greatest including equivalency
                                mergedValues[mergeIndex] = array[L];
                                L++;
                            } else {
                                mergedValues[mergeIndex] = array[R];
                                R++;
                            }
                            mergeIndex += 1; //increments up, sorting in each lesser element of the iteration. GENIUS
                           // std::cout << "MergreIndex: " << mergeIndex << " MergedValue: " << *mergedValues << std::endl;
                        }

                        while (L <= halfpoint) {//when loop above ends, need to include remaining values if any exist
                            //Case where left set is larger than right set or singular
                            mergedValues[mergeIndex] = array[L];
                            L++;
                            mergeIndex++;
                        }
                        while (R <= _end) {//Case where right set is larger than left set
                            mergedValues[mergeIndex] = array[R];
                            R++;
                            mergeIndex++;
                        }
                        for (mergeIndex = 0; mergeIndex < newSize; mergeIndex++) { //Copying the sorted indecies in the temporary array
                            array[_start + mergeIndex] = mergedValues[mergeIndex];
                            //std::cout << array[mergeIndex] << std::endl;
                        }
                        delete[] mergedValues;
                    }


                template<typename T>
                void _mergesort(T array[], uint64_t _start, uint64_t _end){
                    if (_end>_start){
                        uint64_t halfpoint =_start + (_end - _start)/2;
                        _mergesort(array, _start, halfpoint);//lhs
                        _mergesort(array, (halfpoint + 1), _end);//rhs
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

#endif //EX04_MERGESORT_MERGESORT_H

