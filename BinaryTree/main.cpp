#include "BinaryTree.h"

int main()
{
    BinaryTree tree;

    if (tree.addElement("", 1) == false) {
        std::cout << "Cannot add element 1!\n";
        return 1;
    }
    if (tree.addElement("L", 2) == false) {
        std::cout << "Cannot add element 2!\n";
        return 1;
    }
    if (tree.addElement("R", 3) == false) {
        std::cout << "Cannot add element 3!\n";
        return 1;
    }
    if (tree.addElement("LL", 4) == false) {
        std::cout << "Cannot add element 4!\n";
        return 1;
    }
    if (tree.addElement("LR", 5) == false) {
        std::cout << "Cannot add element 5!\n";
        return 1;
    }
    if (tree.addElement("RL", 6) == false) {
        std::cout << "Cannot add element 6!\n";
        return 1;
    }
    if (tree.addElement("RR", 7) == false) {
        std::cout << "Cannot add element 7!\n";
        return 1;
    }

    std::cout << "Testing printPreorder: \n";
    tree.printPreorder(std::cout);
    std::cout << '\n';
    std::cout << "Testing printInorder: \n";
    tree.printInorder(std::cout);
    std::cout << '\n';
    std::cout << "Testing printPostorder: \n";
    tree.printPostOrder(std::cout);
    std::cout << '\n';
    std::cout << "Testing printLeaves: \n";
    tree.printLeaves();
    std::cout << '\n';
    std::cout << "Testing printOnKLevel: \n";
    tree.printOnKLevel(1);
    std::cout << '\n';
    //std::cout << "Testing printLeftSubtree: \n";
    //tree.printLeftSubtree();
    //std::cout << '\n';
    //std::cout << "Testing printRightSubtree: \n";
    //tree.printRightSubtree();
    //std::cout << '\n';

    std::cout << "\nNumber of elements in the tree: " << tree.numberOfElements() << '\n';
    std::cout << "Number of elements in the right subtree: " << tree.numberOfElemsInRight() << '\n';
    std::cout << "Number of elements in the left subtree: " << tree.numberOfElemsInLeft() << '\n';
    std::cout << "Number of leaves in the tree: " << tree.numberOfLeaves() << '\n';
    std::cout << "Number of odd elements in the tree: " << tree.numberOfOddElements() << '\n';
    std::cout << "Number of even elements in the tree: " << tree.numberOfEvenElements() << '\n';

    std::cout << "Is the tree empty? ";
    if (tree.isEmpty() == false) {
        std::cout << "No.\n";
    }
    else {
        std::cout << "Yes.\n";
    }
 
    std::cout << "Max height of the tree: " << tree.findMaxHeight() << '\n';
    std::cout << "Sum of elements: " << tree.sumOfElements() << '\n';
    std::cout << "Average: " << tree.average() << '\n';

    std::cout << "Is binary ordered tree? ";
    if (tree.isBinaryOrderedTree() == false) {
        std::cout << "No.\n";
    }
    else {
        std::cout << "Yes.\n";
    }
    
    std::cout << "Find the element on index 2: " << tree.findByIndex(2) << '\n';

   int* result = tree.createArray();

   for (int i = 0; i < 6; i++) {
       std::cout << result[i] << ' ';
   }

   std::cout << '\n';

   BinaryTree tree1;
   tree1.addElement("", 1);
   tree1.addElement("L", 2);
   tree1.addElement("R", 2);

   if (tree1.isSymmetric() == false) {
       std::cout << "No.\n";
   }
   else {
       std::cout << "Yes.\n";
   }

    return 0;
}