#include "TVSet.h"
#include "Constants.h"
#include <iostream>

using namespace std;

TVSet::TVSet()
    : isOn(false),
    currentChannel(OFF_CHANNEL),
    lastChannel(DEFAULT_CHANNEL)
{
}

bool TVSet::IsTurnedOn() const
{
    return isOn;
}

int TVSet::GetChannel() const
{
    return currentChannel;
}

void TVSet::TurnOn()
{
    if (!isOn)
    {
        isOn = true;
        currentChannel = lastChannel;
    }

    cout << TV_ON_MESSAGE << endl;
}

void TVSet::TurnOff()
{
    if (isOn)
    {
        lastChannel = currentChannel;
        currentChannel = OFF_CHANNEL;
        isOn = false;
    }

    cout << TV_OFF_MESSAGE << endl;
}

bool TVSet::SelectChannel(int channel)
{
    if (!isOn || channel < MIN_CHANNEL || channel > MAX_CHANNEL)
    {
        cout << ERROR_MESSAGE << endl;
        return false;
    }

    currentChannel = channel;

    cout << CHANNEL_SWITCHED_MESSAGE << channel << endl;
    return true;
}

void TVSet::Info() const
{
    if (isOn)
    {
        cout << TV_ON_MESSAGE << endl;
        cout << CHANNEL_CURRENT_MESSAGE << currentChannel << endl;
    }
    else
    {
        cout << TV_OFF_MESSAGE << endl;
    }
}