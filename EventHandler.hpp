/*------------------------------------------------------------------------------
File: EventHandler.hpp

Description:
An EventHandler wraps a callback function in a Command object to be executed in
a more robust environment using the Command Pattern.

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
#ifndef _EventHandler_HPP_
#define _EventHandler_HPP_

#include "Command.hpp"
#include <functional>

namespace gx {

class EventHandler: public Command
{
public:
    typedef std::function< void () > Fn;

    EventHandler( Fn &fn );
    ~EventHandler();

    // Command interface
    virtual void execute();

private:
    Fn m_fn;
};

} // End namespace

#endif
