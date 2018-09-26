### Lab 4 - List ADT implemented with linked list

You are given an implementation of the integer list ADT using linked list and a client. It is all in the `linkedListAll.cpp` source code file.  You may download this repository using 

```
git clone https://github.com/ran-research-lab/ccom3034-b81-listWLinkedList
```

Your task is to complete the implementation of the following member functions:

1. **bool isSorted()**: determines if the list is sorted in ascending order. For example, if the list `L` currrently contains `(4, 9, 20)` then `L.isSorted()` returns `true`.


2. **void insertInOrder(ElementType val)**: given an integer *val* and assuming the list is already sorted in ascending order, this function will insert *val* into the list, conserving its ascending order. For example, if `L`  contains `(4, 9, 20)` then after `L.insertInOrder(15)` the list `L` contains `(4, 9, 15, 20)`

3. **LList merge(const LList & b) const**: given a second list (that is in ascending order), this function returns a third (ordered) list with the elements of the invoking list and the argument list. For example, if `L` contains `(4, 9, 20)` and `M` contains `(10, 23)` then `L.merge(M)` returns a list that contains `(4, 9, 10, 20, 23)`.



The provided client takes care of asking the user for a command and then invoking the corresponding function. The client understands the following commands:

* `i {value} {position}`: insert a *value* at a *position*. For example, if `L` contains `(4,8,1)`, after the command `i 10 2` it will contain `(4,8,10,1)`.  
* `e {position}`: erase the element at *position*. For example, if `L` contains `(4,8,1)`, after the command `e 0` it will contain `(8,1)`
* `d`: display the contents of the list.
* `is`: calls the `isOrdered()` function then prints message. 
* `io {value}`:  insert *value* into the list to maintain its order. For example, if `L` contains `(3, 6, 9)`, after the command `io 4`  it will contain `(3, 4, 6, 9)`.
* `m`: merge the list `(2,4,10)` with the current list and print the result. 
* `q`: quit the client program.

A `Makefile` is provided so that you may compile the program by simply typing `make` in the linux command line.

Please include the name of the programmers at the beginning of the file. Also provide comments before each of the functions. 
