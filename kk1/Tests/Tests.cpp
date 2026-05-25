#define CATCH_CONFIG_MAIN
#include "C:\Users\Марина\Downloads\catch.hpp"
#include "../kk1/TVSet.h"
#include "../kk1/TVSet.cpp"

using namespace std;

TEST_CASE("TV initially off with channel 0")
{
    cout << "Turn on the TV if it is off\n";
    TVSet tv;
    REQUIRE_FALSE(tv.IsTurnedOn());
    REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("TV turns on and starts with channel 1") {
    TVSet tv;
    tv.TurnOn();
    REQUIRE(tv.IsTurnedOn());
    REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("TV remembers channel after turning off") {
    TVSet tv;
    tv.TurnOn();
    tv.SelectChannel(5);
    tv.TurnOff();
    REQUIRE_FALSE(tv.IsTurnedOn());
    REQUIRE(tv.GetChannel() == 0);

    tv.TurnOn();
    REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("Channel selection only works when TV is on") {
    TVSet tv;
    tv.SelectChannel(10);
    REQUIRE(tv.GetChannel() == 0);

    tv.TurnOn();
    tv.SelectChannel(10);
    REQUIRE(tv.GetChannel() == 10);
}

TEST_CASE("Invalid channel numbers") {
    TVSet tv;
    tv.TurnOn();
    tv.SelectChannel(0);
    REQUIRE(tv.GetChannel() == 1);

    tv.SelectChannel(100);
    REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("Repeated TurnOn does not reset channel")
{
    TVSet tv;
    tv.TurnOn();
    tv.SelectChannel(10);
    tv.TurnOn();

    REQUIRE(tv.GetChannel() == 10);
}

TEST_CASE("Invalid SelectChannel returns false")
{
    TVSet tv;
    tv.TurnOn();

    REQUIRE_FALSE(tv.SelectChannel(0));
    REQUIRE_FALSE(tv.SelectChannel(100));
}