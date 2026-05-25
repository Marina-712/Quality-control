#pragma once

class TVSet
{
private:
    bool isOn;
    int currentChannel;
    int lastChannel;

public:
    TVSet();

    bool IsTurnedOn() const;
    int GetChannel() const;

    void TurnOn();
    void TurnOff();
    bool SelectChannel(int channel);

    void Info() const;
};