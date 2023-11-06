#include "catch_amalgamated.hpp"
#include "QueueOfStrings.hpp"
#include "HotPotato.hpp"
#include <string>
#include <fstream>  


/*
 * Note how few test cases we have as required here.


 This DOES NOT mean there is very little to do; 
    This DOES mean you are expected to test your code.
    Note that we haven't even provided test cases that *call* 
        every function within QueueOfStrings.
        That would probably be a good first thing for you to write...
 */



namespace{


// Tests enqueue, front, and front const
TEST_CASE("MyFirstEnqueue", "[RequiredQueue]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE( a.front() == "Mike" );
}

// Tests front, front const, and isEmpty
TEST_CASE("FrontThrowsWhenNone", "[RequiredQueue]")
{
    QueueOfStrings q;
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
}

// Tests size
TEST_CASE("Size1", "[RequiredQueue]")
{
    QueueOfStrings q;
    q.enqueue("Mike");
    REQUIRE( q.size() == 1);
}
TEST_CASE("Size2", "[RequiredQueue]")
{
    QueueOfStrings q;
    REQUIRE( q.size() == 0);
}

// Tests enqueue, dequeue, size
TEST_CASE("MyFirstDequeue", "[RequiredQueue]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE( a.front() == "Mike" );
    a.dequeue();
    REQUIRE( a.size() == 0);
}
TEST_CASE("MySecondDequeue", "[RequiredQueue]")
{
    QueueOfStrings a;
    REQUIRE_THROWS_AS( a.dequeue(), QueueEmptyException );
}

// Tests copy
TEST_CASE("Copy1", "[RequiredQueue]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE( a.front() == "Mike" );

    QueueOfStrings q(a);
    REQUIRE( q.front() == "Mike");
}
TEST_CASE("Copy2", "[RequiredQueue]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE( a.front() == "Mike" );

    QueueOfStrings q(a);
    REQUIRE( q.front() == "Mike");

    a.enqueue("Mikey");
    REQUIRE( a.size() == 2);
    REQUIRE( q.size() == 1);
}

// tests assignment operator
TEST_CASE("SelfAssignment", "[RequiredQueue]")
{
    QueueOfStrings q;
    q.enqueue("Test");
    q = q;
    REQUIRE(q.front() == "Test");
}
TEST_CASE("Assignment1", "[RequiredQueue]")
{
    QueueOfStrings q;
    q.enqueue("Test1");
    q.enqueue("Test2");

    QueueOfStrings a;
    a.enqueue("Test3");

    a = q;
    REQUIRE(a.front() == "Test1");
    REQUIRE(a.size() == 2);
}
TEST_CASE("Assignment2", "[RequiredQueue]")
{
    QueueOfStrings q;
    q.enqueue("Test1");
    q.enqueue("Test2");

    QueueOfStrings a;
    a.enqueue("Test3");

    a = q;
    q.enqueue("Test4");
    REQUIRE(a.front() == "Test1");
    REQUIRE(a.size() == 2);
    REQUIRE(q.size() == 3);
}


TEST_CASE("SimpleHotPotato", "[RequiredHotPotato]")
{
    std::ifstream in{"hp_names_1.txt"};
    std::vector<unsigned> numOfPasses{5, 3};
    REQUIRE("Lakshmi" == playHotPotato(in, numOfPasses));
}








                        
} // end namespace

