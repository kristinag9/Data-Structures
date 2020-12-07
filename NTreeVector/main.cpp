#include "NTree.h"

int main()
{
    NTree tree;

    // String format: "" = insert element as a successor of current
    if (!tree.addElement(nullptr, 10)) {
        std::cout << "Error on 10\n";
        return -1;
    }

    if (!tree.addElement("", 3)) {
        std::cout << "Error on 3\n";
        return -1;
    }

    if (!tree.addElement("", 7)) {
        std::cout << "Error on 7\n";
        return -1;
    }

    if (!tree.addElement("", 12)) {
        std::cout << "Error on 8\n";
        return -1;
    }

    if (!tree.addElement("3", 5)) {
        std::cout << "Error on 5\n";
        return -1;
    }

    if (!tree.addElement("3", 8)) {
        std::cout << "Error on 8\n";
        return -1;
    }

    if (!tree.addElement("3", 9)) {
        std::cout << "Error on 9\n";
        return -1;
    }

    if (!tree.addElement("3 8", 1)) {
        std::cout << "Error on 1\n";
        return -1;
    }

    if (!tree.addElement("3 8", 2)) {
        std::cout << "Error on 2\n";
        return -1;
    }

    if (!tree.addElement("7", 11)) {
        std::cout << "Error on 11\n";
        return -1;
    }

    if (!tree.addElement("7", 13)) {
        std::cout << "Error on 13\n";
        return -1;
    }

    if (!tree.addElement("12", 6)) {
        std::cout << "Error on 6\n";
        return -1;
    }

    if (!tree.addElement("12", 4)) {
        std::cout << "Error on 4\n";
        return -1;
    }
    
    std::cout << "Testing print(): ";
    tree.print(std::cout);
    std::cout << '\n';

    std::cout << "Does the tree contain element 5? " << std::boolalpha << tree.contains(5) << '\n';
    std::cout << "Does the tree contain element 14? " << std::boolalpha << tree.contains(14) << '\n';

    std::cout << "Sum of the elements in the tree: " << tree.sum() << '\n';
    std::cout << "Max element of the tree: " << tree.findMaxElement() << '\n';
    std::cout << "Number of elements in the tree: " << tree.countElements() << '\n';

    std::cout << "Elements on level 2: ";
    tree.elementsOnKLevel(2);
    std::cout << '\n';

    std::cout << "Max height: " << tree.findMaxHeight() << '\n';

    NTree emptyTree;
    std::cout << "Max height with empty tree: " << emptyTree.findMaxHeight() << '\n';
    
    std::cout << "Testing method printChildren(): ";
    tree.printChildren(8);
    std::cout << '\n';

    std::cout << "Breadth-first search: ";
    tree.printBFS();
    std::cout << '\n';

    std::cout << "Depth-first search: ";
    tree.printDFS();
    std::cout << '\n';

    NTree copyTree = tree;
    std::cout << "Copy tree: ";
    copyTree.print(std::cout);
    std::cout << '\n';
    
    std::cout << "Print neighbours of 1: ";
    tree.printNeighbours(1);
    std::cout << '\n';

    std::cout << "Print neighbours of 2: ";
    tree.printNeighbours(2);
    std::cout << '\n';

    std::cout << "Print neighbours of 5: ";
    tree.printNeighbours(5);
    std::cout << '\n';

    std::cout << "Print neighbours of 7: ";
    tree.printNeighbours(7);
    std::cout << '\n';

    std::cout << "Count of nodes which sum of their children is equal to their grandfather: " << tree.countSumEqualsToGrandfather() << '\n';
    
    std::cout << '\n';

    NTree sndTree;
    if (!sndTree.addElement(nullptr, 10)) {
        std::cout << "Error on 10\n";
        return -1;
    }

    if (!sndTree.addElement("", 3)) {
        std::cout << "Error on 3\n";
        return -1;
    }

    if (!sndTree.addElement("", 7)) {
        std::cout << "Error on 7\n";
        return -1;
    }

    if (!sndTree.addElement("", 12)) {
        std::cout << "Error on 12\n";
        return -1;
    }


    if (!sndTree.addElement("12", 6)) {
        std::cout << "Error on 6\n";
        return -1;
    }

    if (!sndTree.addElement("12", 4)) {
        std::cout << "Error on 4\n";
        return -1;
    }

    sndTree.print(std::cout);
    std::cout << '\n';

    std::cout << "Count of nodes which sum of their children is equal to their grandfather: " << sndTree.countSumEqualsToGrandfather() << '\n';
    
    return 0;
}