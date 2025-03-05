#ifndef BITSET_H
#define BITSET_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../errors/errors.h"
#include "../output/output.h"

#define BIT_PER_BLOCK 64
#define MIN_BUFFER_SIZE 1024
#define MAX_NUMBER_LENGTH 16

typedef void (*outputFunc)(const char *);

typedef struct BitSet {
  uint64_t *bits;   // Dynamic block of bits
  size_t size;      // Number of blocks
  size_t capacity;  // Maximum number of elements
} BitSet;

/*
  Creates the structure of a biting set with a given size.
  In case of error, NULL returns
*/
BitSet createBitSet(size_t capacity);

/*
  Removes the BitSet structure
*/
void destroyBitSet(BitSet *bitSet);

/*
  Adds a number in set if it is positive
  and permissible, otherwise it passes it
*/
BaseErrorCode addBitSetElement(const BitSet *bitSet, uint64_t element);

/*
  Adds several numbers in set if they are positive
  and permissible, otherwise passes them
*/
BaseErrorCode addManyBitSetElements(const BitSet *bitSet, size_t count,
                                const uint64_t elements[]);

/*
  Removes an element from the set
*/
BaseErrorCode removeBitSetElement(const BitSet *bitSet, uint64_t element);

/*
  Checks if there is an element in the set
*/
bool isBitSetContains(const BitSet *bitSet, uint64_t element);

/*
  Checks whether two sets are equal
*/
bool isBitSetsEqual(const BitSet *, const BitSet *);

/*
  Checks whether setA ⊆ setВ
*/
bool isSubset(const BitSet *bitSetA, const BitSet *bitSetB);

/*
  Checks whether setA ⊂ setВ
*/
bool isStrictSubset(const BitSet *bitSetA, const BitSet *bitSetB);

/*
  Returns the maximum capacity among two sets
*/
size_t getMaxBitSetCapacity(const BitSet *bitSetA, const BitSet *bitSetB);

/*
  Creates a set with the meaning А ∪ В
*/
BitSet getBitSetsUnion(const BitSet *, const BitSet *);

/*
  Creates a set with the meaning А ∩ В
*/
BitSet getBitSetsIntersection(const BitSet *, const BitSet *);

/*
  Creates a set with the meaning А - В
*/
BitSet getBitSetsDiff(const BitSet *bitSetA, const BitSet *bitSetB);

/*
  Creates a set with the meaning А △ В
*/
BitSet getSymmetricBitSetsDiff(const BitSet *bitSetA, const BitSet *bitSetB);

/*
  Creates a set, the meaning of which is the complement of this set
*/
BitSet getBitSetComplement(const BitSet *);

/*
  Displays a set to the function for showing
*/
BaseErrorCode printBitSet(const BitSet *bitSet, outputFunc output);

#endif