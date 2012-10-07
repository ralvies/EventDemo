/*------------------------------------------------------------------------------
File: EventBasedAO.cpp

Description:
An EventBasedAO is a general purpose active object that provides a simple and
lightweight mechanism for subscribing to events, waiting on those events, and
then responding to those events.

See the file comment block in EventBasedAO.hpp for more information.

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
#include "EventBasedAO.hpp"
#include "Command.hpp"

using namespace gx;

//------------------------------------------------------------------------------
EventBasedAO::EventBasedAO()
{
}

//------------------------------------------------------------------------------
// virtual
EventBasedAO::~EventBasedAO()
{
    unsubscribeAll();
}

//------------------------------------------------------------------------------
// virtual
void EventBasedAO::run()
{
    // Normally we would init() here, but because we aren't really running in a
    // separate thread for this demo, we have to call init() from the subclass'
    // constructor.
    // init();

    Command *pCmd = 0;

    while( m_queue.hasNext() )
    {
        pCmd = m_queue.getNext();
        pCmd->execute();
        delete pCmd;
        pCmd = 0;
    }
}

//------------------------------------------------------------------------------
void EventBasedAO::onEvent( Event &e )
{
    notify( e );
}

//------------------------------------------------------------------------------
void EventBasedAO::notify( Event &e )
{
    if( !m_bindings.hasBinding( e.getID() ) ) return;

    Command *pCmd = m_bindings.bind( e );
    m_queue.add( pCmd );
}

//------------------------------------------------------------------------------
void EventBasedAO::unsubscribeAll()
{
    EventMgr::instance().unsubscribeAll( *this );
}
