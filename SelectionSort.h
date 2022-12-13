#ifndef SELECTION_SORT_H__
#define SELECTION_SORT_H__

/**
 * Constants for sort order
 */
const unsigned short ORDER_ASCENDING = 0;
const unsigned short ORDER_DESCENDING = 1;

/**
 *
 * @param a - integer LHS
 * @param b - integer RHS
 * @return true if a < b
 */
bool descending(const int a, const int b);

/**
 *
 * @param a - integer LHS
 * @param b - integer RHS
 * @return true if a >= b
 */
bool ascending(const int a, const  int b);
/**
 * Swap the values that the 2 pointers point
 * @param a - pointer to var a
 * @param b - pointer to var b
 */
void swapValues( int* const a, int* const b);

/**
 * Perform the selection sort
 * @param numbers - pointer to array of integers
 * @param n - number of elements in array pointer points
 * @param order - function pointer to which comparison to (sort order) to perform.
 */
void selectionSort(int* const numbers, const int n,  bool (*order)(const int, const int));

#endif
