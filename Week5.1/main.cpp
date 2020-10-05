#define CATCH_CONFIG_MAIN 
#include "int_set.hpp"
#include "catch.hpp"

TEST_CASE( "s.add(1), s.containts(1)" ){
    int_set s;
    s.add(1);
    REQUIRE( s.contains(1) );
}

TEST_CASE( "add various, contains various, including negative" ){
    int_set s;
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
    int_set s;
    s.add(1);
    s.remove(1);
    REQUIRE( !s.contains(1) );
}

TEST_CASE( "add various, remove various, contains various, including negative" ){
    int_set s;
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
    int_set s;
    s.add(1);
    std::stringstream str;
    str << s;
    REQUIRE( str.str() == "1 0 0 0 0 0 0 0 0 0 " );
}

TEST_CASE( "add various, operator<< various" ){
    int_set s;
    s.add(1);
    s.add(-6);
    s.add(43646);
    s.add(867);
    std::stringstream str;
    str << s;
    REQUIRE( str.str() == "1 -6 43646 867 0 0 0 0 0 0 " ); 
}