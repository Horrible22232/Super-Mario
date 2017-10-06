#pragma once
#include <vector>
#include <game\components\observer\event\EventList.h>
#include <game\components\entity\Entity.h>
class Observer
{
public:
	Observer();
	~Observer();
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	static void Notify(Event event);
	virtual void onNotification(Event& event) = 0;
	static std::vector<Event>& getNotificationList();
	static std::vector<Observer*>& getObserverList();
private:
	static std::vector<Event> NotificationList;
	static std::vector<Observer*> ObserverList;
};

