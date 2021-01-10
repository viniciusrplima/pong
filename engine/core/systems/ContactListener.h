#include <box2d/box2d.h>

#ifndef _CONTACT_LISTENER_H_
#define _CONTACT_LISTENER_H_

class ContactListener : public b2ContactListener
{
public:
    ContactListener();
    ~ContactListener();

    void BeginContact(b2Contact *);
};

#endif