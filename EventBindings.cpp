/*------------------------------------------------------------------------------
File: EventBindings.cpp

Description:
The EventBindings class manages custom binding functions used to bind events to
their callbacks in a type-safe manner. The binding functions place the bindings
into a Command object that can be manipulated independent of the event itself.

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
#include "EventBindings.hpp"
#include "Event.hpp"

using namespace gx;

//------------------------------------------------------------------------------
EventBindings::EventBindings()
{
}

//------------------------------------------------------------------------------
EventBindings::~EventBindings()
{
}

//------------------------------------------------------------------------------
void EventBindings::registerBinding( unsigned int id, Binding &binding )
{
    m_bindings[ id ] = binding;
}

//------------------------------------------------------------------------------
void EventBindings::unregisterBinding( unsigned int id )
{
    if( !hasBinding( id ) ) return;
    m_bindings.erase( id );
}

//------------------------------------------------------------------------------
bool EventBindings::hasBinding( unsigned int id ) const
{
    Bindings::const_iterator it = m_bindings.find( id );
    return it != m_bindings.end();
}

//------------------------------------------------------------------------------
Command* EventBindings::bind( Event &e )
{
    Bindings::const_iterator it = m_bindings.find( e.getID() );
    Binding b = it->second;
    return b( e );
}
