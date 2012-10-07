/*------------------------------------------------------------------------------
File: EventMgr.hpp

Description:
The EventMgr is the central point for subscribing to and triggering events.
Subscribers subscribe() to an event with an EventListener. When the EventMgr is
notified of an event, it calls each EventListener's onEvent() method with the
event. The event must be copied inside the onEvent() method.

Copyright 2012 Rob Alvies
--------------------------------------------------------------------------------
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
------------------------------------------------------------------------------*/
#ifndef _EventMgr_HPP_
#define _EventMgr_HPP_

#include "TypeID.hpp"
#include <map>

namespace gx {

class EventListener;

class EventMgr
{
public:
    // Singleton interface
    static EventMgr& instance();

    EventMgr();
    ~EventMgr();

    // EventMgr interface
    template< class T > inline void subscribe( EventListener &l );
    template< class T > inline void unsubscribe( EventListener &l );
    void unsubscribeAll( EventListener &l );

    template< class T > inline void notify( T &event );

private:
    void addListener( unsigned int id, EventListener &l );
    void removeListener( unsigned int id, EventListener &l );
    void notify( unsigned int id, void *pEvent );

    typedef std::multimap< unsigned int, EventListener* > EventListeners;
    EventListeners m_listeners;
};

//------------------------------------------------------------------------------
// inline
template< class T >
void EventMgr::subscribe( EventListener &l )
{
    addListener( TypeID< T >::id(), l );
}

//------------------------------------------------------------------------------
// inline
template< class T >
void EventMgr::unsubscribe( EventListener &l )
{
    removeListener( TypeID< T >::id(), l );
}

//------------------------------------------------------------------------------
// inline
template< class T >
void EventMgr::notify( T &event )
{
    notify( TypeID< T >::id(), &event );
}

} // End namespace

#endif
