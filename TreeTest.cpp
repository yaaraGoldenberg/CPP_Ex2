/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
	ariel::Tree emptytree;
	ariel::Tree threetree;
	ariel::Tree myTreeTest;
	threetree.insert(5);
	threetree.insert(7);
	threetree.insert(3);

	int TreeKeys[11] = { 50,76,21,4,32,14,100,83,2,3,7};
	for (int i = 0; i < 10; i++) {
		myTreeTest.insert(TreeKeys[i]);
	}

	ariel::Tree mytree;

	badkan::TestCase tc("Binary tree");
	tc
		.CHECK_EQUAL(emptytree.size(), 0)
		.CHECK_OK(emptytree.insert(5))
		.CHECK_EQUAL(emptytree.size(), 1)
		.CHECK_EQUAL(emptytree.contains(5), true)
		.CHECK_OK(emptytree.remove(5))
		.CHECK_EQUAL(emptytree.contains(5), false)
		.CHECK_THROWS(emptytree.remove(5))
		.CHECK_EQUAL(emptytree.size(), 0)

		.CHECK_EQUAL(threetree.size(), 3)
		.CHECK_EQUAL(threetree.root(), 5)
		.CHECK_EQUAL(threetree.parent(3), 5)
		.CHECK_EQUAL(threetree.parent(7), 5)
		.CHECK_EQUAL(threetree.left(5), 3)
		.CHECK_EQUAL(threetree.right(5), 7)
		.CHECK_THROWS(threetree.insert(3))
		.CHECK_THROWS(threetree.left(6))
		.CHECK_OK(threetree.print())


	
		.CHECK_EQUAL(myTreeTest.contains(100), true)
		.CHECK_EQUAL(myTreeTest.root(), 50)
		.CHECK_EQUAL(myTreeTest.size(), 10)
		.CHECK_OK(myTreeTest.remove(50))
		.CHECK_EQUAL(myTreeTest.size(), 9)
		.CHECK_EQUAL(myTreeTest.root(), 76)
		.CHECK_EQUAL(myTreeTest.contains(50), false)
		.print();
		    


	cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}