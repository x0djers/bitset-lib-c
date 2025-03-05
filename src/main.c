#include "bitset/bitset.h"
#include "output/output.h"

int  main() {
  const size_t universeSize = 10;

  const BitSet bitSetA = createBitSet(universeSize);
  const uint64_t  elementsA[4] = {1, 2, 4, 9};
  addManyBitSetElements(&bitSetA, 4, elementsA);

  const BitSet bitSetB = createBitSet(universeSize);
  const uint64_t  elementsB[5] = {2, 3, 4, 5, 6};
  addManyBitSetElements(&bitSetB, 5, elementsB);

  const BitSet bitSetC = createBitSet(universeSize);
  const uint64_t  elementsC[5] = {3, 4, 6, 7, 8};
  addManyBitSetElements(&bitSetC, 5, elementsC);

  const BitSet bitSetD = createBitSet(universeSize);
  const uint64_t  elementsD[6] = {1, 2, 4, 5, 7, 8};
  addManyBitSetElements(&bitSetD, 6, elementsD);

  const BitSet _1 = getBitSetsDiff(&bitSetA, &bitSetD);
  const BitSet _2 = getBitSetComplement(&_1);
  const BitSet _3 = getBitSetsIntersection(&bitSetA, &bitSetB);
  const BitSet _4 = getBitSetsIntersection(&bitSetB, &bitSetC);
  const BitSet _5 = getBitSetsUnion(&_3, &bitSetC);
  const BitSet _6 = getBitSetsDiff(&_5, &bitSetD);
  const BitSet _7 = getSymmetricBitSetsDiff(&_6, &_4);
  const BitSet _8 = getBitSetsUnion(&_2, &_7);

  printf("Результат выражения: ");
  printBitSet(&_8, outputToStdOut);

  return 0;
}