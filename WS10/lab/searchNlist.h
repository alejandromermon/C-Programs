#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_
#include "Collection.h"
#include <iostream>

using namespace std;

namespace seneca
{
	/**
	 * Searches for the specified element in an array and adds all found matches to a collection.
	 * 
	 * @tparam T - The type of elements stored in the Collection and the array. The Collection class must have an "add" method that takes an element of type T.
	 * @tparam U - The type of element to search for. Must be comparable to type T using the equality operator "==".
	 * @param col - A reference to a Collection object where the matching elements will be added.
	 * @param arr - The array of elements of type T to search.
	 * @param count - The number of elements in the array to search.
	 * @param srch - The element to search for in the array.
	 * @return true - The element is found in the array.
	 * @return false - The element is not found in the array.
	 *
	 */
	template <typename T, typename U>
	bool search(Collection<T>& col, T* arr, int count, const U srch) {
		bool found = false;
		for (auto i = 0; i < count; i++) {
			if (arr[i] == srch) {
				col.add(arr[i]);
				found = true;
			}
		}
		return found;
	}
	/**
	* Lists 'count"# of elements in an array printing each with a line number.
	*
	* @tparam T Type of elements in the array. It must support the "<<" operator overload.
	* @param title - The title to be printed before showing the list of elements.
	* @param arr - Pointer to an array of elements of type T.
	* @param count - The number of elements in the array.
	*
	*/
	template <typename T>
	void listArrayElements(const char* title, const T* arr, int count) {
		cout << title << endl;
		for (auto i = 0; i < count; i++) {
			cout << i + 1 << ": " << arr[i] << endl;
		}
	}
}
#endif // !SENECA_SEARCHNLIST_H_
