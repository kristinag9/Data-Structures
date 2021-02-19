#include "Graph.h"
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_VALUE_PARAMETERIZED_DATA
#include "doctest.h"

TEST_CASE("Testing if there is a path between two given junctions") {
    // create an object - graph
    Graph graph;

    // if the graph cannot be red from the file, return -1 and exit
    if (graph.read("test.txt") == false) {
        std::cout << "Couldn't read";
        return;
    }

    CHECK(graph.hasPath("Popa", "BSFS"));
    CHECK(graph.hasPath("Popa", "5Kyosheta")); 
    CHECK(graph.hasPath("Popa", "NDK"));
    CHECK(graph.hasPath("Popa", "Popa"));
    CHECK(graph.hasPath("BSFS", "Popa"));
    CHECK(graph.hasPath("5Kyosheta", "Popa"));
    CHECK(graph.hasPath("5Kyosheta", "5Kyosheta"));
    CHECK(graph.hasPath("5Kyosheta", "BSFS"));
    CHECK(graph.hasPath("5Kyosheta", "Popa"));
}

TEST_CASE("Find best three paths between two given junctions") {
    // create an object - graph
    Graph graph;

    // if the graph cannot be red from the file, return -1 and exit
    if (graph.read("test.txt") == false) {
        std::cout << "Couldn't read";
        return;
    }

    DOCTEST_VALUE_PARAMETERIZED_DATA(graph.findBestThree("Popa", "5Kyosheta"), graph);
    DOCTEST_VALUE_PARAMETERIZED_DATA(graph.findBestThree("5Kyosheta", "NDK"), graph);
    DOCTEST_VALUE_PARAMETERIZED_DATA(graph.findBestThree("Popa", "BSFS"), graph);
    DOCTEST_VALUE_PARAMETERIZED_DATA(graph.findBestThree("Popa", "NDK"), graph);
    DOCTEST_VALUE_PARAMETERIZED_DATA(graph.findBestThree("NDK", "BSFS"), graph);
    DOCTEST_VALUE_PARAMETERIZED_DATA(graph.findBestThree("BSFS", "5Kyosheta"), graph);
}

TEST_CASE("Testing if there is a cycle in the graph") {
    // create an object - graph
    Graph graph;

    // if the graph cannot be red from the file, return -1 and exit
    if (graph.read("test.txt") == false) {
        std::cout << "Couldn't read";
        return;
    }

    CHECK(graph.hasCycle("Popa"));
    CHECK(graph.hasCycle("BSFS"));
    CHECK(graph.hasCycle("5Kyosheta"));
    CHECK(graph.hasCycle("NDK"));
}

TEST_CASE("Testing if there is a full tourist path in the graph") {
    // create an object - graph
    Graph graph;

    // if the graph cannot be red from the file, return -1 and exit
    if (graph.read("test.txt") == false) {
        std::cout << "Couldn't read";
        return;
    }

    CHECK(graph.hasTouristPath());
}

TEST_CASE("Testing if there is a path between one given junction and all of the others") {
    // create an object - graph
    Graph graph;

    // if the graph cannot be red from the file, return -1 and exit
    if (graph.read("test.txt") == false) {
        std::cout << "Couldn't read";
        return;
    }

    CHECK(graph.reachJunction("5Kyosheta"));
    CHECK(graph.reachJunction("BSFS"));
    CHECK(graph.reachJunction("Popa"));
    CHECK(graph.reachJunction("NDK"));
    CHECK(graph.reachJunction("JamesBoucher"));
}

TEST_CASE("Displaying all dead-end streets") {
    // create an object - graph
    Graph graph;

    // if the graph cannot be red from the file, return -1 and exit
    if (graph.read("test.txt") == false) {
        std::cout << "Couldn't read";
        return;
    }
   
    DOCTEST_VALUE_PARAMETERIZED_DATA(graph.deadEndStreet(), graph);
}

int main(int argc, char** argv) {
    // create an object - graph
    Graph graph;

    // if the graph cannot be read from the file, return -1 and exit
    if (graph.read("test.txt") == false) {
        std::cout << "Couldn't read";
        return -1;
    }
    // display the graph
    graph.write(std::cout);
    std::cout << '\n';

    doctest::Context context;

    // defaults
    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
    context.setOption("order-by", "name");            // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    int res = context.run(); // run the tests

    if (context.shouldExit()) // query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests

    int client_stuff_return_code = 0;

    return res + client_stuff_return_code; // the result from doctest is propagated here as well
}