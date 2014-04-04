/*------------------------------------------------------------------------------
File: EventBindings.hpp

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
#ifndef _EventBindings_HPP_
#define _EventBindings_HPP_

#include <functional>
#include <map>

namespace gx {

class Event;
class Command;

class EventBindings
{
public:
    EventBindings();
    ~EventBindings();

    // EventBindings interface
    typedef std::function< Command* (Event&) > Binding;

    void registerBinding( unsigned int id, Binding &binding );
    void unregisterBinding( unsigned int id );

    bool hasBinding( unsigned int id ) const;
    Command* bind( Event &e );

private:
    typedef std::map< unsigned int, Binding > Bindings;
    Bindings m_bindings;
};

} // End namespace

#endif
