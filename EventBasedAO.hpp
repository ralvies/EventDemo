/*------------------------------------------------------------------------------
File: EventBasedAO.hpp

Description:
An EventBasedAO is a general purpose active object that provides a simple and
lightweight mechanism for subscribing to events, waiting on those events, and
then responding to those events.

An event is any arbitrary type and each type represents a unique event.

To use an EventBasedAO,
 * Create a class that inherits from EventBasedAO
 * Implement the init() method
 * In the init() method, subscribe() to various events, passing in a callback
   that takes an event as an argument

When an event is received, the callback will be executed with the event being
passed in as an argument. The event will be its own copy of the original (using
operator=) and will be destroyed after the callback has returned. Any
information in the event must be copied from the event before exiting the
callback function.

If copying an event becomes too expensive or is simply undesired, a smart
pointer containing the actual event can be used as the event rather than the
event itself. In this case, it is the responsibility of the application
developer to manage the thread safety aspects concerning access to the event.

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
#ifndef _EventBasedAO_HPP_
#define _EventBasedAO_HPP_

#include "AO.hpp"
#include "EventListener.hpp"
#include "EventBindings.hpp"
#include "CommandQueue.hpp"

#include "EventMgr.hpp"
#include "EventHandler.hpp"
#include "Event.hpp"
#include "TypeID.hpp"

#include <functional>
#include <map>

namespace gx {

class EventBasedAO: public AO, public EventListener
{
public:
    EventBasedAO();
    virtual ~EventBasedAO();

    // AO interface
    virtual void run();

    // EventBasedAO interface
    virtual void init() = 0;
    void notify( Event &e );

protected:
    // EventBasedAO interface
    template< class T >
    void subscribe( std::function< void (T&) > const &callback );

    template< class T > void unsubscribe();
    void unsubscribeAll();

private:
    // EventListener interface
    virtual void onEvent( Event &e );

    CommandQueue m_queue;
    EventBindings m_bindings;

    template< class T >
    static Command* bind( std::function< void (T&) > const &callback, Event &e );
};

//------------------------------------------------------------------------------
template< class T >
void EventBasedAO::subscribe( std::function< void (T&) > const &callback )
{
    using namespace std::placeholders;
    unsigned int const id = TypeID< T >::id();
    EventBindings::Binding b = std::bind( &bind< T >, callback, _1 );
    m_bindings.registerBinding( id, b );
    EventMgr::instance().subscribe< T >( *this );
}

//------------------------------------------------------------------------------
template< class T >
void EventBasedAO::unsubscribe()
{
    unsigned int const id = TypeID< T >::id();
    EventMgr::instance().unsubscribe< T >( *this );
    m_bindings.unregisterBinding( id );
}

//------------------------------------------------------------------------------
template< class T >
Command* EventBasedAO::bind( std::function< void (T&) > const &callback, Event &e )
{
    T *pEvent = e.event< T >();
    std::function< void () > fn = std::bind( callback, *pEvent );
    return new EventHandler( fn );
}

} // End namespace

#endif
