#define CATCH_CONFIG_MAIN 
#include "int_set.hpp"
#include "catch.hpp"
#include <string>
using namespace std;

TEST_CASE( "s.add(1), s.containts(1)" ){
    setOfThings<int, 10> s;
    s.add(1);
    REQUIRE( s.contains(1) );
}

TEST_CASE( "add various, contains various, including negative" ){
    setOfThings<int, 10> s;
    s.add(1);
    s.add(-6);
    s.add(43646);
    s.add(867);
    REQUIRE( s.contains(1) );
    REQUIRE( s.contains(-6) );
    REQUIRE( s.contains(43646) );
    REQUIRE( s.contains(867) );
}

TEST_CASE( "s.add(1), s.remove(1), s.containts(1)" ){
    setOfThings<int, 10> s;
    s.add(1);
    s.remove(1);
    REQUIRE( !s.contains(1) );
}

TEST_CASE( "add various, remove various, contains various, including negative" ){
    setOfThings<int, 10> s;
    s.add(1);
    s.add(-676);
    s.add(4364633);
    s.add(867);
    s.remove(-676);
    s.remove(4364633);
    REQUIRE( s.contains(1) );
    REQUIRE( !s.contains(-676) );
    REQUIRE( !s.contains(4364633) );
    REQUIRE( s.contains(867) );
}

TEST_CASE( "s.add(1), operator<<" ){
    setOfThings<int, 10> s;
    s.add(1);
    std::stringstream str;
    str << s;
    REQUIRE( str.str() == "1 " );
}

TEST_CASE( "add various, operator<< various" ){
    setOfThings<int, 10> s;
    s.add(1);
    s.add(-6);
    s.add(43646);
    s.add(867);
    std::stringstream str;
    str << s;
    REQUIRE( str.str() == "1 -6 43646 867 " ); 
}


//string


TEST_CASE( "s.add(string), s.containts(1)" ){
    setOfThings<string, 5> s;
    s.add("string");
    REQUIRE( s.contains("string") );
}

TEST_CASE( "add various strings, contains various string, including backslash and enter" ){
    setOfThings<string, 5> s;
    s.add("string");
    s.add("\n");
    s.add("3");
    s.add("\\");
    REQUIRE( s.contains("string") );
    REQUIRE( s.contains("\n") );
    REQUIRE( s.contains("3") );
    REQUIRE( s.contains("\\") );
}

TEST_CASE( "s.add(string), s.remove(string), s.containts(string)" ){
    setOfThings<string, 5> s;
    s.add("string");
    s.remove("string");
    REQUIRE( !s.contains("string") );
}

TEST_CASE( "add various strings, remove various strings, contains various strings" ){
    setOfThings<string, 5> s;
    s.add("string");
    s.add("\n");
    s.add("3");
    s.add("\\");
    s.remove("string");
    s.remove("\\");
    REQUIRE( s.contains("\n") );
    REQUIRE( !s.contains("string") );
    REQUIRE( !s.contains("\\") );
    REQUIRE( s.contains("3") );
}

TEST_CASE( "s.add(string), operator<<" ){
    setOfThings<string, 5> s;
    s.add("string");
    std::stringstream str;
    str << s;
    REQUIRE( str.str() == "string " );
}

TEST_CASE( "add various strings, operator<< various strings" ){
    setOfThings<string, 10> s;
    s.add("string");
    s.add("\n");
    s.add("3");
    s.add("\\");
    std::stringstream str;
    str << s;
    REQUIRE( str.str() == "string \n 3 \\ " ); 
}