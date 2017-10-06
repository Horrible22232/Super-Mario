#include "stdafx.h"
#include "Observer.h"

std::vector<Event> Observer::NotificationList;
std::vector<Observer*> Observer::ObserverList;

Observer::Observer()
{
}

Observer::~Observer()
{
}

void Observer::addObserver(Observer* observer)
{
	ObserverList.push_back(observer);
}

void Observer::removeObserver(Observer* observer)
{
	for (unsigned int i = 0; i < ObserverList.size(); i++) {
		if (observer == ObserverList.at(i)) {
			ObserverList.erase(ObserverList.begin() + i);
		}
	}
}

void Observer::Notify(Event& event)
{
	NotificationList.push_back(event);
}



std::vector<Event>& Observer::getNotificationList()
{
	return NotificationList;
}

std::vector<Observer*>& Observer::getObserverList()
{
	return ObserverList;
}
