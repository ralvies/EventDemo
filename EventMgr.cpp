/*------------------------------------------------------------------------------
File: EventMgr.cpp

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
#include "EventMgr.hpp"
#include "Event.hpp"
#include "EventListener.hpp"

using namespace gx;

//------------------------------------------------------------------------------
// static
EventMgr& EventMgr::instance()
{
    static EventMgr obj;
    return obj;
}

//------------------------------------------------------------------------------
EventMgr::EventMgr()
{
}

//------------------------------------------------------------------------------
EventMgr::~EventMgr()
{
}

//------------------------------------------------------------------------------
void EventMgr::unsubscribeAll( EventListener &l )
{
    // Search observers
    for( EventListeners::iterator it = m_listeners.begin();
         it != m_listeners.end();
         ++it )
    {
        // Remove the observer passed in as an argument
        if( it->second == &l )
        {
            m_listeners.erase( it );
        }
    }
}

//------------------------------------------------------------------------------
void EventMgr::addListener( unsigned int id, EventListener &l )
{
    m_listeners.insert( std::pair< unsigned int, EventListener* >( id, &l ) );
}

//------------------------------------------------------------------------------
void EventMgr::removeListener( unsigned int id, EventListener &l )
{
    // Search observers with the given key
    for( EventListeners::iterator it = m_listeners.lower_bound( id );
         it != m_listeners.upper_bound( id );
         ++it )
    {
        // Remove the observer passed in as an argument
        if( it->second == &l )
        {
            m_listeners.erase( it );
        }
    }
}

//------------------------------------------------------------------------------
void EventMgr::notify( unsigned int id, void *pEvent )
{
    Event e( id, pEvent );

    for( EventListeners::iterator it = m_listeners.lower_bound( id );
         it != m_listeners.upper_bound( id );
         ++it )
    {
        EventListener &l = *(it->second);
        l.onEvent( e );
    }
}
