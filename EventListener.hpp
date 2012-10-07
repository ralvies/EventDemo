/*------------------------------------------------------------------------------
File: EventListener.hpp

Description:
An EventListener defines the callback interface used by the EventMgr. It is the
Subject interface used in the Observer Pattern.

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
#ifndef _EventListener_HPP_
#define _EventListener_HPP_

namespace gx {

class Event;

class EventListener
{
public:
    EventListener(){}
    virtual ~EventListener(){}

    // Define EventListener interface
    virtual void onEvent( Event &e ) = 0;
};

} // End namespace

#endif
